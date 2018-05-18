#include "Segmentation.h"
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

Segmentation::Segmentation(BYTE* img, int width, int height, bool isEuclidean) {

	this->img = img;
	this->width = width;
	this->height = height;
	this->isEuclidean = isEuclidean;

	histogram = new int[256];
	for (int j = 0; j < 256; j++)
		histogram[j] = 0;

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			histogram[img[width*i + j]]++;

	buffer = new BYTE[width * height];
}

Segmentation::~Segmentation() {
	delete[] histogram;
}



int Segmentation::getThreshold() {

	int distance[256] = { 0 };
	int t1 = 10;
	int t2 = 200;
	int t1O = 0;
	int t2O = 0;
	int threshold = 0;
	int meanT1 = 1000;
	int meanT2 = 2000;
	double sd1 = 1;
	double sd2 = 1;


	while (t1 != t1O && t2 != t2O) {

		int weighT1 = 0;
		int weighT2 = 0;
		meanT1 = 0;
		meanT2 = 0;


		if (isEuclidean)
		{
			for (int i = 0; i < 256; i++) {
				if (abs(t1 - i) < abs(t2 - i))
					distance[i] = 1;
				if (abs(t1 - i) >= abs(t2 - i))
					distance[i] = 2;
			}
		}
		else
		{
			for (int i = 0; i < 256; i++) {
				if (getMD(sd1, histogram[t1], histogram[i]) < getMD(sd2, histogram[t2], histogram[i]))
					distance[i] = 1;
				else
					distance[i] = 2;
			}
		}

		for (int j = 0; j < 256; j++) {
			if (distance[j] == 1) {
				meanT1 += histogram[j] * j;
				weighT1 += histogram[j];
			}
			if (distance[j] == 2) {
				meanT2 += histogram[j] * j;
				weighT2 += histogram[j];
			}
		}

		meanT1 = round(1.0 * meanT1 / weighT1);
		meanT2 = round(1.0 * meanT2 / weighT2);

		if (meanT1 != t1O && meanT2 != t2O) {
			t1O = t1;
			t1 = meanT1;
			t2O = t2;
			t2 = meanT2;
		}
		else {
			t1 = meanT1;
			t2 = meanT2;
			break;
		}


	}

	threshold = (t1 + t2) / 2;
	return threshold;
}

BYTE* Segmentation::KThresholding(int numberOfThresholds)
{
	int	 distances[256] = { 0 }; // etiketleri tutan dizi
	int* thresholds = new int[numberOfThresholds]; // esikleri tutan dizi
	int* means = new int[numberOfThresholds]; // aðýrlýklý ortalamalarý tutan dizi
	int* weights = new int[numberOfThresholds]; // aðýrlýklarý tutan dizi
	int* distancesToThresholds = new int[numberOfThresholds]; // esik degelerine uzaklýklarý tutan dizi
	int min = 0;
	int threshold = 0;
	boolean keepIterate = true;

	// dizileri baþlat
	/*for (int i = 0; i < numberOfThresholds; i++)
	{
		thresholds[i] = i * (255 / (numberOfThresholds - 1));
		int a = thresholds[i];
	}*/

	std::fill(means, means + sizeof(means), 0);
	std::fill(weights, weights + sizeof(weights), 0);

	while (keepIterate) {

		// pikselin en yakýn olduðu eþik deðerinin indisini bul
		// en yakýn olduðu eþik deðerine göre etiketle
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < numberOfThresholds; j++)
			{
				distancesToThresholds[j] = abs(thresholds[j] - i);
			}
			min = findMin(distancesToThresholds, numberOfThresholds);
			distances[i] = min;
		}

		// aðýrlýk ve ortalama deðerleri bul
		for (int i = 0; i < 256; i++) {
			means[distances[i]] += i * histogram[i];
			weights[distances[i]] += histogram[i];
		}

		// aðýrlýklý ortalamalarý hesapla
		for (int i = 0; i < numberOfThresholds; i++)
			means[i] = round((1.0 * means[i]) / weights[i]);

		// bulunan degerler eski degelerle uyusuyor mu?
		// hepsi uyusuyorsa iterasyonu sonlandýr
		for (int i = 0; i < numberOfThresholds; i++)
		{
			if (abs(thresholds[i] - means[i]) > 10)
				break;
			else if (i == numberOfThresholds)
				keepIterate = false;
		}

		// eski degeleri bulunan yeni degerlerle guncelle
		// zaten yeni degerler ile uyusuyorsa degisiklik olmaz
		for(int i = 0; i < numberOfThresholds; i++)
				thresholds[i] = means[i];
	}

	// esik degerlerinin ortalamasýyla sonuc esik degerini bul
	for (int i = 0; i < numberOfThresholds; i++)
		threshold += thresholds[i];
	threshold = round((1.0 * threshold) / numberOfThresholds);

	// esik degerine gore segmentasyon yap
	for (int i = 0; i<width; i++)
		for (int j = 0; j < height; j++) {
			if (img[width*i + j] < threshold)
				buffer[width*i + j] = 0;
			else
				buffer[width*i + j] = 255;
		}
	return buffer;
}

int Segmentation::findMin(int* distancesToThresholds, int size)
{
	int min = 0;

	for (int i = 1; i < size; i++)
	{
		if (distancesToThresholds[i] < distancesToThresholds[min])
			min = i;
	}

	return min;
}

BYTE* Segmentation::doSegmentation() {

	int threshold;
	threshold = getThreshold();

	for (int i = 0; i<width; i++)
		for (int j = 0; j < height; j++) {
			if (img[width*i + j] < threshold)
				buffer[width*i + j] = 0;
			else
				buffer[width*i + j] = 255;
		}

	return buffer;
}

int Segmentation::getSD(int distance[], int threshold, int label) {

	double sd = 0;
	int num = 0;
	for (int i = 0; i < 256; i++)
		if (distance[i] == label) {
			sd += pow((histogram[threshold] - histogram[i]), 2);
			num++;
		}
	return sd / num;
}

int Segmentation::getMD(int sd, int threshold, int value) {

	return sqrt(pow((value - threshold), 2) / sd);
}

int Segmentation::getEuclidean(int threshold, int value) {

	return (threshold - value);
}

