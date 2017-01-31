/*
Kenneth Adair
Another demo of auto.
Based on code from C++11 Language and Features course by Alex Korban
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class JetPlane{
private:
    string model;
public:
    JetPlane():model("death star"){};
    ~JetPlane(){};
    void changeName(string newModel){ model = newModel; }
};

int func(double){ return 10; }

struct Expl
{
    Expl(){}
    explicit Expl(const Expl&){}
};

int main()
{
    auto a = 5.0, b = 10.0;
    auto i = 1.0, *ptr = &a, &ref = b;
    //auto j = 10, str = "error";   //compile error

    map<string, int> index;

    auto& ref2 = index;
    auto* ptr2 = &index;
    const auto j = index;
    const auto& cref = index;

    const vector<int> values;
    auto a2 = values;    // type of a2 is vector<int>
    auto& b2 = values;   // type of b2 is const vector<int>&

    volatile long clock = 0;
    auto c = clock;     // c is not volatile

    JetPlane fleet[10];
    auto e = fleet;     // type of e is JetPlane*
    auto& f = fleet;    // type of f is JetPlane(&)[10] - a reference

    // auto can even point to a function
    // int func(double){ return 10; }
    auto g = func;      // type of g is int(*)(double)
    auto& h = func;     // type of h is int(&)(double)

    // There are many ways to initialize variables with auto
    int i2 = 10;
    auto q = i;
    auto z(i);

    // However we can only use copy initialization if there's a copy constructor
    Expl e2;
    //auto c2 = e2; //compile error
    return 0;
}
