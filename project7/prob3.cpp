#include <iostream>
using namespace std;
float	soda = 2.25,
water = 1.75,
juice = 2.80,
sw10 = 3.45,
sw12 = 5.25,
bill, drinktotal = 0, sandwichtotal = 0, drink, sandwich;
//choice variables
int sandwichInt, counter = 0, customer;
char drinkchar;

void getValue();
void getCustomer();
void menu();
void displayCustomer();
void displayBill();
int main() {
	_asm {
		call	menu;
		call	getCustomer;
		mov		ecx, 0;
	beginning:
		cmp		customer, 0;
		je		done;

		call	displayCustomer;
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
		jmp		displaybill;
	isTen:
		fld		sandwich;
		fld		sw10;
		fmul;
		fstp	sandwichtotal;
		jmp		displaybill;
	isTwelve:
		fld		sandwich;
		fld		sw12;
		fmul;
		fstp	sandwichtotal;
		jmp		displaybill;

	displaybill:
		fld		sandwichtotal;
		fld		drinktotal;
		fadd;
		fstp	bill;

		call	displayBill;
		dec		customer;
		inc		counter;
		jmp		beginning;

	done:

	}
	return 0;
}
void getValue() {
	cout << "How many drinks? ";
	cin >> drink;
	cout << "What kind of drink(S=soda, W=water, J=juicie)? ";
	cin >> drinkchar;
	cout << "How many sandwiches? ";
	cin >> sandwich;
	cout << "What size od sanwich(10/12 inches)? ";
	cin >> sandwichInt;
}
void menu() {
	cout << "----------7-11 Convenient Store----------\n";
	cout << "Drinks\n";
	cout << "\tSoda(S)...........................$2.25\n";
	cout << "\tWater(W)..........................$1.75\n";
	cout << "\tJuice(J)..........................$2.80\n";
	cout << "Sandwiches\n";
	cout << "\t10 inches.........................$3.45\n";
	cout << "\t12 inches.........................$5.25\n";
}
void getCustomer() {
	cout << "Enter the number of customers: ";
	cin >> customer;
}
void displayBill() {
	cout << "\tYour total bill =" << bill << endl;
}
void displayCustomer() {
	cout << "Customer " << counter+1 << endl;
}