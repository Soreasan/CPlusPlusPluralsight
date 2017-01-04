// ClassesAndObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Person.h"
#include "Tweeter.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Person p1("Kate", "Gregory", 123);
	{
		Tweeter p2("Someone", "Else", 456, "@whoever");
	}
	std::cout<< "after innermost block" << std::endl;
	return 0;
}

