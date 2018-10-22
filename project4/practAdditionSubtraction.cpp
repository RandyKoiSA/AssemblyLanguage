#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

using namespace std;
short n = 0;
short x = 0, y = 0;
short result = 0;
short userInput = 0;
char c;
short numCorrect = 0, numWrong = 0;

void generateRand() {
	x = rand() % 100 + 1;
	y = rand() % 100 + 1;
}
void getInput(){ cin >> userInput; }
void getCharInput() { ;
	cin >> c; }
void displayWrong() { cout << "Wrong: the answer was " << result << "\n";  }
void displayCorrect() { cout << "Correct\n"; }
void displayMenu() {
	cout << "a. Practice Addition\n";
	cout << "b. Practice Subtraction\n";
}
void displayFResult() {
	cout << "No. of CORRECT answers = " << numCorrect << endl;
	cout << "No. of WRONG answers = " << numWrong << endl;
	cout << "Are you done(y/n)? ";
}
void displaySub() { cout << x << " - " << y << " ? "; 
	_asm {
		mov		ax, x;
		sub		ax, y;
		mov		result, ax;
	}
}
void displayAdd(){ cout << x << " + " << y << " ? ";
	_asm{
		mov		ax, x;
		add		ax, y;
		mov		result, ax;
	}
}
int main(int argc, char *argv[]) {
	_asm {
	start:
		mov		numCorrect, 0;
		mov		numWrong, 0;
		mov		n, 0;
		call	displayMenu;
		call	getCharInput;
		cmp		c, 'a';
		je		addition;
	subtraction:
		call	generateRand;
		call	displaySub;
		call	getInput;
		mov		ax, userInput;
		cmp		result, ax;
		Je		bcorrect;
	bwrong:
		call	displayWrong;
		inc		numWrong;
		jmp		bcont;
	bcorrect:
		call	displayCorrect;
		inc		numCorrect;
	bcont:
		cmp		n, 1;
		je		done;
		inc		n;
		jmp		subtraction;
	addition:
		call	generateRand;
		call	displayAdd;
		call	getInput;
		mov		ax, userInput;
		cmp		result, ax;
		je		acorrect;
	awrong:
		call	displayWrong;
		inc		numWrong;
		jmp		acont;
	acorrect:
		call	displayCorrect;
		inc		numCorrect;
	acont:
		cmp		n, 1;
		Je		done;
		inc		n;
		jmp		addition;
	done:
		call	displayFResult;
		call	getCharInput;
		cmp		c, 'y';
		je		quit;
		call	start;
	quit:
	}
	cout << "Have a nice day\n";

	return 0;
}