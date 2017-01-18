/*
 *  Kenneth Adair
 *  This demos pointers and inheritance
 *  To compile type:
 *  c++ -std=c++11 [filename]
 *  The #include <memory> requires c++ 11
 */

#include <iostream>
#include <string>
#include <memory>
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
    
    //Demos how Shared Pointers / Smart Pointers work with polymorphism
    auto spKate = make_shared<Tweeter>("SKate", "KGregory", 456, "@gregcons");
    cout << spKate->GetName() << endl;

    //Slicing [losing information when converting to a different clas] demo
    Person localP("Local", "Person", 333);
    //Tweeter localT = localP;  Can't do this, can't convert a person to a tweeter

    Tweeter localT2("Local", "Tweeter", 444, "@local");
    //Slicing occurs here, we lose @local handle
    Person localP2 = localT2;
    cout << localP2.GetName() << endl;

    //Can get around it by doing this
    Person* localP3 = &localT2;
    cout << localP3->GetName() << endl;

    //Best way is to just change it to a person reference, references are polymorphic
    Person& localP4 = localT2;
    cout << localP4.GetName() << endl;
    
    //Casting demo
    Tweeter t("Kate", "Gregory", 123, "@gregcons");
    Person* p = &t;
    //Tweeter* pt = p;    //Doesn't work, compiler error
    Tweeter* pt = (Tweeter*) p; // C style cast, works in this specific case but not ideal
    cout << pt->GetName() << endl;

    //Demo of casting screwing us up, this gets past compiler error checks but crashes
    /*
    int i = 3;
    Tweeter *pi = (Tweeter*) &i;    //Means "Just trust me, this int is actually a Tweeter"
    cout << pi->GetName() << endl;
    */

    //static_cast<> demo, this one is better than C style cast because compiler can catch stuff
    Tweeter* pi = static_cast<Tweeter*>(p);
    cout << pi->GetName() << endl;

    //this one doesn't work but static_cast catches it for us, won't compile
    /*
    int i = 3;
    Tweeter* pi2 = static_cast<Tweeter*>(&i);
    cout << pi2->GetName() << endl;
    */

    //We can try to use dynamic_cast which won't be caught by compiler but gives us null pointers when it fails
    /*
    int i = 3;
    Tweeter* pi = dynamic_cast<Tweeter*>(&i);
    if(pi)  //Check if it's null
    {
        cout << pi->GetName() << endl;
    }
    else
    {
        cout << "Resource can't be cast to tweeter" << endl;
    }
    */
    return 0;
}
