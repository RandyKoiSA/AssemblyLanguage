#include <iostream>

int main(int argc, char argv[]) {
	//Use the following formula for temperature conversoin: C= 5 ( F-32) / 9
	int input;
	int result;
	int thirtytwo = 32;
	int five = 5, nine = 9;
	std::cout << "Enter temperature in Fahrenheit: ";
	std::cin >> input;

	_asm {
		mov		eax, input;		//eax = input
		sub		eax, thirtytwo; //eax = input - 32
		imul	five;			//eax = 5 ( input - 32)
		idiv	nine;			//eax = 5 (input - 32) / 9
		mov		result, eax;		//input = eax;

	}
	std::cout << input << " F is " << result << " C" << std::endl;
	return 0;
}