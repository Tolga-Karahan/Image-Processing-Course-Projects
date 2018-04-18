#ifndef MyVector_h
#define MyVector_h

#include "imge_bmp.h"

class MyVector {

	int R;
	int G;
	int B;
public:
	MyVector();
	MyVector(int, int, int);
	void setPoints(int, int, int);
	int getED(MyVector other);
	int getR();
	int getG();
	int getB();
	void operator + (MyVector&);
	bool operator != (MyVector);
	void findMean(int);
};

#endif MyVector_h