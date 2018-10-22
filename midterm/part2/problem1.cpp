#include <iostream>
using namespace std;
int p[3][4] = { {33,31,20,20},
				{23,22,24,30},
				{10,20,30,40} };
int stuFullerton, stuIrvine, stuGardengrove, freshman, sophmore, junior, senior;
void displayIleast(); void displayFleast(); void displayGGleast(); void displayResults();
int main() {
	_asm {
		lea		esi, p;
		mov		ecx, 0;	//counter
		mov		eax, 0; //storage
		mov		ebx, 0; //placement
	getFStu:
		cmp		ecx, 4;
		je		getIStu;
		add		eax, [p + ebx];
		add		ebx, 4;
		inc		ecx;
		jmp		getFStu;
	getIStu:
		mov		stuFullerton, eax;
		mov		eax, 0;
		mov		ebx, 16;
		mov		ecx, 0;
	Iloop:
		cmp		ecx, 4;
		je		getGStu;
		add		eax, [p + ebx];
		add		ebx, 4;
		inc		ecx;
		jmp		Iloop;
	getGStu:
		mov		stuIrvine, eax;
		mov		eax, 0;
		mov		ebx, 32;
		mov		ecx, 0;
	Gloop:
		cmp		ecx, 4;
		je		getFreshman;
		add		eax, [p + ebx];
		add		ebx, 4;
		inc		ecx;
		jmp		Gloop;
	getFreshman:
		mov		stuGardengrove, eax;
		mov		eax, 0;
		mov		ebx, 0;
		mov		ecx, 0;
	freshloop:
		cmp		ecx, 3;
		je		getSophmore;
		add		eax, [p + ebx];
		add		ebx, 16;
		inc		ecx;
		jmp		freshloop;
	getSophmore:
		mov		freshman, eax;
		mov		ebx, 4;
		mov		eax, 0;
		mov		ecx, 0;
	sophloop:
		cmp		ecx, 3;
		je		getJunior;
		add		eax, [p + ebx];
		add		ebx, 16;
		inc		ecx;
		jmp		sophloop;
	getJunior:
		mov		sophmore, eax;
		mov		ebx, 8;
		mov		eax, 0;
		mov		ecx, 0;
	juniorloop:
		cmp		ecx, 3;
		je		getSenior;
		add		eax, [p + ebx];
		add		ebx, 16;
		inc		ecx;
		jmp		juniorloop;
	getSenior:
		mov		junior, eax;
		mov		ebx, 12;
		mov		eax, 0;
		mov		ecx, 0;
	seniorloop:
		cmp		ecx, 3;
		je		determineLowestStu;
		add		eax, [p + ebx];
		add		ebx, 16;
		inc		ecx;
		jmp		seniorloop;
	determineLowestStu:
		mov		senior, eax;
		call	displayResults;
		mov		ebx, stuFullerton;
		cmp		ebx, stuIrvine;
		jl		fg;
	ig:
		mov		ebx, stuIrvine;
		cmp		ebx, stuGardengrove;
		jl		ileast;
		jmp		ggleast;
	fg:
		mov		ebx, stuFullerton;
		cmp		ebx, stuGardengrove;
		jl		fleast;
		jmp		ggleast;
	ileast:
		call	displayIleast;
		jmp		done;
	fleast:
		call	displayFleast;
		jmp		done;
	ggleast:
		call	displayGGleast;
		jmp		done;
	done:

	}
	return 0;
}

void displayIleast() {
	cout << "Irvine has the minimum number of students\n";
}
void displayFleast() {
	cout << "Fullerton has the minimum number of students\n";
}
void displayGGleast() {
	cout << "Garden grove has the minimum number of students\n";
}
void displayResults() {
	cout << "Fullerton Campus....... " << stuFullerton << endl;
	cout << "Irvine Campus.......... " << stuIrvine << endl;
	cout << "Garden Grove Campus.... " << stuGardengrove << endl;
	cout << "Freshman............... " << freshman << endl;
	cout << "Sophmore............... " << sophmore << endl;
	cout << "Junior................. " << junior << endl;
	cout << "Senior................. " << senior << endl;
}