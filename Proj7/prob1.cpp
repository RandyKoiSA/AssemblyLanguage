#include <iostream>

using namespace std;

/* Global Variables */
float a, b, c, d, h,
w, l, AoT, PoT, AoR, PoR;

float two = 2;
/* Inialize Methods*/
void displayImage();
void getAnswers();
void displayAnswers();

int main() {

	_asm {
		call	displayImage;
		call	getAnswers;
	beginning:
		/* Getting Area of Triangle */
			fld		b;		st[0] = b
			fld		h;		st[0] = h, st[1] = b
			fmul;			st[0] = h * b
			fld		two;	st[0] = 2, st[1] = h * b
			fdiv;			st[0] = (h*b) / 2
			fstp	AoT;	AoT = (h*b) / 2
		/* Getting Parameter of Triangle */
			fld		a;
			fld		b;
			fadd;
			fld		c;
			fadd;
			fstp	PoT;
		/* Getting Area of Rectangle */
			fld		l;
			fld		w;
			fmul;
			fstp	AoR;
		/* Getting Parameter of Rectangle */
			fld		two;
			fld		w;
			fmul;
			fld		two;
			fld		l;
			fmul;
			fadd;
			fstp	PoR;

			call	displayAnswers;
	}

	cin.ignore();
	cin.get();
	return 0;
}

void displayImage() {
	cout << "           /|\\       --------------------" << endl;
	cout << "          / | \\      |                  |" << endl;
	cout << "       a /  |  \\ b   |                  | width" << endl;
	cout << "        /  h|   \\    |                  |" << endl;
	cout << "       /____|____\\   --------------------" << endl;
	cout << "            c                height       " << endl;
}

void getAnswers() {
	cout << "Enter the values of a,b,c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	cin >> l >> w;
}

void displayAnswers() {
	cout << "Triangle" << endl;
	cout << "\tArea...................." << AoT << endl;
	cout << "\tParameter..............." << PoT << endl;
	cout << "Rectangle" << endl;
	cout << "\tArea...................." << AoR << endl;
	cout << "\tParameter..............." << PoR << endl;
}