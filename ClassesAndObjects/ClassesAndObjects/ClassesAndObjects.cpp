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

int DoubleIt(const int& x)
{
	return x * 2;
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

	/***************** Template Specialization demo ***************/
	//Person start("", "", 0);
	Accum<Person> people(0);
	Person p7("Kate", "Gregory", 123);
	Person p8("Someone", "Else", 456);
	people += p7;
	people += p8;
	cout << people.GetTotal() << endl;
	/**************************************************************/

	/************************ Pointers demo ***********************/
	int a = 3;
	cout << "a is " << a << endl;
	int* pA = &a;
	*pA = 4;
	cout << "a is " << a << endl;
	int b = 100;
	pA = &b;
	(*pA)++;
	cout << "a " << a << ", *pA " << *pA << endl;

	Person Kate("Kate", "Gregory", 234);
	Person* pKate = &Kate;
	(*pKate).setNumber(235);
	cout << "Kate: " << Kate.GetName() << " " << Kate.GetNumber() << endl;
	cout << "pKate: " << pKate->GetName() << " " << pKate->GetNumber() << endl;

	int & rA = a;
	rA = 5;
	cout << "a is " << a << endl;

	Person& rKate = Kate;
	rKate.setNumber(345);
	cout << "rKate: " << rKate.GetName() << " " << rKate.GetNumber() << endl;

	//Bad pointer error handling
	int* badPointer = nullptr;	//If we don't set the pointer to nullptr we can't do error handling
	if (badPointer)
	{
		*badPointer = 3;
		cout << *badPointer << endl;
	}

	/**************************************************************/
	
	/**********************Const keyword demo**********************/
	int i = 3;
	const int ci = 3;
	i = 4;
	//ci = 4;	//Can't do this because const prevents us from changing it

	int j = 10;
	int DoubleJ = DoubleIt(j);
	int DoubleTen = DoubleIt(10);

	Person Kate("Kate", "Gregory", 234);
	Kate.setNumber(235);
	const Person cKate = Kate;
	//cKate.setNumber(236);
	int KateNumber = cKate.GetNumber();
	/**************************************************************/
	
	return 0;
}

