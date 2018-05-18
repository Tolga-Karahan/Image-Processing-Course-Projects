#include "Filter.h"
#include <iostream>
using namespace std;


Filter::Filter(BYTE* img, int width, int height)
{
	this->img = img;
	this->width = width;
	this->height = height;
}

Filter::~Filter()
{

}

void Filter::updateIMG(BYTE* img)
{
	this->img = img;
}

BYTE* Filter::filtering(BYTE mask[])
{
	BYTE* buffer = new BYTE[width * height];

	for (int row = 1; row < (height - 1); row++)
	{
		for (int column = 1; column < (width - 1); column++)
		{
			int result = 0;
			// resmin mask matrisine denk gelen ilk indisi
			int firstIndex = (row * width + column) - width - 1;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					result += img[firstIndex] * mask[(i * 3) + j];
					firstIndex++;
				}
				// bir sonraki satýrýn ilk indisini al
				firstIndex += width - 3;
			}
			// Sonucu merkez piksele koy
			buffer[(row * width) + column] = result;
		}
	}

	return buffer;
}

BYTE* Filter::filtering(double mask[])
{
	BYTE* buffer = new BYTE[width * height];

	for (int row = 1; row < (height - 1); row++)
	{
		for (int column = 1; column < (width - 1); column++)
		{
			double result = 0;
			// resmin mask matrisine denk gelen ilk indisi
			int firstIndex = (row * width + column) - width - 1;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					result += img[firstIndex] * mask[(i * 3) + j];
					firstIndex++;
				}
				// bir sonraki satýrýn ilk indisini al
				firstIndex += width - 3;
			}
			// Sonucu merkez piksele koy
			buffer[(row * width) + column] = round(result);
		}
	}

	return buffer;
}

BYTE* Filter::dilation(BYTE mask[])
{
	BYTE* buffer = new BYTE[width * height];


	for (int row = 1; row < (height - 1); row++)
	{
		for (int column = 1; column < (width - 1); column++)
		{
			BYTE result = 1;
			// resmin mask matrisine denk gelen ilk indisi
			int firstIndex = (row * width + column) - width - 1;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					result = img[firstIndex] * mask[(i * 3) + j];
					firstIndex++;
					if (result == 0)
						break;
				}
				// Tek bir sonuç 0 ise döngüden çýk
				if (result == 0)
					break;
				// bir sonraki satýrýn ilk indisini al
				firstIndex += width - 3;
			}
			// Sonucu merkez piksele koy
			if (result == 0)
				buffer[(row * width) + column] = 0;
			else
				buffer[(row * width) + column] = 255;
		}
	}
	return buffer;
}

BYTE* Filter::erosion(BYTE mask[])
{
	BYTE* buffer = new BYTE[width * height];


	for (int row = 1; row < (height - 1); row++)
	{
		for (int column = 1; column < (width - 1); column++)
		{
			BYTE result = 1;
			// resmin mask matrisine denk gelen ilk indisi
			int firstIndex = (row * width + column) - width - 1;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					result = img[firstIndex] * mask[(i * 3) + j];
					firstIndex++;
					if (result == 255)
						break;
				}
				// Tek bir sonuç 0 ise döngüden çýk
				if (result == 255)
					break;
				// bir sonraki satýrýn ilk indisini al
				firstIndex += width - 3;
			}
			// Sonucu merkez piksele koy
			if (result == 255)
				buffer[(row * width) + column] = 255;
			else
				buffer[(row * width) + column] = 0;
		}
	}

	return buffer;
}