#include <iostream>

using namespace std;

int a[4][4] = { 10, 20, 30, 40,
				20, 10, 40, 30,
				5,  15, 20, 25,
				30, 25, 20, 15 };
int i, totalshirts = 0 , largeshirts = 0, blackshirts = 0;

void totalshirtsfunc(); void largeshirtsfunc(); void blackshirtsfunc();

int main(int argc, char *argv[]) {
	_asm {
		lea		esi, a;
		mov		eax, 0;				//counter the total amount of clothes in the 2Darray
		mov		i, 0;
	whileloop://Search number of shirts in the array
		cmp		i, 16;				//counter to stop the while loop
		je		searchLargeShirts;

		add		eax, [esi];			//puts the value of the array element in the register eax
		add		esi, 4;
		inc		i;					//increment i, the counter
		jmp		whileloop;			//goes back tot the whileloop

	searchLargeShirts://Search number of large shirts in the array
		mov		totalshirts, eax;	//move total shirts to a memory
		call	totalshirtsfunc;	 //dislay total shirts in CLI

		mov		eax, 0;
		lea		esi, a;
		add		esi, 8;

		mov		i, 0;

	whilebloop:
		cmp		i, 4;
		je		searchBlackShirts;

		add		eax, [esi];
		add		esi, 16;
		inc		i;
		jmp		whilebloop;

	searchBlackShirts: //Search number of black shirts in the array
		mov		largeshirts, eax;
		call	largeshirtsfunc;

		lea		esi, a;
		add		esi, 48;
		mov		eax, 0;
		mov		i, 0;

	whilecloop:
		cmp		i, 4;
		je		done;

		add		eax, [esi];
		add		esi, 4;
		inc		i;
		jmp		whilecloop;
	done:
		mov		blackshirts, eax;
		call	blackshirtsfunc;
	}
	return 0;
}


void totalshirtsfunc() {
	std::cout << "Total of shirts in the array: " << totalshirts << std::endl;
}
void largeshirtsfunc() {
	std::cout << "Total of large shirts in the array: " << largeshirts << std::endl;
}
void blackshirtsfunc() {
	std::cout << "Total of black shirts in the array: " << blackshirts << std::endl;
}