/*  Kenneth Adair
*   Following a long with Pluralsight c++ course, 
*   This demos easy memory management.
*   Memory leaks happen when you don't delete things.
*   These are examples of a robust class with no memory leaks and it won't blow up when used.
*   To compile this you have to use the following command or it won't work:
*   c++ -std=c++11  EasyMemoryManagement.cpp
*/

#include <iostream>
#include <memory>
using namespace std;

class Resource
{
private:
    string name;
public:
    Resource(string n):name(n){
        cout << "constructing " << name << endl;
    }

    ~Resource(void){
        cout << "destructing " << name << endl;
    }
    
    string GetName() const {
        return name;
    }
};

class Person
{
private:
    string firstname;
    string lastname;
    int arbitrarynumber;
    shared_ptr<Resource> pResource;

public:
    Person(string first, string last, 
        int arbitrary) : firstname(first), lastname(last), 
        arbitrarynumber(arbitrary)
    {
    }

    string GetName() const
    {
        return firstname + " " + lastname;
    }
    int GetNumber() const
    {
        return arbitrarynumber;
    }
    
    void setNumber(int number)
    {
        arbitrarynumber = number;
    }
    
    void SetFirstName(string first)
    {
        firstname = first;
    }

    bool operator<(Person& p)
    {
        return arbitrarynumber < p.arbitrarynumber;
    }

    bool operator<(int i)
    {
        return arbitrarynumber < i;
    }

    friend bool operator<(int i, Person& p)
    {
        return i < p.arbitrarynumber;
    }

    void AddResource()
    {
        //Adding this line so if they create a new resource without deleting the old one we'll delete it and avoid a memory leak.
        pResource.reset();
        //Updates the resource with the smart pointers.
        pResource = make_shared<Resource>("Resource for " + GetName());
        auto t = make_shared<int>(10);
    }
    //Demos that smart pointers work like normal pointers, overloaded and stuff
    string GetResourceName() const
    {
        return pResource->GetName();
    }
};

int main()
{
    {
        Resource localResource("local");
        string localString = localResource.GetName();
    }
    Resource* pResource = new Resource("Created with new");
    string newString = pResource->GetName();
    Resource* p2 = pResource;
    string string2 = p2->GetName(); 
    delete pResource;   //bad
    //string string3 = pResource->GetName();  //bad, causes a crash
    //pResource = nullptr;    //bad
    //delete pResource;   //Bad because we deleted it earlier
    //delete p2;  //bad, causes a crash b/c deleting memory already deleted

    Person Kate("Kate", "Gregory", 345);
    Kate.AddResource();
    Kate.SetFirstName("Kate2");
    Kate.AddResource();     //Requires us to delete the old resource or we have memory leaks.
    Person Kate2 = Kate;    //Requires us to build a constructor that uses a &Person
    Kate = Kate2;           //Requires us to overload the assignment operator or it will crash
    string s1 = Kate.GetResourceName(); //Demos that smart pointers work like normal pointers.
    return 0;
}
