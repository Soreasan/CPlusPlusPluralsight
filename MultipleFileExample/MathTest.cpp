#include <iostream>
using namespace std;

int add(int x, int y);
int add(int x, int y, int z);
int subtract(int x, int y);
int multiply(int x, int y);
int multiply(int x, int y, int z);

int main()
{
	cout << "5 + 10 = " << add(5, 10) << endl;
	cout << "10 - 3 = " << subtract(10, 3) << endl;
	cout << "5 * 5 * 5 = " << multiply(5, 5, 5) << endl;
	return 0;
}
