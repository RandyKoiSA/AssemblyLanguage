#include <iostream>
using namespace std;
float r, h, pi = 3.14, two = 2.0, SA, Volume;
void getValue(); void getResults();
int main() {
	_asm {
		call	getValue;
		//finding SA
		fld		two;
		fld		pi;
		fld		r;
		fld		h;
		fmul;
		fmul;
		fmul;
		fld		two;
		fld		pi;
		fld		r;
		fld		r;
		fmul;
		fmul;
		fmul;
		fadd;
		fstp	SA;

		//Finding Volume
		fld		h;
		fld		pi;
		fmul;
		fld		r;
		fld		r;
		fmul;
		fmul;
		fstp	Volume;

		call	getResults;
	}
	return 0;
}
void getValue() {
	cout << "Enter the values of radius and height: ";
	cin >> r >> h;
}
void getResults() {
	cout << "\tSurface area = "  << SA << endl;
	cout << "\tVolume = " << Volume << endl;
}