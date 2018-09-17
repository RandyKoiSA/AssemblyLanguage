#include <iostream>

int main(int argc, char argv[]) {

	bool exitProg = false;
	short qd, qs;
	short drink, sandwich;
	short total = 0;

		std::cout << "---------------------MENU---------------------" << std::endl;
		std::cout << "Drinks......................................$4" << std::endl;
		std::cout << "Sandwiches...................................$7" << std::endl;

		std::cout << "\tHow many drinks? ";
		std::cin >> qd;
		std::cout << "\tHow many sandwiches? ";
		std::cin >> qs;

		_asm {
			mov		drink, 4;
			mov		sandwich, 7;

			mov		ax, drink;		//ax = qd
			imul	qd;		//dx:ax = gd * 4;
			mov		bx, ax;

			mov		ax, sandwich;
			imul	qs;
			add		ax, bx;
			mov		total, ax;
		}
		std::cout << "Your total bill " << total << " dollars" << std::endl;


	return 0;
}