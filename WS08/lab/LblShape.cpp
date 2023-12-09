/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 18 / 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	// returns the unmodifiable value of m_label member variable
	const char* LblShape::label()const {
		return m_label;
	}
	//Sets the label pointer to null
	LblShape::LblShape() {
		m_label = nullptr;
	}
	//Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable. Then copies the Cstring argument to the newly allocated memory
	LblShape::LblShape(const char* label):m_label(nullptr) {
		if (label)
		{
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}
	//Deletes the memory pointed by m_label member variable.
	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}
	//Reads a comma-delimited Cstring form istream
	void LblShape::getSpecs(std::istream& istr) {
		char label[100+1];
		istr.getline(label, 100, ',');
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
}