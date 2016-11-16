/*
Kenneth Adair
Overloading means we can have multiple functions with
the same name but different inputs that would call separate functions.
For example instead of having add2, add3, add4, etc to add different
amounts of numbers we can just use the same name and have different
arguments/inputs and our program just kinda sorta automatically picks
the correct function.
*/

#include <iostream>
using namespace std;

double add(double x, double y);
double add(double x, double y, double z);
double add(double a, double b, double c, double d);

int main(){
	cout << "5 + 10 = " << add(5, 10) << endl;
	cout << "7 + 2 + 3 = " << add(7, 2, 3) << endl;
	cout << "1 + 2 + 3 + 4 = " << add(1, 2, 3, 4) << endl;
	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double add(double x, double y, double z)
{
	return x + y + z;
}

double add(double a, double b, double c, double d)
{
	return a + b + c + d;
}
