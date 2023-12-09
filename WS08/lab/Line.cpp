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
#include <cstring>
#include "Line.h"
using namespace std;
namespace sdds {
	//Sets the m_length member variable to zero
	Line::Line() {
		m_length = 0;
	}
	//Passes the Cstring to the constructor of the base class and sets the m_length member variable to the value of the second argument.
	Line::Line(const char* label, int length):LblShape(label) {
		m_length = length;
	}
	//Reads comma-separated specs of the Line from istream
	void Line::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}
	//This function overrides the draw function of the base class.
	void Line::draw(std::ostream& ostr)const {
		if (m_length > 0 && LblShape::label())
		{
			ostr << LblShape::label() << endl;
			ostr.width(m_length);
			ostr.fill('=');
			ostr << '=';
		}
	}
}