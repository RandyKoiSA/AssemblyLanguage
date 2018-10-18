#include <iostream>
#include <string>
using namespace std;

char gender;
string name;
char again;
short age;
short cost;
void getInput() {
	cout << "What is your name? ";
	cin >> name;
	cout << "Enter your age: ";
	cin >> age;
	cout << "what is your gender(m/f)? ";
	cin >> gender;
}
void getcontinue() {
	cout << "CONTINUE(y/n)? ";
	cin >> again;
}
void result() {
	cout << name << ", your memebership is " << cost << endl;
}
void menu() {
	cout << "-----24/7 SPORTS CLUB-----\n";
	cout << "Adults (age >= 20)\n";
	cout << "\tMale...............$10\n";
	cout << "\tFemale.............$20\n";
	cout << "Teenagers(13<=age<=19)\n";
	cout << "\tMale...............$30\n";
	cout << "\tFemale.............$10\n";
	cout << "Children(age <= 12)\n";
	cout << "\tFree...............$5\n";
	cout << "--------------------------\n\n\n";
}
int main() {
	_asm {
		call	menu;
	beginning:
		call	getInput;

		cmp		gender, 'm';
		je		isMale;

		cmp		gender, 'M';
		je		isMale;
		jmp		isFemale;
	isFemale:
		cmp		age, 20;
		jge		isFadult;
		cmp		age, 13;
		jge		isFteen;
		cmp		age, 12;
		jle		ischild;

	isFadult:
		mov		cost, 20;
		jmp		doitagain;
	isFTeen:
		mov		cost, 10;
		jmp		doitagain;
	ischild:
		mov		cost, 5;
		jmp		doitagain;

	isMale:
		cmp		age, 20;
		jge		isMadult;
		cmp		age, 13;
		jge		isMteen;
		cmp		age, 12;
		jle		ischild;

	isMadult:
		mov		cost, 10;
		jmp		doitagain;
	isMteen:
		mov		cost, 30;
		jmp		doitagain;


	doitagain:
		call	result;
		call	getcontinue;

		cmp		again, 'y';
		je		beginning;
		cmp		again, 'Y';
		je		beginning;

	done:

	}

	return 0;
}