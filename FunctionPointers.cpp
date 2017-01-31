/*
Kenneth Adair
Following a long with C++ Fundamentals - Part 2 course on Pluralsight.
Demo of Function pointers which sometimes show up in legacy code.  
Function Pointers are Pointers that point to functions.
*/

#include <iostream>
using namespace std;

int doubler(int i)
{ 
    return i * 2; 
}

int tripler(int i)
{ 
    return i * 3; 
}

typedef int (*CHANGER)(int i);

int Change(int i)
{
    CHANGER f;
    if(i > 5)
        f = tripler;
    else
        f = doubler;
    return f(i);
}

int main()
{
    int i1 = 7;
    long l1 = 3L;
    int i2 = Change(i1);
    int i3 = Change((int) l1);
    cout << i2 << " " << i3 << endl;
    return 0;
}
