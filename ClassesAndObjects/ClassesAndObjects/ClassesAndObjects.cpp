// ClassesAndObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include "Tweeter.h"
#include "status.h"
#include <iostream>

using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	Person p1("Kate", "Gregory", 123);
	{
		Tweeter p2("Someone", "Else", 456, "@whoever");
	}
	cout<< "after innermost block" << endl;
	Status s = Pending;
	s = Approved;
	return 0;
}

