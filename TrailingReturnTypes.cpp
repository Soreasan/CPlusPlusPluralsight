/*
Kenneth Adair
Following along with C++11 Language Features course on Pluralsight
This is a demo of trailing return types using auto and decltypes
*/

#include <iostream>
using namespace std;

//Trailing return types allows you to declare a return type based on the types of the argument
template<typename X, typename Y>
auto multiply(X x, Y y) -> decltype(x * y)
{
    return x * y;
}

int main()
{
    cout << multiply(1.5, 255) << endl;
    return 0;
}
