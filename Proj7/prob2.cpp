#include <iostream>
using namespace std;
float a, b, c, negOne = -1, four = 4, two = 2, x1 = 0, x2 = 0;
void getValue(){
	cout << "Enter value a, b, and c for the quadratic equation: ";
	cin >> a >> b >> c;
}
int main() {
	_asm {
		call	getValue;
		//finding x1
		fld		negOne;		//st[0]=(-1)
		fld		b;			//st[0]=b st[1]=(-1)
		fmul;				//st[0]=(-1)*b
		fld		b;			//st[0]=b st[1]=(-1)*b
		fld		b;			//st[0]=b st[1]=b std[2]=(-1)*b
		fmul;				//st[0]=b*b st[1]=(-1)*b
		fld		four;		//st[0]=four st[1]=b*b std[2]=(-1)*b
		fld		a;			//st[0]=a st[1]=four st[2]=b*b st[3]=(-1)*b
		fld		c;			//st[0]=c st[1]=a st[2]=four st[3]=b*b st[4]=(-1)*b
		fmul;				//st[0]=c*a st[1]=four st[2]=b*b st[3]=(-1)*b
		fmul;				//st[0]=4ac st[1]=b*b st[2]=(-1)*b
		fsub;				//st[0]=b^2 - 4ac st[1]=(-1)*b
		fsqrt;				//st[0]=sqrt(b^2-4ac) st[1]=(-1)*b
		fadd;				//st[0]=(-1)*b + sqrt(b^2-4ac)
		fld		two;		//st[0]= two st[1]=(-1)*b + sqrt(b^2-4ac)
		fld		a;			//st[0]= a st[1]=two st[2]=(-1)*b + sqrt(b^2-4ac)
		fmul;				//st[0]= 2a st[1]=(-1)*b + sqrt(b^2-4ac)
		fdiv;				//st[0]= (-1)*b + sqrt(b^2-4ac)/2a;
		fstp	x1;

		//finding x2
		fld		negOne;		//st[0]=(-1)
		fld		b;			//st[0]=b st[1]=(-1)
		fmul;				//st[0]=(-1)*b
		fld		b;			//st[0]=b st[1]=(-1)*b
		fld		b;			//st[0]=b st[1]=b std[2]=(-1)*b
		fmul;				//st[0]=b*b st[1]=(-1)*b
		fld		four;		//st[0]=four st[1]=b*b std[2]=(-1)*b
		fld		a;			//st[0]=a st[1]=four st[2]=b*b st[3]=(-1)*b
		fld		c;			//st[0]=c st[1]=a st[2]=four st[3]=b*b st[4]=(-1)*b
		fmul;				//st[0]=c*a st[1]=four st[2]=b*b st[3]=(-1)*b
		fmul;				//st[0]=4ac st[1]=b*b st[2]=(-1)*b
		fsub;				//st[0]=b^2 - 4ac st[1]=(-1)*b
		fsqrt;				//st[0]=sqrt(b^2-4ac) st[1]=(-1)*b
		fsub;				//st[0]=(-1)*b - sqrt(b^2-4ac)
		fld		two;		//st[0]= two st[1]=(-1)*b - sqrt(b^2-4ac)
		fld		a;			//st[0]= a st[1]=two st[2]=(-1)*b - sqrt(b^2-4ac)
		fmul;				//st[0]= 2a st[1]=(-1)*b - sqrt(b^2-4ac)
		fdiv;				//st[0]= (-1)*b - sqrt(b^2-4ac)/2a;
		fstp	x2;

	}
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
		return 0;
}