/*
Kenneth Adair
Following along with C++ Language Features course on Pluralsight
Demo of Capturing
*/

#include <iostream>
using namespace std;

function<bool()> g()
{
    static auto a = 5;
    static auto b = -3;
    return [](){ return a + b > 0; };
}

function<bool()> f()
{
    auto a = 5;
    auto b = -3;
    // won't compile if a & b aren't captured.
    return [a, b](){return a + b > 0; };
}
/* This won't compile because a and b aren't captured.
function<bool()> nope()
{
    auto a = 5;
    auto b = -3;
    return [](){return a + b > 0; };
}
*/

int main()
{
    auto test = f;
    cout << test << endl;

    int a, b, c, d;
    a = b = c = d = 5;
    //Capture everything by value
    [=](){ return (a > b) && (c < d); };
    //Capture everything by reference
    [&](){ a = b = c = d = 10; }
    //override default capture by value
    [=, &a](){a = 20;};;
    //override default capture by reference
    [&, d](){auto varName = d;};  

    return 0;
}
