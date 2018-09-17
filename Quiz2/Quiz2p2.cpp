#include <iostream>

using namespace std;


int main() {
	short a = 5, b = 7, c = 5, q;
	short twenty = 20;

	_asm {
		mov		ax, a;		// eax = a;
		add		ax, b;		// eax = a+b;
		imul	a;			// eax = a(a+b);
		imul	twenty;		// eax = 

		mov		bx, ax;	// ebx = 20*a*(a+b);
		mov		ax, c;		// eax = c;
		imul	c;			// eax = c^2;
		imul	c;			// eax = c^3;
		mov		cx, ax;	// ecx = eax;
		mov		ax, bx;

		cwd;
		idiv	cx;
		mov		q, ax;
	}
	cout << "q = " << q << endl;

	return 0;
}