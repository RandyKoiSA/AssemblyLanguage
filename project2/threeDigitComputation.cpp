#include <iostream>

int main(int argc, char argv[]) {
	int input;
	int oneHundred, ten;
	int rem;
	int total;
	std::cout << "Enter a 3 digit integer number: ";
	std::cin >> input;


	_asm {
		mov		oneHundred, 100;
		mov		ten, 10;

		mov		eax, input;			//eax = input
		cdq;						//edx:eax = input;
		idiv	oneHundred;			//edx = input % 100
									//eax = input / 100
		mov		rem, edx;
		mov		total, eax;
		mov		eax, rem;

		cdq;
		idiv	ten;				//edx = rem % 10
									//eax = rem / 10
		add		total, edx;
		add		total, eax;
	}
	std::cout << "The total of digits in " << input << " is " << total << std::endl;
	return 0;
}