#include <iostream>

using namespace std;

int main() {
	int thousand, hundred, ten ;
	int input;
	int total;
	cout << "Enter a 4 digit integer number: ";
	cin >> input;
	_asm {
		mov		thousand, 1000;
		mov		hundred, 100;
		mov		ten, 10;
		mov		total, 0;
		mov		eax, input;		//eax = input

		cdq;					//edx:eax = input
		idiv	thousand;		//edx = input % thousand && eax = input / thousand
		add		total, eax;
		mov		eax, edx;

		cdq;
		idiv	hundred;
		add		total, eax;
		mov		eax, edx;

		cdq;
		idiv	ten;
		add		total, eax;
		add		total, edx;
	}
	cout << "Total of digits is : " << total << endl;
	return 0;
}