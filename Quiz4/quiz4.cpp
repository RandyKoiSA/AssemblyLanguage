#include <iostream>

using namespace std;
char c;
int counter = 1;
char again;
void readSentence() { cout << "Enter a sentence: "; }
void readChar() { cin.get(c); }
void getC() { cin >> c; }

void readUpper() {
	c = toupper(c);
	cout << c;
}
void readLower() {
	c = tolower(c);
	cout << c;
}
void cont() { cout << "\nContinue(y/n)? "; }
void getCont() { cin >> again; }
int main(int argc, char * argv[]) {
	_asm {
	s:
		call	readSentence;
		call	getC;
	whileloop:
		cmp		c, '\n';
		je		done;
		cmp		counter, 1;
		je		callUpper;
		call	readLower;
		call	readChar;
		mov		counter, 1;
		jmp		whileloop;
	callUpper:
		call	readUpper;
		call	readChar;
		mov		counter, 0;
		jmp		whileloop;

	done:
		call	cont;
		call	getCont;
		cmp		again, 'y';
		je		s;

	}
	return 0;
}