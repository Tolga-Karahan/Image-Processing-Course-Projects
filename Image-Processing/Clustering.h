#ifndef Clustering_h
#define Clustering_h

#include "imge_bmp.h"
#include "MyVector.h"


class Clustering {

	BYTE* img;
	BYTE* buffer;
	int width;
	int height;

	MyVector mean1;
	MyVector mean2;
	MyVector mean3;

public:
	Clustering(BYTE*, int, int);
	~Clustering();
	void makeClustering();
	int findMin(int, int, int);
	BYTE* getIMG();
	void assignRGB();
};

#endif