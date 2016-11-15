/*
Kenneth Adair
If you don't know a variable's type you can tell the compiler
to pick it for you using the "auto" keyword.  So for this example
instead of writing "float var = 5.0" or "double var = 5.0" I wrote
"auto var = 5.0" and it picks the type that matches the best
and goes with that.
*/
#include <iostream>
using namespace std;

int main()
{
	auto var = 5.0;
	cout << var/2 << endl;
	return 0;
}
