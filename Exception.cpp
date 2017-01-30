/*
Kenneth Adair
Following a long with C++ Fundamentals - Part 2 on Pluralsight
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    try
    {
        vector<int> v;
        v.push_back(1);
        //Crashes program
        int j = v.at(99);
        return 0;
    }
    catch(out_of_range& e)
    {
        cout << "Out of range exception " << e.what() << endl;
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }

    int arbitrarynumber = 0;
    if(arbitrarynumber == 0)
    {
        throw invalid_argument("Arbitrary number is 0");
    }
}
