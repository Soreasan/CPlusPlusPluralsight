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

string Person::GetName()
{
	return firstname + " " + lastname;
}