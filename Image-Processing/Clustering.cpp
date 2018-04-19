#include "imge_bmp.h"
#include "MyVector.h"
#include "Clustering.h"
#include <math.h>

using namespace std;

Clustering::Clustering(BYTE* img, int width, int height) {
	this->img = img;
	this->width = width;
	this->height = height;

	// Eþik deðerlerini rastgele ata
	mean1.setPoints(255, 0, 0);
	mean2.setPoints(0, 255, 0);
	mean3.setPoints(0, 0, 255);

	// Sonucun tutulacaðý bufferý oluþtur
	buffer = new BYTE[width * height * 3];
}

Clustering::~Clustering() {}

void Clustering::makeClustering() {

	// Yeni eþik deðerlerini baþlat
	MyVector mean1NEW(0, 0, 0);
	MyVector mean2NEW(0, 0, 0);
	MyVector mean3NEW(0, 0, 0);
	MyVector V(0, 0, 0);
	int k = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;

	while (true) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {

				// Her bir RGB piksel üzerinde iterasyon yap 
				// Her bir piksel deðerini RGB uzayýný temsil eden bir vektöre koy
				int pos = (i*width + j) * 3;
				V.setPoints(img[pos], img[pos + 1], img[pos + 2]);

				// Piksel vektörünün kümelere uzaklýðýný hesapla 
				int d1 = mean1.getED(V);
				int d2 = mean2.getED(V);
				int d3 = mean3.getED(V);
				int min = findMin(d1, d2, d3);

				// En yakýn olan kümeye ekle
				if (min == d1) {

					mean1NEW + V;
					counter1++;
				}

				else if (min == d2) {

					mean2NEW + V;
					counter2++;
				}

				else if (min == d3) {

					mean3NEW + V;
					counter3++;
				}
			}
		}
		k++;
		mean1NEW.findMean(counter1);
		mean2NEW.findMean(counter2);
		mean3NEW.findMean(counter3);

		if (mean1.getED(mean1NEW) / 3 > 50 && mean2.getED(mean2NEW) / 3 > 50 &&
			mean3.getED(mean3NEW) / 3 > 50) {

			mean1 = mean1NEW;
			mean2 = mean2NEW;
			mean3 = mean3NEW;
		}
		else {
			break;
		}
	}
	assignRGB();
}

int Clustering::findMin(int d1, int d2, int d3) {

	int min;
	if (d1 > d2)
		min = d2;
	else
		min = d1;

	if (min > d3)
		min = d3;

	return min;
}

BYTE* Clustering::getIMG() {
	return buffer;
}

// Belirlenen küme merkezlerine yakýnlýða göre renklendir
void Clustering::assignRGB() {

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			BYTE R = img[(i*width + j) * 3];
			BYTE G = img[(i*width + j) * 3 + 1];
			BYTE B = img[(i*width + j) * 3 + 2];

			MyVector V1(R, G, B);
			int d1 = mean1.getED(V1);
			int d2 = mean2.getED(V1);
			int d3 = mean3.getED(V1);
			int min = findMin(d1, d2, d3);

			if (min == d1) {
				buffer[(i*width + j) * 3] = 0;
				buffer[(i*width + j) * 3 + 1] = 153;
				buffer[(i*width + j) * 3 + 2] = 0;
			}

			else if (min == d2) {
				buffer[(i*width + j) * 3] = 0;
				buffer[(i*width + j) * 3 + 1] = 255;
				buffer[(i*width + j) * 3 + 2] = 255;
			}

			else if (min == d3) {
				buffer[(i*width + j) * 3] = 127;
				buffer[(i*width + j) * 3 + 1] = 0;
				buffer[(i*width + j) * 3 + 2] = 255;
			}

		}
	}

}