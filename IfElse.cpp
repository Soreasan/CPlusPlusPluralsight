/*
Kenneth Adair
Following a long with C++ Fundamentals course on Pluralsight.
This demonstrates If Else statements.
*/

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "Enter two numbers" << endl;
    cin >> x >> y;
    cout << x << " is ";
    if(x > y)
        cout << "larger than ";
    else
        cout << "smaller than ";
    cout << y << endl;
    if(x + y > 10)
        cout << "Thanks for choosing large numbers!" << endl;
    return 0;
}
