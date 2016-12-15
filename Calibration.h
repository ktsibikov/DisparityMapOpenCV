#pragma once
#include <iostream>
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class calibration
{
public:
	calibration();
	calibration(int n_corner_w, int n_corners_h, int n_board, int dt_board, int frame_width, int frame_height);
	void calibrate();
	void save_calibration_result();
	~calibration();

private:
	VideoCapture video_l, video_r;
	int board_w, board_h, n_boards, board_dt, frame_width, frame_height;
	vector<vector<Point2f>> cornervector_l, cornervector_r;
	vector<vector<Point3f>> point3dvector;
	vector<Point2f> corners_l, corners_r;
	vector<Point3f> point3d;
	vector<Mat> rvecs_l, tvecs_l, rvecs_r, tvecs_r;
	Mat frame_l, frame_r, intrinsics_l, intrinsics_r, distortion_l, distortion_r, R, T, E, F,
		rectify_l, rectify_r, projection_l, projection_r, Q;
	double rms_stereo, rms_r, rms_l;
	FileStorage fswrite1;
};