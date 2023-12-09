/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
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
#include "Population.h"
#include "File.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
	int noOfPopulation;
	int count = 0;
	Population* pn;
	Population* matchingRecs;
	bool startsWith(const char* cstring, const char* subString) {
		return std::strstr(cstring, subString) == cstring;
	}

	void sort()
	{
		int i, j;
		Population temp;
		for (i = count - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (matchingRecs[j].population > matchingRecs[j + 1].population)
				{
					temp = matchingRecs[j];
					matchingRecs[j] = matchingRecs[j + 1];
					matchingRecs[j + 1] = temp;
				}
			}
		}
	}
	bool getPostalCode(char* postal_code_prefix) {
		bool check = true;
		cout << "Population Report" << endl;
		cout << "-----------------" << endl;
		cout << "Enter postal code:" << endl;
		cout << "> ";
		cin >> postal_code_prefix;
		if (strcmp(postal_code_prefix, "!") == 0)
		{
			check = false;
		}
		return check;
	}
	bool load(Population& pn) {
		bool check = false;
		//reading postal code from the file
		bool readPostal = read(pn.postalCode);
		//reading population from the file
		bool readPopulation = read(pn.population);
		if (readPostal && readPopulation)
		{
			check = true;
		}
		return check;
	}
	bool load(const char* filename, const char* partial_postal_code_prefix) {
		count = 0;
		bool check = false;
		if (openFile(filename))
		{
			//Total contents in the file
			noOfPopulation = noOfRecords();
			pn = new Population[noOfPopulation];
			for (int i = 0;i < noOfPopulation;i++)
			{
				if (load(pn[i]) && startsWith(pn[i].postalCode, partial_postal_code_prefix))
				{
					//If the postal code prefix matches any postal code in file, 1 will be added to the count
					count++;
					check = true;
				}
				else if(strcmp(partial_postal_code_prefix,"all")==0)
				{
					count= noOfPopulation;
					check = true;
				}
				else
				{
					check = true;
				}
			}
			matchingRecs = new Population[count];
			int index = 0;
			for (int i = 0; i < noOfPopulation; i++)
			{
				if (startsWith(pn[i].postalCode, partial_postal_code_prefix))
				{
					//Storing the matches records in a new array
					matchingRecs[index] = pn[i];
					index++;
				}
				else if(strcmp(partial_postal_code_prefix, "all") == 0)
				{
					matchingRecs[index] = pn[i];
					index++;
				}
			}
		}
		closeFile();
		return check;
	}
	void display() {
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		int poptotal = 0;
		//Sorting the records according to lowest to highest population
		sort();
		if (count > 0)
		{
			int i = 0, j = count;
			while (j != 0)
			{
				cout << i + 1 << "- " << matchingRecs[i].postalCode << ":  " << matchingRecs[i].population << endl;
				poptotal += matchingRecs[i].population;
				i++;
				j--;
			}
		}
		cout << "-------------------------" << endl;
		cout << "Population of the listed areas: " << poptotal << endl;
		cout << "\n";
	}

	void deallocateMemory() {
		for (int i = 0; i < noOfPopulation; i++) {
			delete[] pn[i].postalCode;
		}
		//Deallocating the dynamically allocated memory
		delete[] pn;
		pn = nullptr;
		delete[] matchingRecs;
		matchingRecs = nullptr;
		noOfPopulation = 0;
		count = 0;
	}
}