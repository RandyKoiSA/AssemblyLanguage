#include <iostream>

using namespace std;

short a, b, c, d, e, f;
short bottomfrac;
short x, y;

int main() {
	cout << "Enter the value of a, b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the value of d, e, and f: ";
	cin >> d >> e >> f;

	_asm {
		//Start with y
		mov		ax, b;
		imul	d;	//ax = b*d
		mov		bx, ax;
		mov		ax, a;
		imul	e;  //ax = a*e
		sub		ax, bx; //ax = a*e - b*d
		mov		bottomfrac, ax; //dx = a*e - b*d

		mov		ax, d;
		imul	c;
		mov		bx, ax;
		mov		ax, f;
		imul	a;
		sub		ax, bx;
		idiv	bottomfrac;
		mov		y, ax;

		//On with x
		mov		ax, f;
		imul	b;
		mov		bx, ax;
		mov		ax, e;
		imul	c;
		sub		ax, bx;
		idiv	bottomfrac;
		mov		x, ax;

	}
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;

	return 0;
}	