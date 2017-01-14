#include "stdafx.h"
#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(string first, string last, 
	int arbitrary) : firstname(first), lastname(last), 
	arbitrarynumber(arbitrary)
{
	cout << "constructing " << GetName() << endl;
}

Person::~Person() 
{
	cout << "destructing " << GetName() << endl;
}

string Person::GetName() const
{
	return firstname + " " + lastname;
}

bool Person::operator<(Person& p) const
{
	return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator<(int i) const
{
	return arbitrarynumber < i;
}

bool operator<(int i, const Person& p)
{
	return i < p.arbitrarynumber;	//friend keyword let's us access private variables
}