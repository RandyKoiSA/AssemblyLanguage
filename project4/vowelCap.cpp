#include <iostream>

using namespace std;
char c;

void readSentence() {
	cout << "Enter a sentence: ";
}
void readChar() {cin.get(c);}
void cap() {
	if (c == 'a') cout << 'A';
	else if (c == 'e') cout << 'E';
	else if (c == 'i') cout << 'I';
	else if (c == 'o') cout << 'O';
	else if (c == 'u') cout << 'U';
}
void print() {cout << c;}
int main(int argc, char * argv[]) {
	_asm {
		call	readSentence;
		call	readChar;
	whileloop:
		cmp		c, '\n';
		je		done;
		cmp		c, 'a';
		je		readcap;
		cmp		c, 'e';
		je		readcap;
		cmp		c, 'i';
		je		readcap;
		cmp		c, 'o';
		je		readcap;
		cmp		c, 'u';
		je		readcap;
	regularprint:
		call	print;
		call	readChar;
		jmp		whileLoop;
	readcap:
		call	cap;
		call	readChar;
		jmp		whileloop;
	done:
	}
O	return 0;
}