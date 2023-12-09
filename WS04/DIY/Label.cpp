/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date- 06/10/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>  
#include <cstring>
#include "Label.h"
using namespace std;
namespace sdds {
	Label::Label() {
		//copying the default argument to m_frame upto 8 characters
		strncpy(m_frame, "+-+|+-+|",8);
		m_frame[8] = '\0';
		m_content = nullptr;
	}

	Label::Label(const char* frameArg) {
		//copying the function parameter to 
		strncpy(m_frame, frameArg,8);
		m_frame[8] = '\0';
		m_content = nullptr;
		if (frameArg == nullptr)
		{
			strncpy(m_frame, "+-+|+-+|", 8);
			m_frame[8] = '\0';
		}
	}

	Label::Label(const char* frameArg, const char* content) {
		//copying upto 8 characters
		strncpy(m_frame, frameArg, 8);
		m_frame[8] = '\0';
		//if argument is null pointer then setting m_frame to default value
		if (frameArg == nullptr)
		{
			strncpy(m_frame, "+-+|+-+|", 8);
			m_frame[8] = '\0';
			m_content = nullptr;
		}
		//dynamically allocating m_content
		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);
	}

	Label::~Label() {
		delete[] m_content;
		m_content = nullptr;
	}

	std::istream& Label::readLabel(std::istream& istr) {
		//1 for the null terminator
		char userInput[70+1];
		istr.getline(userInput, 71);
		//dynamically allocating m_content to the size of userInput
		m_content = new char[strlen(userInput) + 1];
		strcpy(m_content, userInput);
		return istr;
	}

	std::ostream& Label::printLabel(std::ostream& ostr) const {
		if (m_content) {
			int len = strlen(m_content);
			ostr << m_frame[0];
			//2 for extra for padding on each side
			for (int i = 0; i < len + 2; i++)
			{
				//prints second character of the frame first
				ostr << m_frame[1];
			}
			ostr << m_frame[2] << endl;
			ostr << m_frame[7] << ' ';
			//sets width of next output field to len+1 characters
			ostr.width(len + 1);
			ostr << ' ' << m_frame[3] << endl;
			ostr << m_frame[7] << ' ' << m_content << ' ' << m_frame[3] << endl;
			ostr << m_frame[7] << ' ';
			ostr.width(len + 1);
			ostr << ' ' << m_frame[3] << endl;
			ostr << m_frame[6];
			for (int i = 0; i < len + 2; i++)
			{
				ostr << m_frame[5];
			}
			ostr << m_frame[4];
		}
		return ostr;
	}

	Label& Label::text(const char* content) {
		m_content = nullptr;
		//dynamically allocating m_content to the parameter argument
		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);
		return *this;
	}
}
