/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name MEHTAB SINGH JAGDE           Date 23/09/2023           Reason
***********************************************************************/
/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZEE
 Date- 23/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"
namespace sdds {
    const int conversions = 1;
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
       int noOfRecs = 0;
       char ch;
       while (fscanf(fptr, "%c", &ch) == conversions) {
           noOfRecs += (ch == '\n');
       }
       rewind(fptr);
       return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   } 
   bool read(char*& pCode) {
       bool check = false;
       char code[128];
       // Read up to 127 characters (excluding commas) or until the next comma into 'code'
       if (fscanf(fptr, "%127[^,],", code) == conversions)
       {
           code[127] = '\0';
           // Allocate memory for 'pCode' to hold a copy of 'code' using dynamic memory allocation
           pCode = new char[strlen(code) + 1];
           strcpy(pCode, code);
           check = true;
       }
       return check;
   }
   bool read(int& population) {
       bool check = false;
       if (fscanf(fptr, "%d\n", &population) == conversions)
       {
           check = true;
       }
       return check;
   }
}