/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 11/ 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"
namespace sdds {
	class Pack :public Container {
		int m_unitSize;
	public:
		Pack(const char* description, int size, int unitSize = 330, int numberOfUnits = 0);
		//Shadows the operator+= of the Base class
		int operator+=(int value);
		//Shadows the operator-= of the Base class
		int operator-=(int value);
		//returns the unit size attribute
		int unit()const;
		//returns the content volume of the Base class divided by the unit size
		int noOfUnits()const;
		//return the capacity of the base class divided by the unit size
		int size()const;
		//Overloads the clear function of the Base class
		void clear(int packSize, int unitSize, const char* description);
		//Shadows the print of the Base class
		std::ostream& print(std::ostream& ostr)const;
		//Shadows the read of the Base class
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, Pack& rhs);
	std::istream& operator>>(std::istream& istr, Pack& rhs);
}
#endif