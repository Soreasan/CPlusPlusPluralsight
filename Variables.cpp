/*
Kenneth Adair
Variables.cpp is based on an example from the "C++ Fundamentals" class
by Kate Gregory on Pluralsight.
This demonstrates basic variable types.
*/

#include <iostream>
using namespace std;

int main()
{
    int i1 = 1;
    cout << "i1 = " << i1 << endl;
    int i2;
    i2 = 2;
    cout << "i2 = " << i2 << endl;
    int i3(3);
    cout << "i3 = " << i3 << endl;

    double d1 = 2.2;
    double d2 = i1;
    int i4 = d1;
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << i1 << endl;
    cout << "i4 = " << i4 << endl;
    char c1= 'a';
    //char c2 = "b";    //Doesn't work because it's a c style string
    cout << "c1 = " << c1 << endl;
    //cout << "c2 = " << c2 << endl;

    bool flag = false;
    cout << "flag = " << flag << endl;
    flag = i1;
    cout << "flag = " << flag << endl;
    flag = d1;
    cout << "flag = " << flag << endl;

    /*  unsigned char n1 = 128; //Unsigned chars can hold up to 255.
        char n2 = 128;
        cout << "n1 = " << n1 << endl;
        cout << "n2 = " << n2 << endl;
        n1 = 254;
        n2 = 254;
        cout << "n1 = " << n1 << endl;
        cout << "n2 = " << n2 << endl;
        n1 = 300;
        n2 = 300;
        cout << "n1 = " << n1 << endl;
        cout << "n2 = " << n2 << endl;
    */
    return 0;
}
