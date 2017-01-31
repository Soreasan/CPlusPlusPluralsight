/*
Kenneth Adair
Following along with C++11 Language Features course on Pluralsight.
*/
#include <iostream>
#include <vector>
using namespace std;

template<typename X, typename Y>
auto multiply(X x, Y y) -> decltype(x * y)
{
    return x * y;
}

class A
{
private:
    A();
};

int main()
{
    int i = 10;
    // decltype is like a more versatile version of auto that can be used for more than just variables
    cout << typeid(decltype(i + 1.0)).name() << endl;   //outputs "double"
    
    vector<int> a;
    decltype(a) b;
    b.push_back(10);
    decltype(a)::iterator iter = a.end();

    //cout << typeid(decltype(A())).name() << endl;   //doesn't compile, A() is private

    //declval is meant for situations like this
    cout << typeid(decltype(declval<A>())).name() << endl;  //works
    return 0;
}
