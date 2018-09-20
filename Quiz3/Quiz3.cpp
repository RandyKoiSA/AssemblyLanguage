#include <iostream>

using namespace std;

int age;
char sex;
int result;

int Ma = 1000, Mt = 500, Fa = 1200, Ft = 400;
void menu() {
	cout << "---------------------Lakers Club---------------------\n";
	cout << "Male\n";
	cout << "\tAdults(age>=20)...........................$1000\n";
	cout << "\tTeenagers(13<=age<=19)....................$500\n";
	cout << "Female\n";
	cout << "\tAdults....................................$1200\n";
	cout << "\tTeenagers.................................$400\n";
}

void getInput() {
	cout << "\nHow old are you? ";
	cin >> age;
	cout << "\nWhat is your gender(m/f)? ";
	cin >> sex;
}

int main() {
	_asm {
		call	menu;
		call	getInput;
		cmp		sex, 'm';
		Je		male;
	female:
		cmp		age, 20;
		Jge		femaleAdult;
	maybeFemaleTeen:
		cmp		age, 13;
		Jge		femaleTeen;
	femaleChild:
		mov		result, 0;
		jmp		done;
	femaleAdult:
		mov		result, 1200;
		jmp		done;
	femaleTeen:
		mov		result, 400;
		jmp		done;
	male:
		cmp		age, 20;
		Jge		maleAdult;
	maybeMaleTeen:
		cmp		age, 13;
		Jge		maleTeen;
	maleChild:
		mov		result, 0;
		jmp		done;
	maleAdult:
		mov		result, 1000;
		jmp		done;
	maleTeen:
		mov		result, 500;
		jmp		done;
	done:

	}
	cout << "Your membership is " << result << endl;
	return 0;
}