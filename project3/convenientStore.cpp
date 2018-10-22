#include <iostream>

using namespace std;

void menu() {
	cout << "----------------------------7-11 Convenient Store----------------------------\n";
	cout << " Drinks:\n";
	cout << " \tSoda(S).....................................................$2\n";
	cout << " \tWater(W)....................................................$1\n";
	cout << " Sandwiches:\n";
	cout << " \t10 inches...................................................$3\n";
	cout << " \t12 inches...................................................$5\n";

}


int main() {
	int cSoda = 2, cWater = 1, cTenS = 3, cTwelveS = 5;

	int qDrink, qSandwich;
	char drinkType;
	int sandwichType;
	int bill;

	menu();

	cout << "\n\nHow many drinks? ";
	cin >> qDrink;
	cout << "What kind of drink(S=Sode, W=Water)? ";
	cin >> drinkType;
	cout << "\nHow many Sandwiches? ";
	cin >> qSandwich;
	cout << "What size of the sandwich (10/12 inches)? ";
	cin >> sandwichType;

	_asm {
		cmp		drinkType, 'S';
		Je		soda;
	water:
		mov		eax, cWater;
		imul	qDrink;
		mov		ebx, eax;
		jmp		sandwich;
	soda:
		mov		eax, cSoda;
		imul	qDrink;
		mov		ebx, eax;
	sandwich:
		cmp		sandwichType, 10;
		Je		tenInch;
	twelveInch:
		mov		eax, cTwelveS;
		imul	qSandwich;
		jmp		total;
	tenInch:
		mov		eax, cTenS;
		imul	qSandwich;
		jmp		total;
	total:
		add		eax, ebx;
		mov		bill, eax;
	}
	cout << "Your total bill = " << bill << endl;
	return 0;
}