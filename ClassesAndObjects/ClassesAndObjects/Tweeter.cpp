#include "stdafx.h"
#include "Tweeter.h"
#include <iostream>

Tweeter::Tweeter(std::string first, 
	std::string last, 
	int arbitrary, 
	std::string handle):Person(first, last, arbitrary), twitterhandle(handle)
{
	std::cout << "constructing tweeter " << twitterhandle << std::endl;
}


Tweeter::~Tweeter()
{
	std::cout << "destructing tweeter " << twitterhandle << std::endl;
}
