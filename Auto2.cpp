/*
Kenneth Adair
Following along with Pluralsight course "C++11 Language Features" by Alex Korban
This demos the auto keyword.  
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    auto size = 10;
    vector<int> numbers;
    //Fill the vector with numbers
    for(auto i = 0; i < size; ++i)
        numbers.push_back(i);
    //iterate through the vector
    for(auto i = numbers.begin(); i != numbers.end(); ++i)
        cout << numbers[*i] << endl;
    return 0;
}
