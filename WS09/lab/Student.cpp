/*
Name - MEHTAB SINGH JAGDE, HARLEEN SINGH
Student ID - 119003226, 116871229
Email - mjagde@myseneca.ca, hsingh902@myseneca.ca
Section - ZEE
Date - 24 / 11 / 2023

We have completed this assignment ourselves  respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>
#include <iostream>
using namespace std;
//This should set the object to a safe empty state.
Student::Student() {
	m_name = nullptr;
	m_age = 0;
}
//This constructor receives the name and the age of the student
Student::Student(const char* name, int age) {
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	m_age = age;
}
//Copy Constructor
Student::Student(const Student& src) {
	m_age = src.m_age;
	if (src.m_name != nullptr)
	{
		m_name = new char[strlen(src.m_name) + 1];
		strcpy(m_name, src.m_name);
	}
	else
	{
		m_name = nullptr;
	}
}
//Copy Assignment Operator
Student& Student::operator=(const Student& src) {
	if (this != &src)
	{
		m_age = src.m_age;
		delete[] m_name;
		if (src.m_name != nullptr)
		{
			m_name = new char[strlen(src.m_name) + 1];
			strcpy(m_name, src.m_name);
		}
		else
		{
			m_name = nullptr;
		}
	}
	return *this;
}
//Destructor
Student::~Student() {
	delete[] m_name;
}
//This method simply displays the name and age of the student
void Student::display() {
	cout << "Name: " << m_name << endl;
	cout << "Age: " << m_age << endl;
}