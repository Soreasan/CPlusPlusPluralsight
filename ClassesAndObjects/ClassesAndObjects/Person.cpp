#include "stdafx.h"
#include "Person.h"
#include <iostream>

Person::Person(std::string first, std::string last, 
	int arbitrary) : firstname(first), lastname(last), 
	arbitrarynumber(arbitrary)
{
	std::cout << "constructing " << firstname << " " << lastname << std::endl;
}

Person::~Person() 
{
	std::cout << "destructing " << firstname << " " << lastname << std::endl;
}