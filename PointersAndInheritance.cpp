/*
 *  Kenneth Adair
 *  This demos pointers and inheritance
 */

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string firstname;
    string lastname;
    int arbitrarynumber;
public:
    Person(string first, string last, 
        int arbitrary) : firstname(first), lastname(last),
        arbitrarynumber(arbitrary)
    {
    }

    virtual ~Person()
    {
    }

    //Virtual keyword means "Call the inheritor's method instead if you can"
    virtual string GetName() const
    {
        return firstname + " " + lastname;
    }
    
    int GetNumber() const 
    { 
        return arbitrarynumber; 
    }
    
    void SetNumber(int number) 
    { 
        arbitrarynumber = number; 
    }

    void SetFirstName(string first)
    { 
        firstname = first; 
    }
};

class Tweeter : public Person
{
private:
    string twitterhandle;
public:
    Tweeter(string first, 
        string last, 
        int arbitrary, 
        string handle): Person(first, last, arbitrary), twitterhandle(handle)
    {
    }
    
    ~Tweeter(void)
    {
    }

    string GetName() const
    {
        return Person::GetName() + " " + twitterhandle;
    }
};

int main()
{
    Person* Kate = new Person("Kate", "Gregory", 456);
    Tweeter* KateGregcons = new Tweeter("Kate", "Gregory", 567, "@gregcons");
    Person* pKateGregcons = KateGregcons;
    cout << Kate->GetName() << endl;
    cout << KateGregcons->GetName() << endl;
    cout << pKateGregcons->GetName() << endl;
    delete KateGregcons;
    return 0;
}
