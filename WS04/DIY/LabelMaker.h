/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date- 06/10/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#ifndef SDDS_LABEMAKERL_H_
#define SDDS_LABELMAKER_H_
#include "Label.h"
namespace sdds {
	class LabelMaker {
		//Creating a label array
		Label* m_label;
		int m_totalLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif