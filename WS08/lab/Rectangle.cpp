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
#include "Rectangle.h"
using namespace std;
namespace sdds {
	//Sets the width and height member variables to zero
	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}
	// Passes the Cstring to the constructor of the base class and sets the m_width and m_height member variables to the corresponding values
	Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label) {
		int _width = strlen(LblShape::label()) + 2;
		if (width > _width && height > 3)
		{
			m_width = width;
			m_height = height;
		}
		else
		{
			m_width = 0;
			m_height = 0;
		}
	}
	//Reads comma-separated specs of the Rectangle from istream.
	void Rectangle::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore(1, ',');
		istr >> m_height;
		istr.ignore(1000, '\n');
	}
	//This function overrides the draw function of the base class.
	void Rectangle::draw(ostream& ostr)const {
		if (m_width > 0 && m_height > 0) {
			ostr << '+';
			ostr.width(m_width - 2);
			ostr.fill('-');
			ostr << '-' << '+' << endl;
			ostr << '|';
			ostr.width(m_width - 2);
			ostr.fill(' ');
			ostr << left << LblShape::label() << '|' << endl;
			int endPoint = (m_height - 3);
			for (int i = 0; i < endPoint; i++)
			{
				ostr << '|';
				ostr.width(m_width - 2);
				ostr.fill(' ');
				ostr << ' ' << '|' << endl;
			}
			ostr << '+';
			ostr.width(m_width - 2);
			ostr.fill('-');
			ostr << '-' << '+';
		}
	}
}