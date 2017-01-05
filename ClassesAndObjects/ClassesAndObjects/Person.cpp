#include "stdafx.h"
#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(string first, string last, 
	int arbitrary) : firstname(first), lastname(last), 
	arbitrarynumber(arbitrary)
{
	cout << "constructing " << firstname << " " << lastname << endl;
}

Person::~Person() 
{
	cout << "destructing " << firstname << " " << lastname << endl;
}