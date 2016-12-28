/*
Kenneth Adair
A simple example demonstrating Strings.
Taken from "Learn How to Program with C++" on Pluralsight
by Kate Gregory
*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <typeinfo>

using namespace std;

int main()
{
    string name;
    cout << "Who are you? ";
    cin >> name;
    string greeting = "Hello, " + name;
    if(name == "Kate")
        greeting += ", I know you!";
    cout << greeting << endl;

    int l = greeting.length();
    cout << "\"" + greeting + "\" is " << l << " characters long." << endl;
    int space = greeting.find(' ');
    string beginning = greeting.substr(space + 1);
    cout << beginning << endl;
    if(beginning == name)
    {
        cout << "expected result." << endl;
    }
    return 0;
}
