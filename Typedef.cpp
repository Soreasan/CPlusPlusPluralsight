/*
Kenneth Adair
Following a long with Pluralsight's C++ Fundamentals course.
This demos legacy code and specifically typedef. 
*/

#include <iostream>
//#include <typedef>
using namespace std;

typedef unsigned long DWORD;

typedef struct tagKPoint
{
    int x, y;
} KPoint;

int main()
{
    int i1 = 7;
    long l1 = 3L;
    DWORD d1 = 13;
    //d1 = "hello";
    cout << i1 << " " << l1 << " " << d1 << endl;
    KPoint p;
    p.x = 2;
    p.y = 3;
    int i2 = i1;
    int i3 = (int) l1;
    int i4 = 5;



    return 0;
}
