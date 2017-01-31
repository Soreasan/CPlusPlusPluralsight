/*
Kenneth Adair
Demo of pointers to member functions
Occasionally appears in Legacy code
Following along with Pluralsight's C++ Fundamentals - Part 2.
*/

#include <iostream>
using namespace std;

class Utility
{
private:
    int x;
public:
    Utility(int a): x(a){}
    int doublex(){return 2*x;}
    int triplex(){return 3*x;}
};

typedef int (Utility::* UF)();
int ManipulateUtility(int i)
{
    Utility u(i);
    UF action;
    if(i > 3)
        action = &Utility::triplex;
    else
        action = &Utility::doublex;
    return (u.*action)();
}

int main()
{
    int i4 = ManipulateUtility(5);
    cout << i4 << endl;
    return 0;
}
