/*
Kenneth Adair
Following a long with C++ Fundamentals - Part 2 course on Pluralsight.  
This demos Lambda expressions that return stuff
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
        v.push_back(i);
    vector<int> v2;
    //If the return type is obvious the lamdba will just know
    transform(v.begin(), v.end(), back_inserter(v2), [](int n){ return n * n * n;});
    for_each(v2.begin(), v2.end(), [](int n){ cout << n << " "; });
    cout << endl;
    cout << endl << "--------------------" << endl;
    vector<double> dv;
    //you can indicate a return type with lambdas using -> [return type]
    transform(v.begin(), v.end(), back_inserter(dv), [](int n) -> double{
        if(n % 2 == 0){
            return n * n * n;
        }else{
            return n / 2.0;
        }
    });
    return 0;
}
