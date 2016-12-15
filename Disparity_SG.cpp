#include "Disparity_SG.h"

int disparity_SGBM::i;
Mat disparity_SGBM::kernel;
int disparity_SGBM::morph_size;
int disparity_SGBM::bila_d;
int disparity_SGBM::bila_sigmaColor;
int disparity_SGBM::bila_sigmaSpace;
StereoSGBM disparity_SGBM::sbm_SG[8];

void thread_f_1_of_4(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 10, 300, 75)), (*frame_r_rectify)(Rect(5, 10, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_2_of_4(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 55, 300, 75)), (*frame_r_rectify)(Rect(5, 55, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_3_of_4(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 110, 300, 75)), (*frame_r_rectify)(Rect(5, 110, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_4_of_4(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 155, 300, 75)), (*frame_r_rectify)(Rect(5, 155, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}

void thread_f_1_of_4_small(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 10, 300, 75)), (*frame_r_rectify)(Rect(5, 10, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_2_of_4_small(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 55, 300, 75)), (*frame_r_rectify)(Rect(5, 55, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_3_of_4_small(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 110, 300, 75)), (*frame_r_rectify)(Rect(5, 110, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_4_of_4_small(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 155, 300, 75)), (*frame_r_rectify)(Rect(5, 155, 300, 75)), *disparity_slice_roi_disparity_obenunten);
}

void thread_f_1_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 10, 300, 27 + 20)), (*frame_r_rectify)(Rect(5, 10, 300, 27 + 20)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_2_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 27, 300, 28 + 20)), (*frame_r_rectify)(Rect(5, 27, 300, 28 + 20)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_3_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 55, 300, 27 + 20)), (*frame_r_rectify)(Rect(5, 55, 300, 27 + 20)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_4_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 82, 300, 28 + 20)), (*frame_r_rectify)(Rect(5, 82, 300, 28 + 20)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_5_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 110, 300, 27 + 20)), (*frame_r_rectify)(Rect(5, 110, 300, 27 + 20)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_6_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 137, 300, 28 + 20)), (*frame_r_rectify)(Rect(5, 137, 300, 28 + 20)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_7_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 165, 300, 27 + 20)), (*frame_r_rectify)(Rect(5, 165, 300, 27 + 20)), *disparity_slice_roi_disparity_obenunten);
}
void thread_f_8_of_8(StereoSGBM *sbm_SG, Mat *frame_l_rectify, Mat *frame_r_rectify, Mat *disparity_slice_roi_disparity_obenunten)
{
	sbm_SG->operator()((*frame_l_rectify)(Rect(15, 182, 300, 28 + 20)), (*frame_r_rectify)(Rect(5, 182, 300, 28 + 20)), *disparity_slice_roi_disparity_obenunten);
}

void thread_rectify_l(VideoCapture video_l, Mat mapx_l, Mat mapy_l, Mat *frame_l, Mat *frame_l_rectify)
{
	video_l.read(*frame_l);
	remap(*frame_l, *frame_l_rectify, mapx_l, mapy_l, INTER_AREA, 0);//Undistort + rectify image
}
void thread_rectify_r(VideoCapture video_r, Mat mapx_r, Mat mapy_r, Mat *frame_r, Mat *frame_r_rectify)
{
	video_r.read(*frame_r);
	remap(*frame_r, *frame_r_rectify, mapx_r, mapy_r, INTER_AREA, 0);//Undistort + rectify image
}

disparity_SGBM::disparity_SGBM()
{
	roi_l = Rect(15, 10, 300, 220);
	roi_r = Rect(5, 10, 300, 220);
	roi_disparity = Rect(40, 0, 260, 220);

	for (int i = 0; i<8; i++)
	{
		sbm_SG[i].SADWindowSize = 3;
		sbm_SG[i].preFilterCap = 48;
		sbm_SG[i].uniquenessRatio = 0;
		sbm_SG[i].speckleWindowSize = 0;
		sbm_SG[i].speckleRange = 0;
		sbm_SG[i].minDisparity = 0;
		sbm_SG[i].numberOfDisparities = 64;
		sbm_SG[i].P1 = 800;
		sbm_SG[i].P2 = 1600;
	}
	morph_size = 3;
	kernel = getStructuringElement(MORPH_CROSS, Size(3, 3));
	bila_d = 10;
	bila_sigmaColor = 15;
	bila_sigmaSpace = 1;

	//mask = Mat::ones(240,320,CV_8U);//Bin?rmaske f?r Disparit?tskarte
	polygon_l_o[0].x = 0;
	polygon_l_o[0].y = 0;
	polygon_l_o[1].x = 95;
	polygon_l_o[1].y = 0;
	polygon_l_o[2].x = 95;
	polygon_l_o[2].y = 10;
	polygon_l_o[3].x = 45;
	polygon_l_o[3].y = 60;
	polygon_l_o[4].x = 0;
	polygon_l_o[4].y = 60;
	polygon_r_o[0].x = 96;
	polygon_r_o[0].y = 0;
	polygon_r_o[1].x = 320;
	polygon_r_o[1].y = 0;
	polygon_r_o[2].x = 320;
	polygon_r_o[2].y = 10;
	polygon_r_o[3].x = 96;
	polygon_r_o[3].y = 10;
	polygon_l_u[0].x = 0;
	polygon_l_u[0].y = 60;
	polygon_l_u[1].x = 45;
	polygon_l_u[1].y = 60;
	polygon_l_u[2].x = 45;
	polygon_l_u[2].y = 240;
	polygon_l_u[3].x = 0;
	polygon_l_u[3].y = 240;
	polygon_r_u[0].x = 310;
	polygon_r_u[0].y = 10;
	polygon_r_u[1].x = 320;
	polygon_r_u[1].y = 10;
	polygon_r_u[2].x = 320;
	polygon_r_u[2].y = 240;
	polygon_r_u[3].x = 310;
	polygon_r_u[3].y = 240;
	polygon_u[0].x = 10;
	polygon_u[0].y = 230;
	polygon_u[1].x = 310;
	polygon_u[1].y = 230;
	polygon_u[2].x = 310;
	polygon_u[2].y = 240;
	polygon_u[3].x = 10;
	polygon_u[3].y = 240;

	fillConvexPoly(mask, polygon_l_o, 5, Scalar(0));
	fillConvexPoly(mask, polygon_l_u, 4, Scalar(0));
	fillConvexPoly(mask, polygon_r_o, 4, Scalar(0));
	fillConvexPoly(mask, polygon_r_u, 4, Scalar(0));
	fillConvexPoly(mask, polygon_u, 4, Scalar(0));

	writerl = VideoWriter("C:/Users/Yu/Documents/Visual Studio 2012/Projects/webcaml.avi", CV_FOURCC('D', 'I', 'V', '3'), 5, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), true);
	writerr = VideoWriter("C:/Users/Yu/Documents/Visual Studio 2012/Projects/webcamr.avi", CV_FOURCC('D', 'I', 'V', '3'), 5, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), true);
	writer_disparity = VideoWriter("C:/Users/zhao/Documents/Visual Studio 2012/Projects/disparity.avi", CV_FOURCC('D', 'I', 'V', '3'), 5, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), false);
	fsread1 = FileStorage("camera_paramter.xml", FileStorage::READ);
}
disparity_SGBM::disparity_SGBM(int frame_width, int frame_height)
{
	if (frame_width == 320 && frame_height == 240)
	{
		roi_l = Rect(15, 10, 300, 220);
		roi_r = Rect(5, 10, 300, 220);
		roi_disparity = Rect(40, 0, 260, 220);
		fsread1 = FileStorage("camera_paramter.xml", FileStorage::READ);

	}
	else if (frame_width == 640 && frame_height == 480)
	{
		roi_l = Rect(30, 20, 600, 440);
		roi_r = Rect(10, 20, 600, 440);
		roi_disparity = Rect(80, 0, 520, 440);
		fsread1 = FileStorage("camera_paramter_640x480.xml", FileStorage::READ);
	}
	else if (frame_width == 240 && frame_height == 180)
	{
		roi_l = Rect(15, 10, 220, 160);
		roi_r = Rect(5, 10, 220, 160);
		roi_disparity = Rect(40, 0, 180, 160);
		fsread1 = FileStorage("camera_paramter_240x180.xml", FileStorage::READ);
	}
	else
		cout << "ung?ltige Aufl?sung." << endl;
	for (int i = 0; i<8; i++)
	{
		sbm_SG[i].SADWindowSize = 3;
		sbm_SG[i].preFilterCap = 48;
		sbm_SG[i].uniquenessRatio = 0;
		sbm_SG[i].speckleWindowSize = 0;
		sbm_SG[i].speckleRange = 0;
		sbm_SG[i].minDisparity = 0;
		sbm_SG[i].numberOfDisparities = 64;
		sbm_SG[i].P1 = 800;
		sbm_SG[i].P2 = 2800;
	}

	morph_size = 3;
	kernel = getStructuringElement(MORPH_CROSS, Size(3, 3));
	bila_d = 10;
	bila_sigmaColor = 15;
	bila_sigmaSpace = 1;

	mask = Mat::ones(240, 320, CV_8U);//Bin?rmaske f?r Disparit?tskarte
	polygon_l_o[0].x = 0;
	polygon_l_o[0].y = 0;
	polygon_l_o[1].x = 95;
	polygon_l_o[1].y = 0;
	polygon_l_o[2].x = 95;
	polygon_l_o[2].y = 10;
	polygon_l_o[3].x = 45;
	polygon_l_o[3].y = 60;
	polygon_l_o[4].x = 0;
	polygon_l_o[4].y = 60;
	polygon_r_o[0].x = 96;
	polygon_r_o[0].y = 0;
	polygon_r_o[1].x = 320;
	polygon_r_o[1].y = 0;
	polygon_r_o[2].x = 320;
	polygon_r_o[2].y = 10;
	polygon_r_o[3].x = 96;
	polygon_r_o[3].y = 10;
	polygon_l_u[0].x = 0;
	polygon_l_u[0].y = 60;
	polygon_l_u[1].x = 45;
	polygon_l_u[1].y = 60;
	polygon_l_u[2].x = 45;
	polygon_l_u[2].y = 240;
	polygon_l_u[3].x = 0;
	polygon_l_u[3].y = 240;
	polygon_r_u[0].x = 310;
	polygon_r_u[0].y = 10;
	polygon_r_u[1].x = 320;
	polygon_r_u[1].y = 10;
	polygon_r_u[2].x = 320;
	polygon_r_u[2].y = 240;
	polygon_r_u[3].x = 310;
	polygon_r_u[3].y = 240;
	polygon_u[0].x = 10;
	polygon_u[0].y = 230;
	polygon_u[1].x = 310;
	polygon_u[1].y = 230;
	polygon_u[2].x = 310;
	polygon_u[2].y = 240;
	polygon_u[3].x = 10;
	polygon_u[3].y = 240;

	fillConvexPoly(mask, polygon_l_o, 5, Scalar(0));
	fillConvexPoly(mask, polygon_l_u, 4, Scalar(0));
	fillConvexPoly(mask, polygon_r_o, 4, Scalar(0));
	fillConvexPoly(mask, polygon_r_u, 4, Scalar(0));
	fillConvexPoly(mask, polygon_u, 4, Scalar(0));

	writerl = VideoWriter("C:/Users/zhao/Documents/Visual Studio 2012/Projects/webcaml.avi", CV_FOURCC('D', 'I', 'V', '3'), 5, Size(frame_width, frame_height), true);
	writerr = VideoWriter("C:/Users/zhao/Documents/Visual Studio 2012/Projects/webcamr.avi", CV_FOURCC('D', 'I', 'V', '3'), 5, Size(frame_width, frame_height), true);
	writer_disparity = VideoWriter("C:/Users/zhao/Documents/Visual Studio 2012/Projects/disparity.avi", CV_FOURCC('D', 'I', 'V', '3'), 5, Size(frame_width, frame_height), false);
}
void disparity_SGBM::MyCallbackForSAD_wsize(int SAD_wsize, void* userData)
{
	if (SAD_wsize>0)
	{
		for (i = 0; i<8; i++)
			sbm_SG[i].SADWindowSize = SAD_wsize;
	}
}
void disparity_SGBM::MyCallbackForpreFilterCap(int preFilterCap, void* userData)
{
	for (i = 0; i<8; i++)
		sbm_SG[i].preFilterCap = preFilterCap;
}
void disparity_SGBM::MyCallbackForuniquenessRatio(int uniquenessRatio, void* userData)
{
	for (i = 0; i<8; i++)
		sbm_SG[i].uniquenessRatio = uniquenessRatio;
}
void disparity_SGBM::MyCallbackForspeckle_wsize(int speckle_wsize, void* userData)
{
	for (i = 0; i<8; i++)
		sbm_SG[i].speckleWindowSize = speckle_wsize;
}
void disparity_SGBM::MyCallbackForspeckleRange(int speckleRange, void* userData)
{
	for (i = 0; i<8; i++)
		sbm_SG[i].speckleRange = speckleRange;
}
void disparity_SGBM::MyCallbackForminDisparity(int minDisparity, void* userData)
{
	for (i = 0; i<8; i++)
	{
		sbm_SG[i].minDisparity = minDisparity;
		sbm_SG[i].disp12MaxDiff = sbm_SG[i].minDisparity + sbm_SG[i].numberOfDisparities;
	}
}
void disparity_SGBM::MyCallbackFornumberOfDisparities(int numDisparity, void*userData)
{
	if (numDisparity >= 16)
	{
		for (i = 0; i<8; i++)
		{
			int divisible_16 = floor(numDisparity / 16) * 16;
			sbm_SG[i].numberOfDisparities = divisible_16;
			sbm_SG[i].disp12MaxDiff = sbm_SG[i].minDisparity + sbm_SG[i].numberOfDisparities;
		}
	}
	else
	{
		for (i = 0; i<8; i++)
		{
			sbm_SG[i].numberOfDisparities = 16;
			sbm_SG[i].disp12MaxDiff = sbm_SG[i].minDisparity + sbm_SG[i].numberOfDisparities;
		}
	}
}
void disparity_SGBM::MyCallbackForP1(int p1, void* userData)
{
	for (i = 0; i<8; i++)
		sbm_SG[i].P1 = p1;
}
void disparity_SGBM::MyCallbackForP2(int p2, void* userData)
{
	for (i = 0; i<8; i++)
		sbm_SG[i].P2 = p2;
}
void disparity_SGBM::MyCallbackForMorphSize(int morph_size, void* userData)
{
	if (morph_size == 0)
		kernel = getStructuringElement(MORPH_CROSS, Size(1, 1));
	else
		kernel = getStructuringElement(MORPH_CROSS, Size(morph_size, morph_size));
}
void disparity_SGBM::MyCallbackFord(int param3, void* userData)
{
	bila_d = param3;
}
void disparity_SGBM::MyCallbackForsigmaColor(int param4, void* userData)
{
	bila_sigmaColor = param4;
}
void disparity_SGBM::MyCallbackForsigmaSpace(int param5, void* userData)
{
	bila_sigmaSpace = param5;
}

Mat disparity_SGBM::median_point(Mat *disparity_grey)
{
	//for(int row = 0; row < disparity_grey->rows; row++)
	{
		//for(int col=0; col < disparity_grey->cols; col++)
		{
			//if(disparity_grey->at<char>(row,col)>96)
			cout << (int)(disparity_grey->at<char>(120, 160)) << endl;
		}
	}
	cvtColor(*disparity_grey, disparity_C3, CV_GRAY2RGB);
	return disparity_C3;
}

void disparity_SGBM::calculate_disparity_320x240()
{
	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	fsread1["intrinsic_L"] >> intrinsics_l;
	fsread1["distortion_L"] >> distortion_l;
	fsread1["projection_L"] >> projection_l;
	fsread1["rectify_L"] >> rectify_l;
	fsread1["intrinsic_R"] >> intrinsics_r;
	fsread1["distortion_R"] >> distortion_r;
	fsread1["projection_R"] >> projection_r;
	fsread1["rectify_R"] >> rectify_r;
	fsread1.release();
	initUndistortRectifyMap(intrinsics_l, distortion_l, rectify_l, projection_l, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_l, mapy_l);
	initUndistortRectifyMap(intrinsics_r, distortion_r, rectify_r, projection_r, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_r, mapy_r);
	namedWindow("Left undist rect", WINDOW_AUTOSIZE);
	namedWindow("Right undist rect", WINDOW_AUTOSIZE);
	namedWindow("disparity", WINDOW_AUTOSIZE);
	namedWindow("sliders", WINDOW_NORMAL);
	createTrackbar("SAD_wsize", "sliders", &sbm_SG[0].SADWindowSize, 11, MyCallbackForSAD_wsize);
	createTrackbar("preFilterCap", "sliders", &sbm_SG[0].preFilterCap, 400, MyCallbackForpreFilterCap);
	createTrackbar("uniqueness", "sliders", &sbm_SG[0].uniquenessRatio, 15, MyCallbackForuniquenessRatio);
	createTrackbar("specklews", "sliders", &sbm_SG[0].speckleWindowSize, 200, MyCallbackForspeckle_wsize);
	createTrackbar("speckleRa", "sliders", &sbm_SG[0].speckleRange, 2, MyCallbackForspeckleRange);
	createTrackbar("minDispar", "sliders", &sbm_SG[0].minDisparity, 96, MyCallbackForminDisparity);
	createTrackbar("numDispar", "sliders", &sbm_SG[0].numberOfDisparities, 196, MyCallbackFornumberOfDisparities);
	createTrackbar("P1", "sliders", &sbm_SG[0].P1, 8000, MyCallbackForP1);
	createTrackbar("P2", "sliders", &sbm_SG[0].P2, 10000, MyCallbackForP2);
	createTrackbar("morph_size", "sliders", &morph_size, 19, MyCallbackForMorphSize);
	createTrackbar("d", "sliders", &bila_d, 20, MyCallbackFord);
	createTrackbar("sigmaColor", "sliders", &bila_sigmaColor, 50, MyCallbackForsigmaColor);
	createTrackbar("sigmaSpace", "sliders", &bila_sigmaSpace, 10, MyCallbackForsigmaSpace);
	counter = 0;
	time(&start);
	while (1)
	{
		video_l.read(frame_l);
		video_r.read(frame_r);
		remap(frame_l, frame_l_rectify, mapx_l, mapy_l, INTER_AREA, 0);
		remap(frame_r, frame_r_rectify, mapx_r, mapy_r, INTER_AREA, 0);
		sbm_SG[0].operator()(frame_l_rectify(roi_l), frame_r_rectify(roi_r), disparity);
		//disparity.copyTo(disparity_bila,mask); //Polygonmaske
		normalize(disparity(roi_disparity), disparity_normalized, 0, 255, CV_MINMAX, CV_8U);
		morphologyEx(disparity_normalized, disparity_bila2, MORPH_CLOSE, kernel);
		//bilateralFilter(disparity_bila2,disparity_bila3,bila_d,bila_sigmaColor,bila_sigmaSpace);
		imshow("Left undist rect", frame_l_rectify);
		imshow("Right undist rect", frame_r_rectify);
		imshow("disparity", disparity_bila2);
		//writerl.write(frame_l_rectify);
		//writerr.write(frame_r_rectify);
		//writer_disparity.write(disparity_bila3);
		c = cvWaitKey(1);
		if (c == 27)
			break;
		time(&end);
		++counter;
		sec = difftime(end, start);
		fps = counter / sec;
		cout << fps << " fps" << endl;
	}
	destroyAllWindows();
}
void disparity_SGBM::calculate_disparity_320x240_4_threads()
{
	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	Mat disparity_slices[4];
	vector<Mat> vec_disparity_slice;
	Rect roi_disparity_slice_o, roi_disparity_slice_m, roi_disparity_slice_u;

	roi_disparity_slice_o = Rect(roi_disparity.x, roi_disparity.y, roi_disparity.width, 55); //4 threads
	roi_disparity_slice_m = Rect(roi_disparity.x, roi_disparity.y + 10, roi_disparity.width, 55); //4 threads
	roi_disparity_slice_u = Rect(roi_disparity.x, roi_disparity.y + 20, roi_disparity.width, 55); //4 threads

	fsread1["intrinsic_L"] >> intrinsics_l;
	fsread1["distortion_L"] >> distortion_l;
	fsread1["projection_L"] >> projection_l;
	fsread1["rectify_L"] >> rectify_l;
	fsread1["intrinsic_R"] >> intrinsics_r;
	fsread1["distortion_R"] >> distortion_r;
	fsread1["projection_R"] >> projection_r;
	fsread1["rectify_R"] >> rectify_r;
	fsread1.release();
	initUndistortRectifyMap(intrinsics_l, distortion_l, rectify_l, projection_l, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_l, mapy_l);
	initUndistortRectifyMap(intrinsics_r, distortion_r, rectify_r, projection_r, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_r, mapy_r);
	namedWindow("Left undist rect", WINDOW_AUTOSIZE);
	namedWindow("Right undist rect", WINDOW_AUTOSIZE);
	namedWindow("disparity", WINDOW_AUTOSIZE);
	namedWindow("disparity threshold", WINDOW_AUTOSIZE);
	namedWindow("sliders", WINDOW_NORMAL);

	createTrackbar("SAD_wsize", "sliders", &sbm_SG[0].SADWindowSize, 11, MyCallbackForSAD_wsize);
	createTrackbar("preFilterCap", "sliders", &sbm_SG[0].preFilterCap, 400, MyCallbackForpreFilterCap);
	createTrackbar("uniqueness", "sliders", &sbm_SG[0].uniquenessRatio, 15, MyCallbackForuniquenessRatio);
	createTrackbar("specklews", "sliders", &sbm_SG[0].speckleWindowSize, 200, MyCallbackForspeckle_wsize);
	createTrackbar("speckleRa", "sliders", &sbm_SG[0].speckleRange, 2, MyCallbackForspeckleRange);
	createTrackbar("minDispar", "sliders", &sbm_SG[0].minDisparity, 96, MyCallbackForminDisparity);
	createTrackbar("numDispar", "sliders", &sbm_SG[0].numberOfDisparities, 196, MyCallbackFornumberOfDisparities);
	createTrackbar("P1", "sliders", &sbm_SG[0].P1, 8000, MyCallbackForP1);
	createTrackbar("P2", "sliders", &sbm_SG[0].P2, 10000, MyCallbackForP2);

	createTrackbar("morph_size", "sliders", &morph_size, 19, MyCallbackForMorphSize);
	createTrackbar("d", "sliders", &bila_d, 20, MyCallbackFord);
	createTrackbar("sigmaColor", "sliders", &bila_sigmaColor, 50, MyCallbackForsigmaColor);
	createTrackbar("sigmaSpace", "sliders", &bila_sigmaSpace, 10, MyCallbackForsigmaSpace);

	counter = 0;
	time(&start);
	while (1)
	{
		thread cam_l(thread_rectify_l, video_l, mapx_l, mapy_l, &frame_l, &frame_l_rectify), cam_r(thread_rectify_r, video_r, mapx_r, mapy_r, &frame_r, &frame_r_rectify);
		cam_l.join();
		cam_r.join();
		imshow("Left undist rect", frame_l_rectify);
		imshow("Right undist rect", frame_r_rectify);
		vec_disparity_slice.clear();
		thread thread_1_of_4(thread_f_1_of_4, &sbm_SG[0], &frame_l_rectify, &frame_r_rectify, &disparity_slices[0]),
			thread_2_of_4(thread_f_2_of_4, &sbm_SG[1], &frame_l_rectify, &frame_r_rectify, &disparity_slices[1]),
			thread_3_of_4(thread_f_3_of_4, &sbm_SG[2], &frame_l_rectify, &frame_r_rectify, &disparity_slices[2]),
			thread_4_of_4(thread_f_4_of_4, &sbm_SG[3], &frame_l_rectify, &frame_r_rectify, &disparity_slices[3]);
		thread_1_of_4.join();
		thread_2_of_4.join();
		thread_3_of_4.join();
		thread_4_of_4.join();
		vec_disparity_slice.push_back(disparity_slices[0](roi_disparity_slice_o));
		vec_disparity_slice.push_back(disparity_slices[1](roi_disparity_slice_m));
		vec_disparity_slice.push_back(disparity_slices[2](roi_disparity_slice_m));
		vec_disparity_slice.push_back(disparity_slices[3](roi_disparity_slice_u));
		vconcat(vec_disparity_slice, disparity);

		//disparity.copyTo(disparity_bila,mask); //Polygonmaske

		normalize(disparity/*(Rect(20,20,220,180))*/, disparity_normalized, 140, 255, CV_MINMAX, CV_8U);
		morphologyEx(disparity_normalized, disparity_bila2, MORPH_CLOSE, kernel);
		//bilateralFilter(disparity_bila2,disparity_bila3,bila_d,bila_sigmaColor,bila_sigmaSpace);

		//equalizeHist(disparity_bila2,disparity_C3);
		//threshold(disparity_C3, disparity_thres, 245, 255, THRESH_BINARY);

		//cout << (unsigned int)(disparity_C3.at<unsigned char>(110,130)) << endl;

		imshow("disparity", disparity_bila2);
		//imshow("disparity threshold", disparity_thres);
		//writerl.write(frame_l_rectify_SG);
		//writerr.write(frame_r_rectify_SG);
		//writer_disparity.write(disparity_bila3);
		c = cvWaitKey(1);
		if (c == 27)
			break;
		time(&end);
		++counter;
		sec = difftime(end, start);
		fps = counter / sec;
		cout << fps << " fps" << endl;
	}
	destroyAllWindows();
}
void disparity_SGBM::calculate_disparity_320x240_8_threads()
{
	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	Mat disparity_slices[8];
	vector<Mat> vec_disparity_slice;
	Rect roi_disparity_slice_o, roi_disparity_slice_m1, roi_disparity_slice_m2, roi_disparity_slice_u;

	roi_disparity_slice_o = Rect(roi_disparity.x, roi_disparity.y, roi_disparity.width, 27); //8 threads
	roi_disparity_slice_m1 = Rect(roi_disparity.x, roi_disparity.y + 10, roi_disparity.width, 27); //8 threads
	roi_disparity_slice_m2 = Rect(roi_disparity.x, roi_disparity.y + 10, roi_disparity.width, 28);
	roi_disparity_slice_u = Rect(roi_disparity.x, roi_disparity.y + 20, roi_disparity.width, 28); //8 threads

	fsread1["intrinsic_L"] >> intrinsics_l;
	fsread1["distortion_L"] >> distortion_l;
	fsread1["projection_L"] >> projection_l;
	fsread1["rectify_L"] >> rectify_l;
	fsread1["intrinsic_R"] >> intrinsics_r;
	fsread1["distortion_R"] >> distortion_r;
	fsread1["projection_R"] >> projection_r;
	fsread1["rectify_R"] >> rectify_r;
	fsread1.release();
	initUndistortRectifyMap(intrinsics_l, distortion_l, rectify_l, projection_l, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_l, mapy_l);
	initUndistortRectifyMap(intrinsics_r, distortion_r, rectify_r, projection_r, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_r, mapy_r);
	namedWindow("Left undist rect", WINDOW_AUTOSIZE);
	namedWindow("Right undist rect", WINDOW_AUTOSIZE);
	namedWindow("disparity", WINDOW_AUTOSIZE);
	namedWindow("sliders", WINDOW_NORMAL);

	createTrackbar("SAD_wsize", "sliders", &sbm_SG[0].SADWindowSize, 11, MyCallbackForSAD_wsize);
	createTrackbar("preFilterCap", "sliders", &sbm_SG[0].preFilterCap, 400, MyCallbackForpreFilterCap);
	createTrackbar("uniqueness", "sliders", &sbm_SG[0].uniquenessRatio, 15, MyCallbackForuniquenessRatio);
	createTrackbar("specklews", "sliders", &sbm_SG[0].speckleWindowSize, 200, MyCallbackForspeckle_wsize);
	createTrackbar("speckleRa", "sliders", &sbm_SG[0].speckleRange, 2, MyCallbackForspeckleRange);
	createTrackbar("minDispar", "sliders", &sbm_SG[0].minDisparity, 96, MyCallbackForminDisparity);
	createTrackbar("numDispar", "sliders", &sbm_SG[0].numberOfDisparities, 196, MyCallbackFornumberOfDisparities);
	createTrackbar("P1", "sliders", &sbm_SG[0].P1, 8000, MyCallbackForP1);
	createTrackbar("P2", "sliders", &sbm_SG[0].P2, 10000, MyCallbackForP2);

	createTrackbar("morph_size", "sliders", &morph_size, 19, MyCallbackForMorphSize);
	createTrackbar("d", "sliders", &bila_d, 20, MyCallbackFord);
	createTrackbar("sigmaColor", "sliders", &bila_sigmaColor, 50, MyCallbackForsigmaColor);
	createTrackbar("sigmaSpace", "sliders", &bila_sigmaSpace, 10, MyCallbackForsigmaSpace);

	counter = 0;
	time(&start);
	while (1)
	{
		thread cam_l(thread_rectify_l, video_l, mapx_l, mapy_l, &frame_l, &frame_l_rectify), cam_r(thread_rectify_r, video_r, mapx_r, mapy_r, &frame_r, &frame_r_rectify);
		cam_l.join();
		cam_r.join();
		imshow("Left undist rect", frame_l_rectify);
		imshow("Right undist rect", frame_r_rectify);
		vec_disparity_slice.clear();
		thread thread_1_of_8(thread_f_1_of_8, &sbm_SG[0], &frame_l_rectify, &frame_r_rectify, &disparity_slices[0]),
			thread_2_of_8(thread_f_2_of_8, &sbm_SG[1], &frame_l_rectify, &frame_r_rectify, &disparity_slices[1]),
			thread_3_of_8(thread_f_3_of_8, &sbm_SG[2], &frame_l_rectify, &frame_r_rectify, &disparity_slices[2]),
			thread_4_of_8(thread_f_4_of_8, &sbm_SG[3], &frame_l_rectify, &frame_r_rectify, &disparity_slices[3]),
			thread_5_of_8(thread_f_5_of_8, &sbm_SG[4], &frame_l_rectify, &frame_r_rectify, &disparity_slices[4]),
			thread_6_of_8(thread_f_6_of_8, &sbm_SG[5], &frame_l_rectify, &frame_r_rectify, &disparity_slices[5]),
			thread_7_of_8(thread_f_7_of_8, &sbm_SG[6], &frame_l_rectify, &frame_r_rectify, &disparity_slices[6]),
			thread_8_of_8(thread_f_8_of_8, &sbm_SG[7], &frame_l_rectify, &frame_r_rectify, &disparity_slices[7]);
		thread_1_of_8.join();
		thread_2_of_8.join();
		thread_3_of_8.join();
		thread_4_of_8.join();
		thread_5_of_8.join();
		thread_6_of_8.join();
		thread_7_of_8.join();
		thread_8_of_8.join();

		vec_disparity_slice.push_back(disparity_slices[0](roi_disparity_slice_o));
		vec_disparity_slice.push_back(disparity_slices[1](roi_disparity_slice_m2));
		vec_disparity_slice.push_back(disparity_slices[2](roi_disparity_slice_m1));
		vec_disparity_slice.push_back(disparity_slices[3](roi_disparity_slice_m2));
		vec_disparity_slice.push_back(disparity_slices[4](roi_disparity_slice_m1));
		vec_disparity_slice.push_back(disparity_slices[5](roi_disparity_slice_m2));
		vec_disparity_slice.push_back(disparity_slices[6](roi_disparity_slice_m1));
		vec_disparity_slice.push_back(disparity_slices[7](roi_disparity_slice_u));
		vconcat(vec_disparity_slice, disparity);

		//disparity.copyTo(disparity_bila,mask); //Polygonmaske

		normalize(disparity, disparity_normalized, 0, 255, CV_MINMAX, CV_8U);
		morphologyEx(disparity_normalized, disparity_bila2, MORPH_CLOSE, kernel);
		//bilateralFilter(disparity_bila2,disparity_bila3,bila_d,bila_sigmaColor,bila_sigmaSpace);

		imshow("disparity", disparity_bila2);
		//writerl.write(frame_l_rectify_SG);
		//writerr.write(frame_r_rectify_SG);
		//writer_disparity.write(disparity_bila3);
		c = cvWaitKey(1);
		if (c == 27)
			break;
		time(&end);
		++counter;
		sec = difftime(end, start);
		fps = counter / sec;
		cout << fps << " fps" << endl;
	}
	destroyAllWindows();
}
void disparity_SGBM::calculate_disparity_240x180_4_threads()
{
	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, 240);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, 180);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, 240);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, 180);
	Mat disparity_slices[4];
	vector<Mat> vec_disparity_slice;
	Rect roi_disparity_slice_o, roi_disparity_slice_m, roi_disparity_slice_u;

	roi_disparity_slice_o = Rect(roi_disparity.x, roi_disparity.y, roi_disparity.width, 55); //4 threads
	roi_disparity_slice_m = Rect(roi_disparity.x, roi_disparity.y + 10, roi_disparity.width, 55); //4 threads
	roi_disparity_slice_u = Rect(roi_disparity.x, roi_disparity.y + 20, roi_disparity.width, 55); //4 threads

	fsread1["intrinsic_L"] >> intrinsics_l;
	fsread1["distortion_L"] >> distortion_l;
	fsread1["projection_L"] >> projection_l;
	fsread1["rectify_L"] >> rectify_l;
	fsread1["intrinsic_R"] >> intrinsics_r;
	fsread1["distortion_R"] >> distortion_r;
	fsread1["projection_R"] >> projection_r;
	fsread1["rectify_R"] >> rectify_r;
	fsread1.release();
	initUndistortRectifyMap(intrinsics_l, distortion_l, rectify_l, projection_l, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_l, mapy_l);
	initUndistortRectifyMap(intrinsics_r, distortion_r, rectify_r, projection_r, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_r, mapy_r);
	namedWindow("Left undist rect", WINDOW_AUTOSIZE);
	namedWindow("Right undist rect", WINDOW_AUTOSIZE);
	namedWindow("disparity", WINDOW_AUTOSIZE);
	namedWindow("sliders", WINDOW_NORMAL);

	createTrackbar("SAD_wsize", "sliders", &sbm_SG[0].SADWindowSize, 11, MyCallbackForSAD_wsize);
	createTrackbar("preFilterCap", "sliders", &sbm_SG[0].preFilterCap, 400, MyCallbackForpreFilterCap);
	createTrackbar("uniqueness", "sliders", &sbm_SG[0].uniquenessRatio, 15, MyCallbackForuniquenessRatio);
	createTrackbar("specklews", "sliders", &sbm_SG[0].speckleWindowSize, 200, MyCallbackForspeckle_wsize);
	createTrackbar("speckleRa", "sliders", &sbm_SG[0].speckleRange, 2, MyCallbackForspeckleRange);
	createTrackbar("minDispar", "sliders", &sbm_SG[0].minDisparity, 96, MyCallbackForminDisparity);
	createTrackbar("numDispar", "sliders", &sbm_SG[0].numberOfDisparities, 196, MyCallbackFornumberOfDisparities);
	createTrackbar("P1", "sliders", &sbm_SG[0].P1, 8000, MyCallbackForP1);
	createTrackbar("P2", "sliders", &sbm_SG[0].P2, 10000, MyCallbackForP2);

	createTrackbar("morph_size", "sliders", &morph_size, 19, MyCallbackForMorphSize);
	createTrackbar("d", "sliders", &bila_d, 20, MyCallbackFord);
	createTrackbar("sigmaColor", "sliders", &bila_sigmaColor, 50, MyCallbackForsigmaColor);
	createTrackbar("sigmaSpace", "sliders", &bila_sigmaSpace, 10, MyCallbackForsigmaSpace);

	counter = 0;
	time(&start);
	while (1)
	{
		thread cam_l(thread_rectify_l, video_l, mapx_l, mapy_l, &frame_l, &frame_l_rectify), cam_r(thread_rectify_r, video_r, mapx_r, mapy_r, &frame_r, &frame_r_rectify);
		cam_l.join();
		cam_r.join();
		imshow("Left undist rect", frame_l_rectify);
		imshow("Right undist rect", frame_r_rectify);
		vec_disparity_slice.clear();
		thread thread_1_of_4(thread_f_1_of_4_small, &sbm_SG[0], &frame_l_rectify, &frame_r_rectify, &disparity_slices[0]),
			thread_2_of_4(thread_f_2_of_4_small, &sbm_SG[1], &frame_l_rectify, &frame_r_rectify, &disparity_slices[1]),
			thread_3_of_4(thread_f_3_of_4_small, &sbm_SG[2], &frame_l_rectify, &frame_r_rectify, &disparity_slices[2]),
			thread_4_of_4(thread_f_4_of_4_small, &sbm_SG[3], &frame_l_rectify, &frame_r_rectify, &disparity_slices[3]);
		thread_1_of_4.join();
		thread_2_of_4.join();
		thread_3_of_4.join();
		thread_4_of_4.join();
		vec_disparity_slice.push_back(disparity_slices[0](roi_disparity_slice_o));
		vec_disparity_slice.push_back(disparity_slices[1](roi_disparity_slice_m));
		vec_disparity_slice.push_back(disparity_slices[2](roi_disparity_slice_m));
		vec_disparity_slice.push_back(disparity_slices[3](roi_disparity_slice_u));
		vconcat(vec_disparity_slice, disparity);

		normalize(disparity, disparity_normalized, 0, 255, CV_MINMAX, CV_8U);
		morphologyEx(disparity_normalized, disparity_bila2, MORPH_CLOSE, kernel);
		//bilateralFilter(disparity_bila2,disparity_bila3,bila_d,bila_sigmaColor,bila_sigmaSpace);

		imshow("disparity", disparity_bila2);
		//writerl.write(frame_l_rectify_SG);
		//writerr.write(frame_r_rectify_SG);
		//writer_disparity.write(disparity_bila3);
		c = cvWaitKey(1);
		if (c == 27)
			break;
		time(&end);
		++counter;
		sec = difftime(end, start);
		fps = counter / sec;
		//cout << fps << " fps" << endl;
	}
	destroyAllWindows();
}
void disparity_SGBM::calculate_disparity_320x240_gpu_BP_GPU()
{
	GpuMat frame_l_gpu, frame_r_gpu, disparity_gpu;
	setDevice(0);
	DeviceInfo dev;
	cout << dev.isCompatible() << endl;
	StereoConstantSpaceBP bp(128, 4, 4, 5);

	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	fsread1["intrinsic_L"] >> intrinsics_l;
	fsread1["distortion_L"] >> distortion_l;
	fsread1["projection_L"] >> projection_l;
	fsread1["rectify_L"] >> rectify_l;
	fsread1["intrinsic_R"] >> intrinsics_r;
	fsread1["distortion_R"] >> distortion_r;
	fsread1["projection_R"] >> projection_r;
	fsread1["rectify_R"] >> rectify_r;
	fsread1.release();
	initUndistortRectifyMap(intrinsics_l, distortion_l, rectify_l, projection_l, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_l, mapy_l);
	initUndistortRectifyMap(intrinsics_r, distortion_r, rectify_r, projection_r, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_r, mapy_r);
	namedWindow("Left undist rect", WINDOW_AUTOSIZE);
	namedWindow("Right undist rect", WINDOW_AUTOSIZE);
	namedWindow("disparity", WINDOW_AUTOSIZE);

	counter = 0;
	time(&start);
	while (1)
	{
		thread cam_l(thread_rectify_l, video_l, mapx_l, mapy_l, &frame_l, &frame_l_rectify), cam_r(thread_rectify_r, video_r, mapx_r, mapy_r, &frame_r, &frame_r_rectify);
		cam_l.join();
		cam_r.join();
		frame_l_gpu.upload(frame_l_rectify);
		frame_r_gpu.upload(frame_r_rectify);
		bp.operator()(frame_l_gpu, frame_r_gpu, disparity_gpu);
		disparity_gpu.download(disparity);
		normalize(disparity(roi_disparity), disparity_normalized, 0, 255, CV_MINMAX, CV_8U);
		morphologyEx(disparity_normalized, disparity_bila2, MORPH_CLOSE, kernel);
		imshow("Left undist rect", frame_l_rectify);
		imshow("Right undist rect", frame_r_rectify);
		imshow("disparity", disparity_bila2);
		c = cvWaitKey(1);
		if (c == 27)
			break;
		time(&end);
		++counter;
		sec = difftime(end, start);
		fps = counter / sec;
		cout << fps << " fps" << endl;
	}
	destroyAllWindows();
}
void disparity_SGBM::calculate_disparity_640x480_gpu_BP_GPU()
{
	GpuMat frame_l_gpu, frame_r_gpu, disparity_gpu;
	Mat frame_l_grey, frame_r_grey;
	setDevice(1);
	DeviceInfo dev;
	cout << dev.isCompatible() << endl;
	StereoConstantSpaceBP bp(192, 6, 6, 5);

	video_r.open(0);
	video_l.open(2);
	video_l.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	video_l.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	video_r.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	video_r.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	fsread1["intrinsic_L"] >> intrinsics_l;
	fsread1["distortion_L"] >> distortion_l;
	fsread1["projection_L"] >> projection_l;
	fsread1["rectify_L"] >> rectify_l;
	fsread1["intrinsic_R"] >> intrinsics_r;
	fsread1["distortion_R"] >> distortion_r;
	fsread1["projection_R"] >> projection_r;
	fsread1["rectify_R"] >> rectify_r;
	fsread1.release();
	initUndistortRectifyMap(intrinsics_l, distortion_l, rectify_l, projection_l, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_l, mapy_l);
	initUndistortRectifyMap(intrinsics_r, distortion_r, rectify_r, projection_r, Size(video_l.get(CV_CAP_PROP_FRAME_WIDTH), video_l.get(CV_CAP_PROP_FRAME_HEIGHT)), 0, mapx_r, mapy_r);
	namedWindow("Left undist rect", WINDOW_AUTOSIZE);
	namedWindow("Right undist rect", WINDOW_AUTOSIZE);
	namedWindow("disparity", WINDOW_AUTOSIZE);

	counter = 0;
	time(&start);
	while (1)
	{
		thread cam_l(thread_rectify_l, video_l, mapx_l, mapy_l, &frame_l, &frame_l_rectify), cam_r(thread_rectify_r, video_r, mapx_r, mapy_r, &frame_r, &frame_r_rectify);
		cam_l.join();
		cam_r.join();
		frame_l_gpu.upload(frame_l_rectify);
		frame_r_gpu.upload(frame_r_rectify);
		bp.operator()(frame_l_gpu, frame_r_gpu, disparity_gpu);
		disparity_gpu.download(disparity);
		normalize(disparity(roi_disparity), disparity_normalized, 0, 255, CV_MINMAX, CV_8U);
		//morphologyEx(disparity_normalized,disparity_bila2,MORPH_CLOSE,kernel);
		imshow("Left undist rect", frame_l_rectify);
		imshow("Right undist rect", frame_r_rectify);
		imshow("disparity", disparity_normalized);
		c = cvWaitKey(1);
		if (c == 27)
			break;
		time(&end);
		++counter;
		sec = difftime(end, start);
		fps = counter / sec;
		cout << fps << " fps" << endl;
	}
	destroyAllWindows();
}

disparity_SGBM::~disparity_SGBM()
{
}