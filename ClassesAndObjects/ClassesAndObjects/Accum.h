#pragma once
template<class T>
class Accum
{
private:
	T total;
public:
	Accum(T start) : total(start) {};
	T operator+=(const T& t) { return total = total + t; };
	T GetTotal() { return total; }
};

//Template Specialization
template<>
class Accum<Person>
{
private:
	int total;
public:
	Accum(int start) : total(start) {};
	int operator+=(Person& t) { return total = total + t.GetNumber(); };
	int GetTotal() { return total; }
};