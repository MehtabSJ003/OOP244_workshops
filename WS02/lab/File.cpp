/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name  MEHTAB SINGH JAGDE          Date 18/09/2023           Reason
***********************************************************************/
/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZBB
 Date- 18/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    // TODO: read functions go here  
    const int conversions = 1;

    bool read(char*& name) {
        bool check = false;
        char employeeName[128];
        if (fscanf(fptr, "%127[^\n]\n", employeeName) == conversions) {
            //Assigning employeeName to null terminator
            employeeName[127] = '\0';
            name = new char[strlen(employeeName) + 1];
            strcpy(name, employeeName);
            check = true;
        }
        return check;
    }
    bool read(int& employeeNumber) {
        bool check = false;
        if (fscanf(fptr, "%d,", &employeeNumber) == conversions)
        {
            check = true;
        }
        return check;
    }
    bool read(double& employeeSalary) {
        bool check = false;
        if (fscanf(fptr, "%lf,", &employeeSalary) == conversions)
        {
            check = true;
        }
        return check;
    }
}