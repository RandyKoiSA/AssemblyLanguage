#include <iostream>

using namespace std;
short c;
short total;
short pin;
short n;

void displayValid(){
	cout << " is a valid ID for the family\n";
}
void displayInvalid(){
	cout << " is a invalid ID for the family\n";

}
void displayHex() {
	cout << hex << pin;
}

int main(int argc, char *argv[]) {
	_asm {
		mov		n, 1;
	setPIN:

		cmp		n, 4;
		je		done;

		cmp		n, 1;
		je		pin1;

		cmp		n, 2;
		je		pin2;

		cmp		n, 3;
		je		pin3;
	pin1:

		mov		pin, 0xBEEF;
		call	displayHex;
		jmp		loopfnc;
	pin2:
		mov		pin, 0xFADE;
		call	displayHex;
		jmp		loopfnc;
	pin3:
		mov		pin, 0xCABE;
		call	displayHex;
		jmp		loopfnc;

	loopfnc:
		mov		ax, pin;
		mov		c, 0xF000;
		mov		bx, 0;
		and		c, ax;
		shr		c, 12;
		mov		bx, c;

		mov		c, 0x0F00;
		and		c, ax;
		shr		c, 8;
		add		bx, c;

		mov		c, 0x00F0;
		and		c, ax;
		shr		c, 4;
		add		bx, c;

		mov		c, 0x000F;
		and		c, ax;
		add		bx, c;

		//Check if total is even
		mov		c, 1;
		mov		total, bx;
		and		c, bx;
		cmp		c, 1;
		je		isOdd;
		jmp		isEven;
	isEven:
		call	displayValid;
		jmp		incn;
	isOdd:
		call	displayInvalid;
		jmp		incn;
	incn:
		inc		n;
		jmp		setPIN;
	done:

	}
	return 0;
}