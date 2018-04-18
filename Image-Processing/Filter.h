#ifndef Filter_h
#define Filter_h
#include <windows.h>

class Filter
{
	BYTE* img;
	int width;
	int height;

	public:
		Filter(BYTE*, int, int);
		~Filter();
		BYTE* filtering(BYTE mask[]);
		BYTE* dilation(BYTE mask[]);
		BYTE* erosion(BYTE mask[]);
		void updateIMG(BYTE*);
};
#endif