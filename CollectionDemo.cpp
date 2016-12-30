/*
Kenneth Adair
This example is taken from the Pluralsight course
"Learn How to Program with C++" by Kate Gregory.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //for sort and count

using namespace std;

int main()
{
    vector<int> vi;
    for(int i = 0; i < 10; i++)
        vi.push_back(i);
    for(auto item:vi)
        cout << item << " ";
    cout << endl;

    vector<string> vs;

    cout << "Enter three words ";
    for(int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        vs.push_back(s);
    }

    for(auto item:vs)
        cout << item << " ";
    cout << endl;

    cout << "int vector vi has " << vi.size() << " elements." << endl;

    vi[5] = 3;
    vi[6] = -1;

    //for each loop thingy
    for(auto item:vi)
        cout << item << " ";
    cout << endl;

    //pretty standard for loop approach
    for(unsigned int i = 0; i < vi.size(); i++)
        cout << vi[i] << " ";
    cout << endl;

    //Iterator approach
    for(auto i = begin(vi); i != end(vi); i++)
        cout << *i << " ";
    cout << endl;

    sort(begin(vs), end(vs));
    for(auto item:vs)
    {
        cout << item << " ";
    }
    cout << endl;

    int threes = count(begin(vi), end(vi), 3);
    cout << "vector of ints has " << threes << " elements with value 3" << endl;

    int tees = count(begin(vs[0]), end(vs[0]), 't');
    cout << "first word has " << tees << " letter t's" << endl;

    return 0;
}
