/*
Kenneth Adair
This program demonstrates if and else statements.
*/

#include <iostream>
using namespace std;

int main()
{
	int i;
	int j;
	cout << "Enter a number: ";
	//Console Input
	cin >> i;
	cout << "You entered " << i << ".  Enter another number.";
	cin >> j;

	if(i < j)
	{
		cout << "The first number, " << i << ", is less than the second number, " << j << endl;
	}
	else
	{
		cout << "The first number, " << i << ", is not less than the second number, " << j << endl;
	}
	if(i == j)
	{
		cout << "The first number, " << i << ", is equal to the second number, " << j << endl;
	}
	if(i > j)
	{
		cout << "The first number, " << i << ", is more than the second number, " << j << endl;
	}
	return 0;
}
