/*
Kenneth Adair
Following along with Pluralsight's C++ Fundamentals - Part 2 course
This is a demo of C-style arrays
*/

#include <iostream>
using namespace std;

int main()
{
    int ints[3];
    //Accessing the array using indexes
    ints[0] = 0;
    ints[1] = 1;
    //Accessing the array using pointers.
    *(ints+2)=2;
    //*(ints+3)=3;  //Will cause program to crash, won't get compilation error

    //Can initialize an array from the get-go
    float floats[] = {1.0, 2.0, 3.0};

    //Can allocate the array on the new store
    int* aI = new int[4];
    //Square bracket notation
    aI[0] = 4;
    aI[1] = 3;
    aI[2] = 2;
    //Pointer arithmetic
    *(aI + 3) = 1;

    //Can loop through a c style array
    for(int i = 0; i < 4; i++)
        aI[i] = i;

    //A trick to get the # of array indexes, divide size in bytes of array by size of bytes of the first index.
    int localsize = sizeof(ints)/sizeof(ints[0]);
    int freestore = sizeof(aI)/sizeof(aI[0]);

    //Free up memory on free store to avoid memory leaks
    delete[] aI;

    // 2d c style array
    int matrix[2][3];
    matrix[0][0] = 1;
    matrix[0][1] = 2;

    return 0;
}
