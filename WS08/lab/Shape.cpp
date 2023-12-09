/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 18 / 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
	//Overloading the insertion operator using draw so that any shape object can be written
	ostream& operator<<(ostream& ostr, const Shape& rhs) {
		rhs.draw(ostr);
		return ostr;
	}
	//Overloading the extraction operator using getSpecs so that any shape object can be read
	istream& operator>>(istream& istr, Shape& rhs) {
		rhs.getSpecs(istr);
		return istr;
	}
}