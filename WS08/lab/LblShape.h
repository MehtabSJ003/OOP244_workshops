/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 18 / 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
#include <iostream>
namespace sdds {
	class LblShape :public Shape {
		char* m_label;
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		virtual ~LblShape();
		LblShape(const LblShape& src) = delete;
		LblShape& operator=(const LblShape& src) = delete;
		void getSpecs(std::istream& istr);
	};
}
#endif