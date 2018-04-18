// Clustering iþleminde kullanmak için oluþturulan vektör sýnýfý
// Her bir pikselin RGB uzayýndaki deðerlerini temsil eden bir vektör oluþturur

#include "MyVector.h"
#include "imge_bmp.h"
#include <math.h>


MyVector::MyVector() {};

MyVector::MyVector(int R, int G, int B) {

	this->R = R;
	this->G = G;
	this->B = B;
}

void MyVector::setPoints(int R, int G, int B) {
	this->R = R;
	this->G = G;
	this->B = B;
}

int MyVector::getED(MyVector other) {
	return sqrt(pow((R - other.R), 2) +
		pow((G - other.G), 2) + pow((B - other.B), 2));
}

int MyVector::getR() {
	return R;
}

int MyVector::getG() {
	return G;
}

int MyVector::getB() {
	return B;
}

void MyVector::operator + (MyVector& other) {
	R = R + other.getR();
	G = G + other.getG();
	B = B + other.getB();
}

void MyVector::findMean(int num) {
	R = R / num;
	G = G / num;
	B = B / num;
}

bool MyVector::operator != (MyVector other) {
	return (R != other.R && G != other.G && B != other.B);
}
