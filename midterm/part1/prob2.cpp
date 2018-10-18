/* Problem 2 on midterm */

#include <iostream>

using namespace std;

short c , n;
short counter;
short bitson = 0, frontyard = 0;
void Base2() {
	short x = 1 << 15, t;
	for (int i = 1; i <= 16; ++i) {
		t = n & x;
		if (t == 0) cout << "0";
		else cout << "1";
		if (i % 4 == 0) cout << ' ';
		n = n << 1;
	}
}
void callbitson() {
	cout << bitson << " bits are ON\n";
}
void callbackyard() {
	cout << "backyard is using more water.\n";
}
void callfrontyard() {
	cout << "frontyard is using more water.\n";
}

int main() {
	_asm {
		mov		bx, 1100111111011100b;
		mov		c, 1;
		mov		counter, 0;

	beginning:
		cmp		counter, 16;
		je		problemb;

		mov		ax, bx;
		and		ax, c;
		cmp		ax, 1;
		je		isOn;

	isOff:
		jmp		cont;
	isOn:
		inc		bitson;
	cont:
		inc		counter;
		shr		bx, 1;
		jmp		beginning;

	problemb:
		call	callbitson;
		//turn off bit 7 and 8
		mov		bx, 1100111111011100b;
		ror		bx, 6;
		sub		bx, 3;			//0111 0011 0011 1100 = 29,500
		rol		bx, 2;			//1100 1100 1111 0001 look at bit 1,2,3 and 5,6,7
		mov		c, 7;

		mov		ax, bx;
		and		ax, c;
		mov		frontyard, ax;
		
		ror		bx, 4;
		mov		ax, bx;
		and		ax, c;
		cmp		ax, frontyard;
		jg		backyardWin;
		jmp		frontyardWin;

	frontyardWin:
		call	callfrontyard;
		jmp		problemd;
	backyardWin:
		call	callbackyard;
		jmp		problemd;

	problemd:
		mov		bx, 1100111111011100b;
		mov		n, bx;
		call	Base2;
	}
	return 0;
}