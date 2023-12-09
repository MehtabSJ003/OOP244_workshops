/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main_prof.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
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
#include <iostream>
#include "Population.h"
using namespace sdds;
int main() {
    char code[4]{};
    while (getPostalCode(code)) {
        if (load("PCpopulationsComplete.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}
