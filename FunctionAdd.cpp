/*
Kenneth Adair
Simple program that illustrates the basic concept of a function.
*/

#include <iostream>
using namespace std;

int add(int x, int y);

int main(){
	cout << add(5, 6) << endl;
}

int add(int x, int y)
{
	return x + y;
}
