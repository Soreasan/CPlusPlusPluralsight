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