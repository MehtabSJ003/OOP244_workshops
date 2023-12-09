/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name MEHTAB SINGH JAGDE           Date  18/09/2023          Reason
***********************************************************************/
/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZBB
 Date- 18/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes
	bool read(char*& name);
	bool read(int& employeeNumber);
	bool read(double& employeeSalary);
}

#endif // !SDDS_FILE_H_