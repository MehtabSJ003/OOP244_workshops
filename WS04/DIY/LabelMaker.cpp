/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date- 06/10/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <cstring>
#include "Label.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		m_totalLabels = noOfLabels;
		//dynamically allocating total labels to label array
		m_label = new Label[m_totalLabels];
	}
	
	void LabelMaker::readLabels() {
		cout << "Enter " << m_totalLabels << " labels:" << endl;
		//Looping till total number of labels
		for (int i = 0;i < m_totalLabels;i++) 
		{
			//gets user input
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			m_label[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {
		for (int i = 0;i < m_totalLabels;i++)
		{
			//Printing each label
			m_label[i].printLabel()<<endl;
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] m_label;
	}
}
