#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

string slash = "/";
string bslash = "\\";
string vline = "|";
string space = " ";
string underline = "_";
string fir;

void EmptySlashLayer(int sizeX, int maxSizeX) {
	string sp = "";
	if (maxSizeX - sizeX > 0) for (int i = 0; i < maxSizeX / 2 - sizeX / 2; i++) sp += space;
	sizeX = sizeX / 2 - 1;
	string l;
	l += slash;
	for (int i = 0; i < sizeX; i++) l += space;
	string r;
	for (int i = 0; i < sizeX; i++) r += space;
	r += bslash;
	fir += sp + l + r + sp + "\n";
}

void DownSlashLayer(int sizeX, int maxSizeX, int holeSize) {
	holeSize /= 2;
	string sp = "";
	if (maxSizeX - sizeX > 0) for (int i = 0; i < maxSizeX / 2 - sizeX / 2; i++) sp += space;
	sizeX = sizeX / 2 - 1;
	string l;
	l += slash;
	for (int i = 0; i < sizeX; i++) l += i < sizeX - holeSize ? underline : space;
	string r;
	for (int i = 0; i < sizeX; i++) r += !(i < sizeX - (sizeX - holeSize)) ? underline : space;
	r += bslash;
	fir += sp + l + r + sp + "\n";
}

void TriangleEmpty(int sizeX, int holeSizeUp, int holeSizeDown, int maxSizeX) {
	for (int i = 2 + holeSizeUp; i < sizeX; i += 2) {
		EmptySlashLayer(i, maxSizeX);
	}
	DownSlashLayer(sizeX, maxSizeX, holeSizeDown);
}

void EmptyVerticalLineLayer(int sizeX, int maxSizeX) {
	string sp = "";
	if (maxSizeX - sizeX > 0) for (int i = 0; i < maxSizeX / 2 - sizeX / 2; i++) sp += space;
	sizeX = sizeX / 2 - 1;
	string l;
	l += vline;
	for (int i = 0; i < sizeX; i++) l += space;
	string r;
	for (int i = 0; i < sizeX; i++) r += space;
	r += vline;
	fir += sp + l + r + sp + "\n";;
}

void DownVerticalLineLayer(int sizeX, int maxSizeX) {
	string sp = "";
	if (maxSizeX - sizeX > 0) for (int i = 0; i < maxSizeX / 2 - sizeX / 2; i++) sp += space;
	sizeX = sizeX / 2 - 1;
	string l;
	l += vline;
	for (int i = 0; i < sizeX; i++) l += underline;
	string r;
	for (int i = 0; i < sizeX; i++) r += underline;
	r += vline;
	fir += sp + l + r + sp + "\n";
}

void RectangleUpExclude(int sizeX, int sizeY, int maxSizeX) {
	for (int i = 0; i < sizeY - 1; i++) {
		EmptyVerticalLineLayer(sizeX, maxSizeX);
	}
	DownVerticalLineLayer(sizeX, maxSizeX);
}

void PrintFir(int sizeX) {
	fir = "";
	if (sizeX < 2) printf("The dimentions are too small.\nP.S. Minimum size - 7");
	for (int i = 2; i <= sizeX - 2; i += 2)
	{
		if (i == 2)TriangleEmpty(2, 0, 0, sizeX);
		else TriangleEmpty(i, i / 1.4, i / 2, sizeX);
	}
	TriangleEmpty(sizeX, sizeX/ 1.4, 0, sizeX);
	RectangleUpExclude(sizeX / 3.1, sizeX / 7, sizeX);
	cout << fir;
}

int main() {
	int x;
	printf("Enter the diameter of fir:\nx=");
	cin >> x;
	PrintFir(x);
	_getch();
}
