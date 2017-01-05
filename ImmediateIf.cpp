/*
Kenneth Adair
Following a long with C++ Fundamentals course.
This demonstrates the IMMEDIATE IF concept.
[IF CONDITION] ? [IF TRUE DO THIS] : [ELSE DO THIS];
For example these two are equivalent:

if(1 > 0)
    cout << "true" << endl;
else
    cout << "false" << endl;

1 > 0 ? cout << "true" << endl : cout << "false" << endl;
*/

#include <iostream>
using namespace std;

int main()
{
    int x = 99;
    while(x > 0)
    {
        cout << "Enter a number, 0 to quit." << endl;
        cin >> x;
        string sign = x > 0 ? "positive" : "0 or negative";
        cout << "Your number is " << sign << endl;
    }
    1 > 0 ? cout << "true" << endl : cout << "false" << endl;
    return 0;
}
