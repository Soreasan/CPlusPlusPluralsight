/*
Kenneth Adair
Demo of in-class initializers for non-static data members
*/

#include <iostream>
using namespace std;

class JetPlane
{
private:
    string _manufacturer = "Unknown";
    string _model = "Unknown";
public:
    JetPlane()
    {}
    JetPlane(const string& manufacturer) : _manufacturer(manufacturer)
    {}
};

int main()
{
    return 0;
}
