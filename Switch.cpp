/*
Kenneth Adair
Following a long with C++ Fundamentals course.
This program demonstrates SWITCH statements.
*/

#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter a number, 0 to quit" << endl;
    cin >> x;
    while(x>0)
    {
        switch(x)
        {
            case 1:
                cout << "You entered 1" << endl;
                break;
            case 2:
            case 3:
                cout << "You entered 2 or 3" << endl;
                break;
            case 4:
                //there should be a break after the text but there isn't for demo purposes.
                cout << "You entered 4" << endl;
            case 5:
                cout << "You entered 5" << endl;
                break;
            default:
                cout << "You entered other than 1-5" << endl;
        }
    cout << "Enter a number, 0 to quit" << endl;
    cin >> x;
    }
}
