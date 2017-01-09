#include <string>
//If we've already included the Person class don't include it again.  #ifndef means "If not defined"
#ifndef _Person_H
#define _Person_H
class Person
{
private:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
public:
	Person(std::string first, std::string last, int arbitrary);
	~Person();
	std::string GetName();
	int GetNumber() { return arbitrarynumber; }
	void setNumber(int number) { arbitrarynumber = number; }
	bool operator<(Person& p);
	bool operator<(int i);
	friend bool operator<(int i, Person& p);	//Friend keyword makes this exception to public/private rules
};
bool operator<(int i, Person& p);
#endif