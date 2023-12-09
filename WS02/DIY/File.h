/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name MEHTAB SINGH JAGDE            Date 23/09/2023            Reason
***********************************************************************/
/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZEE
 Date- 23/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   int noOfRecords();
   void closeFile();
   bool read(char*& pCode);
   bool read(int& population);

}
#endif // !SDDS_FILE_H_
