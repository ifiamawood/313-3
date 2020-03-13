// 313 3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<opencv.hpp>

using namespace cv;
using std::string;

string window_name = "binaryMat";

void threshod_Mat(int th, void*data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	threshold(src, dst, th, 255, 0);
	imshow(window_name, dst);
}
int main()
{
	Mat srcMat, gryMat;
	int low = 30, max = 255;
	srcMat = imread("D:\\1.jpg");
	if (!srcMat.data) {
		std::cout << "ͼ������ʧ��" << std::endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshold",
		window_name,
		&low,
		max,
		threshod_Mat,
		&gryMat);
	waitKey(0);
	return 0;
}

