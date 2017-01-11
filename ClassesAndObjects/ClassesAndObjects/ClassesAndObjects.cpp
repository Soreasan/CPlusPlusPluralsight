// ClassesAndObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include "Tweeter.h"
#include "status.h"
#include "Accum.h"
#include <iostream>

using namespace std;

template<class T>
T max(T t1, T t2)
{
	return t1 < t2 ? t2 : t1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Person p1("Kate", "Gregory", 123);
	{
		Tweeter p2("Someone", "Else", 456, "@whoever");
	}
	cout<< "after innermost block" << endl;
	Status s = Pending;
	s = Approved;
	cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << endl;
	p1.setNumber(124);
	cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << endl;
	/******************** Overloading examples ********************/
	Person p3("Kate", "Gregory", 123);
	Person p4("Someone", "Else", 456);
	cout << "p3 is ";
	if (!(p3 < p4))
		cout << "not ";
	cout << "less than p4" << endl;
	cout << "p1 is ";
	if (!(p1 < 300))
		cout << "not ";
	cout << "less than 300" << endl;

	cout << "300 is ";
	if (!(300 < p1))
		cout << "not " << endl;
	cout << "less than p1" << endl;
	/**************************************************************/
	
	/*********************** Template demo ************************/
	cout << "max of 33 and 44 is " << max(33, 44) << endl;
	string s1 = "hello";
	string s2 = "world";
	cout << "max of " << s1 << " and " << s2 << " is " << max(s1, s2) << endl;
	Person p5("Kate", "Gregory", 123);
	Person p6("Someone", "Else", 456);
	cout << "max of " << p5.GetName() << " and " << p6.GetName() << " is " << (max(p5, p6)).GetName() << endl;
	/**************************************************************/

	/***************** Class Template demo ************************/
	//Initialize a template class
	Accum<int> integers(0);
	integers += 3;
	integers += 7;
	cout << integers.GetTotal() << endl;

	Accum<string> strings("");
	strings += "hello";
	strings += " world";
	cout << strings.GetTotal() << endl;
	/**************************************************************/

	return 0;
}

