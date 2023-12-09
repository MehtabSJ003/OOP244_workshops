/*
Name - MEHTAB SINGH JAGDE, HARLEEN SINGH
Student ID - 119003226, 116871229
Email - mjagde@myseneca.ca, hsingh902@myseneca.ca
Section - ZEE
Date - 24 / 11 / 2023

We have completed this assignment ourselves  respecting academic integrity.

*/
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"
class Graduate :public Student {
	char* m_supervisorName;
	char* m_thesisTitle;
public:
	Graduate();
	Graduate(const char* name, int age, const char* thesisTitle, const char* supervisorName);
	Graduate(const Graduate& src);
	Graduate& operator=(const Graduate& src);
	~Graduate();
	void display();
};
#endif