#pragma once
#include "opencv2/gpu/gpu.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <iostream>
#include <thread>
#include <time.h>

using namespace std;
using namespace cv;
using namespace gpu;

class disparity_SGBM
{
public:
	disparity_SGBM();
	disparity_SGBM(int frame_width, int frame_height);
	void calculate_disparity_320x240();
	void calculate_disparity_320x240_4_threads();
	void calculate_disparity_320x240_8_threads();
	void calculate_disparity_240x180_4_threads();
	void calculate_disparity_320x240_gpu_BP_GPU();
	void calculate_disparity_640x480_gpu_BP_GPU();

	Mat median_point(Mat *disparity);

	static void MyCallbackForSAD_wsize(int SAD_wsize, void* userData);
	static void MyCallbackForpreFilterCap(int preFilterCap, void* userData);
	static void MyCallbackForuniquenessRatio(int uniquenessRatio, void* userData);
	static void MyCallbackForspeckle_wsize(int speckle_wsize, void* userData);
	static void MyCallbackForspeckleRange(int speckleRange, void* userData);
	static void MyCallbackForminDisparity(int minDisparity, void* userData);
	static void MyCallbackFornumberOfDisparities(int numDisparity, void*userData);
	static void MyCallbackForP1(int p1, void* userData);
	static void MyCallbackForP2(int p2, void* userData);
	static void MyCallbackForMorphSize(int morph_size, void* userData);
	static void MyCallbackFord(int param3, void* userData);
	static void MyCallbackForsigmaColor(int param4, void* userData);
	static void MyCallbackForsigmaSpace(int param5, void* userData);

	~disparity_SGBM();

private:
	VideoCapture video_l, video_r;
	VideoWriter writerl;
	VideoWriter writerr;
	VideoWriter writer_disparity;
	FileStorage fsread1;

	char c;
	Mat intrinsics_l, intrinsics_r, distortion_l, distortion_r, rectify_l, rectify_r, projection_l, projection_r,
		frame_l, frame_r, frame_l_rectify, frame_r_rectify, mapx_l, mapy_l, mapx_r, mapy_r,
		disparity, disparity_normalized, disparity_bila, disparity_bila2, disparity_bila3, disparity_bila4, disparity_C3, disparity_thres;
	Mat mask;

	Rect roi_l, roi_r, roi_disparity;

	Point polygon_l_o[5];
	Point polygon_r_o[4];
	Point polygon_l_u[4];
	Point polygon_r_u[4];
	Point polygon_u[4];

	static int i;
	static Mat kernel;
	static int morph_size;
	static int bila_d;
	static int bila_sigmaColor;
	static int bila_sigmaSpace;
	static StereoSGBM sbm_SG[8];

	time_t start, end;
	double fps;
	int counter;
	double sec;

	vector<int> xs;
	vector<int> ys;
};