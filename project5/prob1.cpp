#include <iostream>

using namespace std;

int main() {
	short floppySearch, ramSearch, printerSearch;
	short numFloppy, numRam, numPrinter;
	_asm {
		mov		ax, 1100111010011100b;				//ax = 1100 1110 1001 1100b
		mov		printerSearch, 1100000000000000b;	//pr = 1100 0000 0000 0000b
		mov		floppySearch,  0000000001100000b;	//fl = 0000 0000 0110 0000b
		mov		ramSearch,     0000000000000110b;	//rm = 0000 0000 0000 0110b
		//printerSearch
		mov		bx, ax;
		and		bx, printerSearch;
		shr		bx, 14;
		cmp		bx, 0;
		je		zeroPrinter;
		cmp		bx, 1;
		je		onePrinter;
		cmp		bx, 2;
		je		twoPrinter;
		cmp		bx, 3;
		je		threePrinter;
		jmp		floppy;
	zeroPrinter:
		mov		numPrinter, 0;
		jmp		floppy;
	onePrinter:
		mov 	numPrinter, 1;
		jmp		floppy;
	twoPrinter:
		mov	numPrinter, 2;
		jmp		floppy;
	threePrinter:
		mov 	numPrinter, 3;
		jmp		floppy;
	//Floppy Search
	floppy:
		mov		bx, ax;
		and		bx, floppySearch;
		shr		bx, 5;
		cmp		bx, 0;
		je		oneDrive;
		cmp		bx, 1;
		je		twoDrive;
		cmp		bx, 2;
		je		threeDrive;
		cmp		bx, 3;
		je		fourDrive;
		jmp		ram;
	oneDrive:
		mov		numFloppy, 1;
		jmp		ram;
	twoDrive:
		mov		numFloppy, 2;
		jmp		ram;
	threeDrive:
		mov		numFloppy, 3;
		jmp		ram;
	fourDrive:
		mov		numFloppy, 4;
		jmp		ram;
	//Ram Search
	ram:
		mov		bx, ax;
		and		bx, ramSearch;
		shr		bx, 1;
		cmp		bx, 0;
		je		ram16;
		cmp		bx, 1;
		je		ram32;
		cmp		bx, 2;
		je		ram48;
		cmp		bx, 3;
		je		ram64;
		jmp		done;
	ram16:
		mov		numRam, 16;
		jmp		done;
	ram32:
		mov		numRam, 32;
		jmp		done;
	ram48:
		mov		numRam, 48;
		jmp		done;
	ram64:
		mov		numRam, 64;
		jmp		done;
	done:


	}
	cout << "The number of printers connected to the computer: " << numPrinter << endl;
	cout << "The number of floppy dirves: " << numFloppy << endl;
	cout << "The size of the RAM: " << numRam << endl;
	return 0;
}