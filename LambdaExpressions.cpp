/*
Kenneth Adair
Following along with C++11 Language Features by Alex Korban on Pluralsight
*/

#include <iostream>
using namespace std;

int main()
{
    typedef int (*Func)();
    Func f = []{return 10;};
    auto test = f();    //Invoke lambda via funtion pointer
    cout << test << endl;
    
    //Recursion lambda
    function<int(int)> fibonacci = [&](int n) -> int
    {
        if(n < 1)
            return -1;
        else if(n == 1 || n == 2)
            return 1;
        else
            return fibonacci(n - 1) + fibonacci(n - 2);
    };
    auto num = fibonacci(10);
    cout << num << endl;
    return 0;
}
