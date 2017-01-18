/*  Kenneth Adair
*   Following a long with Pluralsight c++ course, 
*   This demos Manual memory management.
*   Memory leaks happen when you don't delete things.
*   These are examples of a robust class with no memory leaks and it won't blow up when used.
*/

#include <iostream>
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
    Resource* pResource;

public:
    Person(string first, string last, 
        int arbitrary) : firstname(first), lastname(last), 
        arbitrarynumber(arbitrary), pResource(nullptr)
    {
    }

    /*
        If we create a copy of person it will also have a pointer to the same resource.
        That means when we go out of scope if there are two pointers to the same pResource
        it will try to delete them both which will cause the program to crash.  To avoid
        this we create a seperate constructor when we're copying a Person.  In particular
        it's important to create a copy of the resource instead of just pointing to the
        same resource so when we go to the delete there will be two seperate resources
        for our program to delete.  
    */
    Person(const Person& p): firstname(p.firstname), lastname(p.lastname), 
        arbitrarynumber(p.arbitrarynumber), pResource(new Resource(p.pResource->GetName()))
    {
    }

    Person& operator=(const Person& p)
    {
        firstname = p.firstname;
        lastname = p.lastname;
        arbitrarynumber = p.arbitrarynumber;
        delete pResource;   //If we already have one delete it to avoid memory leaks.  If it's nullptr it's harmless
        pResource = new Resource(p.pResource->GetName());
        return *this;   //A pointer that each member function that represents object itself
    }

    ~Person()
    {
        //Deletes a Resource if it's there, doesn't do anything if it's not there.  Avoid memory leaks
        delete pResource;
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
        delete pResource;
        //the NEW keyword allows this resource to live longer than the scope would usually allow.
        pResource = new Resource("Resource for " + GetName());
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
    return 0;
}
