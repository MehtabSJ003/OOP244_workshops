/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 18 / 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& ostr)const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual ~Shape() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& rhs);
	std::istream& operator>>(std::istream& istr, Shape& rhs);
}
#endif