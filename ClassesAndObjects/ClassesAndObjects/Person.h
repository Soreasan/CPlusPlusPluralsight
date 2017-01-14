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
	std::string GetName() const;
	int GetNumber() const { return arbitrarynumber; }
	void setNumber(int number) { arbitrarynumber = number; }
	bool operator<(Person& p) const;
	bool operator<(int i) const;
	friend bool operator<(int i, const Person& p);	//Friend keyword makes this exception to public/private rules
};
bool operator<(int i, const Person& p);
#endif