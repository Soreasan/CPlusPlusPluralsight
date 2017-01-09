/*
Kenneth Adair
Following a long with C++ Fundamentals course on Pluralsight.
This demos various operators.
*/

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> primes;

/* A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself  */
bool IsPrime(int num, vector<int> &primes){
    if(primes.size() == 0)
        primes.push_back(2);
    for(int i : primes)
        if(num % i == 0 || num < i) return false;
    for(int i = primes.back(); i < (int) sqrt( (double) num) + 1; i++)
        if(num % i == 0) return false;
    primes.push_back(num);
    return true;
}

int main(){
    int i = 0;
    cout << "i " << i << endl;
    i += 2;
    cout << "i " << i << endl;
    i *= 3;
    cout << "i " << i << endl;
    i -= 2;
    cout << "i " << i << endl;
    i /= 4;
    cout << "i " << i << endl;

    int j = i++;
    cout << "i " << i << ", j " << j << endl;
    j = ++i;
    cout << "i " << i << ", j " << j << endl;
    j = i--;
    cout << "i " << i << ", j " << j << endl;
    j = --i;
    cout << "i " << i << ", j " << j << endl;

    i = 2;
    while(i < 101)
        IsPrime(i++, primes);
    cout << "I found " << primes.size() << " primes up to 100" << endl;
    return 0;
}
