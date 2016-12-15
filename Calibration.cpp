#include "Calibration.h"

calibration::calibration()
{
	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	board_w = 18;
	board_h = 12;
	n_boards = 24;
	board_dt = 20;
	point3d.resize(board_w*board_h);
	for (int i = 0; i<point3d.size(); i++)
	{
		point3d[i].z = 0.0f;
		(float)point3d[i].x = i % board_w;
		(float)point3d[i].y = i / board_w;
	}
	fswrite1 = FileStorage("camera_paramter_640x480.xml", FileStorage::WRITE);

	if (!(video_l.isOpened() && video_r.isOpened()))
		cout << "Cannot open the video cam" << endl;

}

calibration::calibration(int n_corner_w, int n_corners_h, int n_board, int dt_board, int width, int height)
{
	board_w = n_corner_w;
	board_h = n_corners_h;
	n_boards = n_board;
	board_dt = dt_board;
	frame_width = width;
	frame_height = height;
	point3d.resize(board_w*board_h);
	for (int i = 0; i<point3d.size(); i++)
	{
		point3d[i].z = 0.0f;
		(float)point3d[i].x = i % board_w;
		(float)point3d[i].y = i / board_w;
	}
	if (width == 640 && height == 480)
		fswrite1 = FileStorage("camera_paramter_640x480.xml", FileStorage::WRITE);
	else if (width == 320 && height == 240)
		fswrite1 = FileStorage("camera_paramter.xml", FileStorage::WRITE);
	else if (width == 160 && height == 120)
		fswrite1 = FileStorage("camera_paramter_160x120.xml", FileStorage::WRITE);
	else
		cout << "ung?ltige Aufl?sung." << endl;
}

void calibration::calibrate()
{
	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, frame_width);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, frame_height);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, frame_width);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, frame_height);
	if (!(video_l.isOpened() && video_r.isOpened()))
		cout << "Cannot open the video cam" << endl;
	int successes = 0;
	int framenumber = 0;
	namedWindow("Webcaml", CV_WINDOW_AUTOSIZE);
	namedWindow("Webcamr", CV_WINDOW_AUTOSIZE);
	while (successes<n_boards)
	{
		video_l.read(frame_l);
		video_r.read(frame_r);
		if (framenumber++ % board_dt == 0 && framenumber != 0)
		{
			bool patternfoundl = findChessboardCorners(frame_l, Size(board_w, board_h), corners_l, CV_CALIB_CB_FILTER_QUADS + /*CALIB_CB_NORMALIZE_IMAGE +*/ CALIB_CB_FAST_CHECK);
			bool patternfoundr = findChessboardCorners(frame_r, Size(board_w, board_h), corners_r, CV_CALIB_CB_FILTER_QUADS + /*CALIB_CB_NORMALIZE_IMAGE +*/ CALIB_CB_FAST_CHECK);
			drawChessboardCorners(frame_l, Size(board_w, board_h), corners_l, patternfoundl);
			drawChessboardCorners(frame_r, Size(board_w, board_h), corners_r, patternfoundr);
			imshow("Webcaml", frame_l);
			imshow("Webcamr", frame_r);
			if (corners_l.size() == (board_w*board_h) && corners_r.size() == (board_w*board_h))
			{
				cornervector_l.push_back(corners_l);
				cornervector_r.push_back(corners_r);
				point3dvector.push_back(point3d);
				successes++;
				int c = cvWaitKey(1000);
			}
		}
		else
		{
			imshow("Webcaml", frame_l);
			imshow("Webcamr", frame_r);
		}
		char c = cvWaitKey(1);
		if (c == 27)break;
	}
	destroyAllWindows();
	rms_l = calibrateCamera(point3dvector, cornervector_l, Size(video_r.get(CV_CAP_PROP_FRAME_WIDTH), video_r.get(CV_CAP_PROP_FRAME_HEIGHT)),
		intrinsics_l, distortion_l, rvecs_l, tvecs_l, CV_CALIB_FIX_K3, cvTermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, 1200, 0.0001/*DBL_EPSILON*/));
	rms_r = calibrateCamera(point3dvector, cornervector_r, Size(video_r.get(CV_CAP_PROP_FRAME_WIDTH), video_r.get(CV_CAP_PROP_FRAME_HEIGHT)),
		intrinsics_r, distortion_r, rvecs_r, tvecs_r, CV_CALIB_FIX_K3, cvTermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, 1200, 0.0001/*DBL_EPSILON*/));
	/*cout << "intrinsic_l       = " << endl << format(intrinsics_l, "C") << endl << endl;
	cout << "intrinsic_r       = " << endl << format(intrinsics_r, "C") << endl << endl;
	cout << "distortion_l        = " << endl << format(distortion_l, "C") << endl << endl;
	cout << "distortion_r        = " << endl << format(distortion_r, "C") << endl << endl;
	cout << "tvecs_l      = " << endl << format(tvecs_l[0], "C") << endl << endl;
	cout << "rvecs_l      = " << endl << format(rvecs_l[0], "C") << endl << endl;*/
	double rms_stereo = stereoCalibrate(point3dvector, cornervector_l, cornervector_r, intrinsics_l, distortion_l, intrinsics_r, distortion_r,
		Size(video_r.get(CV_CAP_PROP_FRAME_WIDTH), video_r.get(CV_CAP_PROP_FRAME_HEIGHT)), R, T, E, F,
		TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 1200, 0.0001), +CV_CALIB_FIX_K3);
	Rodrigues(R, R);
	/*cout << "R       = " << endl << format(R, "C") << endl << endl;
	cout << "T        = " << endl << format(T, "C") << endl << endl;
	cout << "E       = " << endl << format(E, "C") << endl << endl;
	cout << "F        = " << endl << format(F, "C") << endl << endl;
	cout << "RMS Fehler l,r,stereo: " << rms_l << rms_r << rms_stereo << endl;*/
	stereoRectify(intrinsics_l, distortion_l, intrinsics_r, distortion_r, Size(video_r.get(CV_CAP_PROP_FRAME_WIDTH), video_r.get(CV_CAP_PROP_FRAME_HEIGHT)), R, T,
		rectify_l, rectify_r, projection_l, projection_r, Q);
}

void calibration::save_calibration_result()
{
	fswrite1 << "intrinsic_L" << intrinsics_l;
	fswrite1 << "distortion_L" << distortion_l;
	fswrite1 << "projection_L" << projection_l;
	fswrite1 << "rectify_L" << rectify_l;
	fswrite1 << "intrinsic_R" << intrinsics_r;
	fswrite1 << "distortion_R" << distortion_r;
	fswrite1 << "projection_R" << projection_r;
	fswrite1 << "rectify_R" << rectify_r;
	fswrite1 << "R" << R;
	fswrite1 << "T" << T;
	fswrite1 << "essential_matrix" << E;
	fswrite1 << "fundamental_matrix" << F;
	fswrite1 << "projection_error_left" << rms_l;
	fswrite1 << "projection_error_right" << rms_r;
	fswrite1 << "projection_error_stereo" << rms_stereo;
	fswrite1 << "Q" << Q; //needed for reprojectImageTo3D()
	fswrite1.release();
}

calibration::~calibration()
{
}