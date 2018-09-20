#include<iostream>
using namespace std;

int suma(int a, int b)
{
	if (a==0)
		return b;
	else
		return suma(a - 1, b + 1);
}
/*
int suma(int a, int b)
{

	if (a>0 and b>0)
		return 2 + suma(a - 1, b - 1);
	else
		if (a>0 or b>0)
			return 1 + suma(a - 1, b - 1);
		else
			return 0;
}

*/

int resta(int a, int b)
{
	if (a < b) 
		swap(a, b); //no considera el signo
	if (b == 0)
		return a;
	else 
		return resta(a - 1, b - 1);
}
/*
int resta(int a, int b)
{
	if (a>b)
		return 1 + resta(a, b + 1);
	else
		if (b>a)
			return -1 + resta(a + 1, b);
		else
			return 0;

}
*/
int multiplication(int a, int b)
{
	if (a==0 or b==0)
		return 0;
	else {
		return a+ multiplication(a, b - 1);
	}
}
int division(int a, int b)
{
	if (a == 0)
		return 0;
	else
		return 1+ division(a - b, b);
}
void main()
{
		cout << "sum" << endl;
		cout << "res" << endl;
		cout << "mul" << endl;
		cout << "div" << endl;

		int op;
		cin >> op;

		int a, b;
		cout << "Ingrese a: ";
		cin >> a;
		cout << "Ingrese b: ";
		cin >> b;

		switch (op)
		{
			case 1:
				cout << "Suma: " << a << " + " << b << " = " << suma(a, b);
				cin.ignore();
				break;
			case 2:
				cout << "Suma: " << a << " - " << b << " = " << resta(a, b);
				break;
			case 3:
				cout << "Suma: " << a << " * " << b << " = " << multiplication(a, b);
				break;
			case 4:
				if (b == 0) break;
				cout << "Suma: " << a << " + " << b << " = " << division(a, b);
				break;

		}
		system("pause");
}
