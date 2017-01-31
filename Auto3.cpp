/*
Kenneth Adair
Following along with Pluralsight's C++11 Language Features by Alex Korban.
Loosely based on sample code from the videos.  
*/

#include <iostream>
using namespace std;

template<typename X, typename Y>
void do_magic(const X& x, const Y& y)
{
    auto result = x * y;
    cout << result << endl;
}

int main()
{
    int x = 15;
    float y = 3.5;
    cout << "x is an int which is " << x << " and y is a float which is " << y << "." << endl;
    cout << "We will multiply them and see what we get: " << endl;
    do_magic(x, y);
    return 0;
}
