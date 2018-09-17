#include <iostream>

int main(int argc, char argv[]) {
	int a, b, c, h, l, w;
	int two;
	int pTri, aTri, pRect, aRect;
	std::cout << "      ^       |--------------| " << std::endl;
	std::cout << "   a ^|^ b    |              | " << std::endl;
	std::cout << "    ^ | ^     |              | w" << std::endl;
	std::cout << "   ^  |h ^    |--------------| " << std::endl;
	std::cout << "   -------     l               " << std::endl;
	std::cout << "    c                          " << std::endl;

	std::cout << "Enter the values of a, b, c, and h: ";
	std::cin >> a >> b >> c >> h;
	std::cout << "Enter the balues of length and width of the rectangle: ";
	std::cin >> w >> l;

	_asm { //Find parimeter of tri
		mov		eax, a;
		add		eax, b;
		add		eax, c;
		mov		pTri, eax;
	}
	_asm { //Find area of triangle
		mov		two, 2;
		mov		eax, h;
		imul	c;
		idiv	two;
		mov		aTri, eax;
	}
	_asm { //Find parimeter of rect
		mov		eax, w;
		add		eax, w;
		add		eax, h;
		add		eax, h;
		mov		pRect, eax;
	}
	_asm { //Find area of rect
		mov		eax, w;
		imul	h;
		mov		aRect, eax;
	}
	std::cout << "Triangle\n";
	std::cout << "\tArea.........." << aTri << std::endl;
	std::cout << "\tParimeter....." << pTri << std::endl;

	std::cout << "Rectangle\n";
	std::cout << "\tArea.........." << aRect << std::endl;
	std::cout << "\tParimeter....." << pRect << std::endl;

	return 0;
}