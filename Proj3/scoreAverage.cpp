#include <iostream>

using namespace std;

int score = 0;
int average = 0;
int total = 0;
int n = 0;


void getScore() {
	cout << "Enter your score (-1) to stop: ";
	cin >> score;
}

int main() {
	cout << "Let's compute your score's average: \n";

	_asm {
		mov		eax, 0;
	start:
		call	getScore;
		cmp		score, -1;
		Jne		addScore;
	exit:
		mov		eax, total;
		cdq;
		idiv	n;
		jmp		done;
	addScore:
		inc		n;
		mov		ebx, score;
		add		total, ebx;
		Jmp		start;
	done:
		mov		average, eax;
	}
	cout << "\tYour average is: " << average << endl;
	return 0;
}