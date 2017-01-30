/*
Kenneth Adair
Following a long with C++ Fundamentals Part 2 on Pluralsight
This demos "capturing" or getting data for lambda function things.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
        v.push_back(i);

    //Capturing by value explicitly [x, y]
    int x = 3;
    int y = 7;
    cout << "printing elements between " << x << " and " << y << " inclusive" << endl;
    for_each(v.begin(), v.end(), [x, y](int n)
            {
                if(n >= x && n <= y)
                    cout << n << " ";
            });
    cout << endl;
    for_each(v.begin(), v.end(), [](int n){ cout << n << " ";  });
    cout << endl;
    
    //Capturing by value implicitly [=]
    x = 2;
    y = 9;
    cout << "printing elements between " << x << " and " << y << " inclusive" << endl;
    for_each(v.begin(), v.end(), [=](int n)
        {
            if(n >= x && n <= y)
                cout << n << " ";
        });
    cout << endl;
    for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
    cout << endl;
    cout << endl << "-------------------------------" << endl;

    //capturing by value and changing locally [=]
    x = 1;
    y = 1;
    for_each(v.begin(), v.end(), [=](int& r) mutable {
        //lambdas only change their own local copies of the variables of x and y
        //Although the vector variables will be changed since we passed by reference
        const int old = r;
        r*= 2;
        x = y;
        y = old;
    });
    
    cout << "doubling " << endl;
    for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
    cout << endl;
    cout << "x, y: " << x << ", " << y << endl;
    cout << endl << "----------------------------" << endl;
    
    //Capturing by reference [&x, &y] - also changing the param (int&)
    v.clear();
    for(int i = 0; i < 10; ++i){v.push_back(i);}
    for_each(v.begin(), v.end(), [&x, &y](int& r){
        const int old = r;
        r *= 2;
        x = y;
        y = old;
    });

    for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
    cout << endl;

    //Capturing whole stack by reference (and a neater way to keep initialization)
    v.clear();
    int i = 0;
    generate_n(back_inserter(v), 10, [&] { return i++; }); 
    cout << "initializing" << endl;
    for_each(v.begin(), v.end(), [](int n){ cout << n << " "; });
    cout << endl;
    cout << "i: " << i << endl;
    cout << endl << "---------------------------------" << endl;

    return 0;
}
