/*  Kenneth Adair
*   Following a long with Pluralsight c++ course, 
*   This demos Manual memory management.
*   Memory leaks happen when you don't delete things.
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
    //delete pResource;   
    //delete p2;  //bad, causes a crash b/c deleting memory already deleted

    return 0;
}
