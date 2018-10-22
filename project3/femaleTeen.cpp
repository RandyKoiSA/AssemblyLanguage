#include <iostream>
#include <string>

using namespace std;

string name;
int age; char gender;

void showFemaleTeen() {
	cout << name << ", you are a female teenager.\n";
}
void showNotFemaleTeen() {
	cout << name << ", you are not a female teeanger.\n";
}

int main() {


	cout << "Enter your name: ";
	cin >> name;
	cout << name << ", how old are you? ";
	cin >> age;
	cout << name << " what is your gener (m/f)? ";
	cin >> gender;

	_asm {
		cmp		gender, 'F';
		Je		checkTeen;
	checkFemale:
		cmp		gender, 'f';
		Je		checkTeen;
	notFemale:
		call	showNotFemaleTeen;
		call		done;
	checkTeen:
		cmp		age, 13;
		Jge		isFT;
	notFT:
		call	showNotFemaleTeen;
		jmp		done;
	isFT:
		call	showFemaleTeen;
	done:
	}

	return 0;
}