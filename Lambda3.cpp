/*
Kenneth Adair
Following along with Pluralsight courses.
C++11 Language and Features
Lambda storage demo
*/
#include <iostream>
#include <functional>
using namespace std;

class LambdaStore
{
    //This lambda takes doubles and returns booleans
    function<bool(double)> _stored_lambda;
public:
    function<int(int)> get_abs() const
    {
        return [](int i){ return abs(i); };
    }

    void set_lambda(const function<bool(double)>& lambda)
    {
        _stored_lambda = lambda;
    }
};

int main()
{
    //Funny variable name
    auto bots = -10;
    LambdaStore ls;
    //Setting the _stored_lambda function to this
    ls.set_lambda([](double d){ return d > 0.0; });
    auto matic = ls.get_abs();
    auto mobile = matic(bots);    //returns 10
    cout << mobile << endl;
    return 0;
}
