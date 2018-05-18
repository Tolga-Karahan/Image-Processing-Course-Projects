#pragma once
#ifndef Segmentation_H
#define Segmentation_H

#include "imge_bmp.h"

class Segmentation {

	BYTE* img;
	BYTE* buffer;
	int width;
	int height;
	int* histogram;
	bool isEuclidean;

public:
	Segmentation(BYTE* img, int width, int height, bool isEuclidean);
	~Segmentation();
	int getThreshold();
	BYTE* KThresholding(int);
	int findMin(int*, int);
	BYTE* doSegmentation();
	int getSD(int distance[], int threshold, int label);
	int getMD(int sd, int threshold, int value);
	int getEuclidean(int threshold, int value);
};
#endif