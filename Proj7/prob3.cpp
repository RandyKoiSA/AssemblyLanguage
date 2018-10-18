#include <iostream>
using namespace std;
float	soda = 2.25,
		water = 1.75,
		juice = 2.80,
		sw10 = 3.45,
		sw12 = 5.25,
bill, drinktotal = 0, sandwichtotal = 0, drink, sandwich;
//choice variables
int sandwichInt;
char drinkchar;

void getValue();
int main() {
	_asm {
		call	getValue;

		cmp		drinkchar, 's';
		je		isSoda;
		cmp		drinkchar, 'S';
		je		isSoda;
		cmp		drinkchar, 'w';
		je		isWater;
		cmp		drinkchar, 'W';
		je		isWater;
		cmp		drinkchar, 'j';
		je		isJuice;
		cmp		drinkchar, 'J';
		je		isJuice;
		jmp		readSandwich;

	isSoda:
		fld		soda;
		fld		drink;
		fmul;
		fstp	drinktotal;
		jmp		readSandwich;
	isWater:
		fld		water;
		fld		drink;
		fmul;
		fstp	drinktotal;
		jmp		readSandwich;
	isJuice:
		fld		juice;
		fld		drink;
		fmul;
		fstp	drinktotal;
		jmp		readSandwich;

	readSandwich:
		cmp		sandwichInt, 10;
		je		isTen;
		cmp		sandwichInt, 12;
		je		isTwelve;
		jmp		done;
	isTen:
		fld		sandwich;
		fld		sw10;
		fmul;
		fstp	sandwichtotal;
		jmp		done;
	isTwelve:
		fld		sandwich;
		fld		sw12;
		fmul;
		fstp	sandwichtotal;
		jmp		done;

	done:
		fld		sandwichtotal;
		fld		drinktotal;
		fadd;
		fstp	bill;
	}
	cout << "\tYour total bill = " << bill << endl;
	return 0;
}
void getValue() {
	cout << "----------7-11 Convenient Store----------\n";
	cout << "Drinks\n";
	cout << "\tSoda(S)...........................$2.25\n";
	cout << "\tWater(W)..........................$1.75\n";
	cout << "\tJuice(J)..........................$2.80\n";
	cout << "Sandwiches\n";
	cout << "\t10 inches.........................$3.45\n";
	cout << "\t12 inches.........................$5.25\n\n\n";
	cout << "How many drinks? ";
	cin >> drink;
	cout << "What kind of drink(S=soda, W=water, J=juicie)? ";
	cin >> drinkchar;
	cout << "How many sandwiches? ";
	cin >> sandwich;
	cout << "What size od sanwich(10/12 inches)? ";
	cin >> sandwichInt;
}