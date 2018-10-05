#include <iostream>

using namespace std;
short n = 1;
short c;
short counter;
void printfloor() {
	cout << n << " ";
}
int main() {

	cout << "Elavator will stop at floors no. ";
	_asm {
		mov		bx, 1001000100001100b;
		mov		c, 1;
		mov		counter, 16;

	whileloop:
		cmp		counter, 0;
		je		done;

		mov		ax, bx;
		shr		bx, 1;
		and		ax, c;

		cmp		ax, 1;
		je		isPressed;
	
		jmp		cont;
	isPressed:
		call	printfloor;

	cont:
		inc		n;
		dec		counter;
		jmp		whileloop;
	done:

	}
	return 0;
}