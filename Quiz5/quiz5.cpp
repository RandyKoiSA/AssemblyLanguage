#include <iostream>

using namespace std;
short on = 0, c, totaldoors;

void displayA() {
	cout << "There are " << on << " ones in this register.\n";
}

void displaybit8on() {
	cout << "8 bit is on\n";
}

void displaybit8off() {
	cout << "8 bit is off\n";
}

void displaytotaldoors() {
	cout << "There are " << totaldoors << " opened.\n";
}

int main() {

	_asm {
		mov		bx, 1010111110111011b;
		mov		c, 1;
		mov		cx, 16;


	whileloop:					//determine which bits are on.
		cmp		cx, 0;
		je		bit8read;

		mov		ax, bx;
		and		ax, 1;
		cmp		ax, 1;
		ror		bx, 1;
		je		ison;
		call	isoff;
	isoff:
		jmp		cont;
	ison:
		inc		on;
		jmp		cont;
	cont:
		dec		cx;
		jmp		whileloop;

	bit8read:					//determin if bit 8 is on.
		call	displayA;
		//mov		bx, 1010111110111011b;
		shr		bx, 7;
		mov		ax, bx;
		and		ax, 1;
		cmp		ax, 1;
		je		bit8ison;
		jmp		bit8isoff;

	bit8isoff:
		call	displaybit8off;
		jmp		doorread;
	bit8ison:
		call	displaybit8on;
		jmp		doorread;

	//determine how many doors are open
	doorread:
		shr		bx, 3;
		mov		ax, bx;
		and		ax, 0x000F;
		mov		totaldoors, ax;
		call	displaytotaldoors;

	}

	return 0;
}