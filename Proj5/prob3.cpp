#include <iostream>

using namespace std;
short c;
short counter;
short n = 0;
void displayone() {
	cout << "1";
}
void displayzero() {
	cout << "0";
}
void sprinkleron() {
	cout << endl << n << " sprinklers ar ON";
}
int main(int argc, char *argv[]) {

	_asm {
		mov		bx, 0x6A2F;			//ax = 0110 1010 0010 1111b
		mov		c, 1;
		mov		counter, 16;
	whileloop:
		cmp		counter, 0;
		je		done;

		rol		bx, 1;
		mov		ax, bx;
		and		ax, c;
		cmp		ax, 0;
		je		iszero;
		jmp		isone;
	isone:
		inc		n;
		call	displayone;
		jmp		cont;
	iszero:
		call	displayzero;
		jmp		cont;
	cont:
		dec		counter;
		jmp		whileloop;
	done:
		call	sprinkleron;
	}
	return 0;
}