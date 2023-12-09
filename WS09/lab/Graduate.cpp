/*
Name - MEHTAB SINGH JAGDE, HARLEEN SINGH
Student ID - 119003226, 116871229
Email - mjagde@myseneca.ca, hsingh902@myseneca.ca
Section - ZEE
Date - 24 / 11 / 2023

We have completed this assignment ourselves  respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "Graduate.h"
#include <cstring>
#include <iostream>
using namespace std;
//This should set the object to a safe empty state along with invoking base class default constructor
Graduate::Graduate() :Student() {
	m_supervisorName = nullptr;
	m_thesisTitle = nullptr;
}
//This constructor should be able to appropriately allocate the heap memory for the thesis title and supervisor name along with invoking base class constructor
Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisorName) :Student(name, age) {
	m_supervisorName = new char[strlen(supervisorName) + 1];
	strcpy(m_supervisorName, supervisorName);
	m_thesisTitle = new char[strlen(thesisTitle) + 1];
	strcpy(m_thesisTitle, thesisTitle);
}
//Copy Constructor
Graduate::Graduate(const Graduate& src) :Student(src) {
	if (src.m_supervisorName != nullptr)
	{
		m_supervisorName = new char[strlen(src.m_supervisorName) + 1];
		strcpy(m_supervisorName, src.m_supervisorName);
	}
	else
	{
		m_supervisorName = nullptr;
	}
	if (src.m_thesisTitle != nullptr)
	{
		m_thesisTitle = new char[strlen(src.m_thesisTitle) + 1];
		strcpy(m_thesisTitle, src.m_thesisTitle);
	}
	else
	{
		m_thesisTitle = nullptr;
	}
}
//Copy Assignment Operator
Graduate& Graduate::operator=(const Graduate& src) {
	if (this != &src)
	{
		//Invoking base class copy Assignment operator
		Student::operator=(src);
		delete[] m_supervisorName;
		delete[] m_thesisTitle;
		if (src.m_supervisorName != nullptr)
		{
			m_supervisorName = new char[strlen(src.m_supervisorName) + 1];
			strcpy(m_supervisorName, src.m_supervisorName);
		}
		else
		{
			m_supervisorName = nullptr;
		}
		if (src.m_thesisTitle != nullptr)
		{
			m_thesisTitle = new char[strlen(src.m_thesisTitle) + 1];
			strcpy(m_thesisTitle, src.m_thesisTitle);
		}
		else
		{
			m_thesisTitle = nullptr;
		}
	}
	return *this;
}
//Destructor
Graduate::~Graduate() {
	delete[] m_supervisorName;
	delete[] m_thesisTitle;
}
//This method simply displays the name and age of the student along with the Thesis title and name of the supervisor
void Graduate::display() {
	Student::display();
	cout << "Thesis Title: " << m_thesisTitle << endl;
	cout << "Supervisor: " << m_supervisorName << endl;
	cout << "---------------------------------------------" << endl;
}
