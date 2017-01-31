/*
Kenneth Adair
Following along with Pluralsight courses.
Taken from C++11 Language Features course
Another demo of lambdas.   
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //binding a lambda to a variable to use later
    auto f =    [](int i) -> double
                {
                    if(i > 10) 
                        return 0.0; 
                    return double(i);
                };

    for(int i = 5; i < 15; i++)
        cout << f(i) << endl;
    return 0;
}
