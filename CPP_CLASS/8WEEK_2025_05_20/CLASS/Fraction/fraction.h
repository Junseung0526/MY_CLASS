#pragma once

#include <iostream>
using namespace std;
//#ifndet FRACTION_H
#define FRACTION_H

class Fraction
{

private:
	int numer;
	int denom;

public:

	Fraction(int num, int den);
	Fraction();
	Fraction(const Fraction& ftact);
	~Fraction();

	int getNumer() const;
	int getDenom() const;
	void print() const;

	void setNumer(int num);
	void setDenom(int den);

private:
	void normalize();
	int gcd(int n, int m);
};
//#endif