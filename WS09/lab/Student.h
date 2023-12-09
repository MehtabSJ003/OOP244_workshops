/*
Name - MEHTAB SINGH JAGDE, HARLEEN SINGH
Student ID - 119003226, 116871229
Email - mjagde@myseneca.ca, hsingh902@myseneca.ca
Section - ZEE
Date - 24 / 11 / 2023

We have completed this assignment ourselves  respecting academic integrity.

*/
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

class Student {
	char* m_name;
	int m_age;
public:
	Student();
	Student(const char* name, int age);
	Student(const Student& src);
	Student& operator=(const Student& src);
	virtual ~Student();
	void display();
};

#endif