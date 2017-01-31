/*
Kenneth Adair
Following along with Pluralsight course.
This is a basic demo of lambdas which let you put functions where ever you want.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    for(int i = 0; i < 10; ++i)
        numbers.push_back(i * i);
    // lambdas let you put functions down here
    // syntax looks like this: []([datatype] varName){//do stuff});
    for_each(numbers.begin(), numbers.end(), [](const int &i){cout << i << endl;});
    return 0;
}
