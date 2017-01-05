/*
Kenneth Adair
Function demos taken from C++ Fundamentals course on Pluralsight.
*/

#include <iostream>
using namespace std;

//Basic Function
bool IsPrime(int x)
{
    bool prime = true;
    for(int i = 1; i <= x/i; i++)
    {
        int factor = x/i;
        if(factor * factor == x)
        {
            prime = false;
            break;
        }
    }
    return prime;
}

/* By putting int& we pass a reference which is useful 
if we want to change the data or if making a copy is
expensive to do.  Great for sorting and stuff */
bool IsPrimeByReference(int& x)
{
    return IsPrime(x);
}
/* 
If we return by reference but use a local variable it
goes out of scope and ceases to exist so our reference
points to a variable that no longer exists.  Don't do it.
*/
int& DanglingReference()
{
    int a = 3;
    return a;
}

int main()
{
    int x;
    cout << "Enter a number" << endl;
    cin >> x;
    if(IsPrime(x))
        cout << x << " is prime." << endl;
    else
        cout << x << " is not prime." << endl;
    return 0;
}
