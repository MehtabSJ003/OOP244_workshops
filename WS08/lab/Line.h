/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 18 / 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
#include <iostream>
namespace sdds{
	class Line :public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		virtual ~Line() {};
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif