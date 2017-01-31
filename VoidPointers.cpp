/*
Kenneth Adair
This is a demo of void pointers which occasionally pop up in legacy code.
Following along with C++ Fundamentals - Part 2 course on Pluralsight
*/

#include <iostream>
using namespace std;

void UseSomething(void* something)
{
    //cout << *something << endl;
    int* s = (int*) something;
    cout << *s << endl;
}

int main()
{
    int i1 = 10;
    int p = 15;
    UseSomething(&i1);
    UseSomething(&p);
    return 0;
}
