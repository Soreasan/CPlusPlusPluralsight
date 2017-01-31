/*
Kenneth Adair
Following along with Pluralsight's C++ Fundamentals - Part 2 on Pluralsight
This is a demo of C style strings.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    char* s1 = "Hello";
    int i = strlen(s1);
    //Added +1 for the null terminator '\0'
    char* s2 = new char[strlen(s1) + strlen(" Kate") + 1];
    strcpy(s2, s1);
    strcat(s2, " Kate");
    //Have to manually add a null terminator or it will search memory for it
    char hello[] = {' ', 'w', 'o', 'r', 'l', 'd', '\0'};
    int j = strlen(hello);
    //If we do this the compiler automatically adds the null terminator itself
    char better[] = "better";
    int k = strlen(better);

    //How to build a c++ string from a c style string
    string s(s1);
    //Can easily concatenate to a c++ string
    s += " modern C++";
    //How to build a C string from a C++ string, first create a char array of right length
    char* s3 = new char[s.length() + 1];
    
    //These don't  work
    //s3 = s;
    //s3 = s.c_str();

    //Next is to move the string into the character array
    strcpy(s3, s.c_str());

    //avoid memory leaks by deleting the stuff we created with the NEW keyword
    delete[] s2;
    delete[] s3;
    
    return 0;
}
