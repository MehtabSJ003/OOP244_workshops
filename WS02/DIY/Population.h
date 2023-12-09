/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name MEHTAB SINGH JAGDE            Date 23/09/2023           Reason
***********************************************************************/
/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZEE
 Date- 23/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct Population {
		char* postalCode;
		int population;
	};
   // returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);
   void sort();
   bool getPostalCode(char* postal_code_prefix);
   bool load(Population& pn);
   bool load(const char* filename, const char* partial_postal_code_prefix);
   void display();
   void deallocateMemory();
}
#endif // SDDS_POPULATION_H_