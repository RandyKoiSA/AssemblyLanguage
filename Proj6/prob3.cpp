#include <iostream>
					//Red Shirts
int a[3][3][2] = { 1, 2,	//Row1: S , Row2: M, Row3: L  //Column 1: Short Sleeve, Column 2: Long Sleeves
				 3, 4,		
				5, 6,	   //Blue Shirts
						7, 8,		
					   9, 10,
					 11, 12,	    //Black Shirts
								13, 14, 
							  15,16,
							 17,18 };
int i , totalshirts, mediumshirts, shortsleeveshirts, redshirts;
int main() {
	_asm {
		mov		i, 0;
		lea		esi, a;
		mov		eax, 0;
	whileloop:
		cmp		i, 18;
		je		readMedShirts;
		add		eax, [esi];
		add		esi, 4;
		inc		i;
		jmp		whileloop;

	readMedShirts:
		mov		totalshirts, eax;
		mov		i, 0;
		lea		esi, a;
		add		esi, 12;
		mov		eax, 0;
	whilebloop:
		cmp		i, 6;
		je		readShortSleeves;

		add		eax, [esi];
		add		esi, 4;
		add		eax, [esi];
		add		esi, 20;
		add		i, 2;
		jmp		whilebloop;



	readShortSleeves:
		mov		mediumshirts, eax;
		mov		i, 0;
		lea		esi, a;
		mov		eax, 0;


	}
	std::cout << "Total shirts: " << totalshirts << std::endl;
	std::cout << "Medium shirts: " << mediumshirts << std::endl;
	return 0;
}
							