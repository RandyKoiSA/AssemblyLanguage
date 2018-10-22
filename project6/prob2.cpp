#include <iostream>

using namespace std;

int a[5] = { 9, 3, 22, 8, 1 };
int i;

void printArray();

int main() {
	std::cout << "Original array a: ";
	printArray();

	_asm {
		mov		i, 1;			//counter
		lea		esi, a;
	whileloop:
		cmp		i, 5;
		je		done;
		mov		eax, [esi];
		cmp		eax, [esi + 4];
		jg		swapin;
		jmp		cont;
	swapin:
		mov		eax, [esi];
		mov		ebx, [esi + 4];
		mov		[esi], ebx;
		mov		[esi + 4], eax;
		lea		esi, a;
		mov		i, 1;
		jmp		whileloop;
	cont:
		inc		i;
		add		esi, 4;
		jmp		whileloop;
	done:
	}

	std::cout << "Sorted array a: ";
	printArray();

	return 0;
}

void printArray() {
	for (int i = 0; i < 5; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << endl;
}