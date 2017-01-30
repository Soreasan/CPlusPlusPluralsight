/*
Kenneth Adair
Following a long with Pluralsight course C++ Fundamentals - Part 2
Simple lambda demo
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i< 10; ++i)
        v.push_back(i);

    for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
    cout << endl;
    cout << endl << "----------------------------" << endl;
    for_each(v.begin(), 
             v.end(), 
             [](int n)
                {
                    cout << n << " ";
                }
             );
    cout << endl;
    cout << endl << "----------------------------" << endl;

    for_each(v.begin(), v.end(), [](int n){
        cout << n;
        if(n % 2 == 0){
            cout << " even " << endl;
        }else{
            cout << " odd " << endl;
        }
    });

    cout << endl << "--------------------------" << endl;
}
