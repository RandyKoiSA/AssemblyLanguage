#include <iostream>

using namespace std;
char c;
int yesCount = 0, noCount = 0;
void readSentence() { cout << "Enter a string of votes: ";}
void readChar() { cin.get(c); }
int main(int argc, char *argv[]) {
	_asm {
		call	readSentence;
		call	readChar;
	whileloop:
		cmp		c, '\n';
		Je		done;
		cmp		c, 'y';
		Je		addYes;
		inc		noCount;
		call	readChar;
		jmp		whileloop;
	addYes:
		inc		yesCount;
		call	readChar;
		jmp		whileloop;
	done:
	}
	cout << "No. of YES votes = " << yesCount << " = ";
	for (int i = 0; i < yesCount; i++) { cout << "*"; }
	cout << "\nNo. of NO votes = " << noCount << " = ";
	for (int i = 0; i < noCount; i++) { cout << "*"; }
	return 0;
}