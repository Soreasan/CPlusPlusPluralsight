/*
Kenneth Adair
A simple example demonstrating Strings.
Taken from "Learn How to Program with C++" on Pluralsight
by Kate Gregory
*/

#include <iostream>
#include <string>

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
    return 0;
}
