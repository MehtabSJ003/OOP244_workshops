/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 11/ 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
	void Container::setEmpty() {
		m_content[0] = '\0';
		m_capacity = 0;
		m_contentVolume = 0;
	}
	int Container::capacity()const {
		return m_capacity;
	}
	int Container::volume()const {
		return m_contentVolume;
	}
	Container::Container(const char* content, int capacity, int contentVolume) {
		if (content && content[0] != '\0' && contentVolume < capacity)
		{
			//copies the argument to cstring array
			strncpy(m_content, content, MAX_CONTENT_LENGTH );
			m_content[MAX_CONTENT_LENGTH - 1] = '\0';
			m_capacity = capacity;
			m_contentVolume = contentVolume;
		}
		else
		{
			//setting the container to invalid state
			setEmpty();
		}
	}
	int Container::operator+=(int value) {
		int addedAmount=0;
		//Calculating space remaining
		int enoughSpace = m_capacity - m_contentVolume;
		if (value <= enoughSpace)
		{
			m_contentVolume += value;
			addedAmount = value;
		}
		else
		{
			m_contentVolume += enoughSpace;
			addedAmount = enoughSpace;
		}
		return addedAmount;
	}
	int Container::operator-=(int value) {
		int reducedAmount=0;
		if (value <= m_contentVolume)
		{
			m_contentVolume -= value;
			reducedAmount = value;
		}
		else
		{
			reducedAmount = m_contentVolume;
			m_contentVolume = 0;
		}
		return reducedAmount;
	}
	Container::operator bool() const {
		bool check = false;
		if (m_content[0] != '\0' && m_contentVolume <= m_capacity)
		{
			check = true;

		}
		return check;
	}
	void Container::clear(int capacity, const char* description) {
		if (capacity > 0 && description && description[0] != '\0')
		{
			setEmpty();
			m_capacity = capacity;
			strncpy(m_content, description,MAX_CONTENT_LENGTH);
		}
	}
	ostream& Container::print(std::ostream& ostr)const {
		if (*this)
		{
			ostr << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
		}
		else
		{
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}
	istream& Container::read(std::istream& istr) {
		if (!(*this))
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;;
			istr.ignore(1000, '\n');
		}
		else
		{
			cout << "Add to ";
			print(cout);
			cout << endl;
			cout << "> ";
			int integerValue;
			//Taking input till the valid answer is typed in
			while (!(istr >> integerValue) || integerValue < 1 || integerValue>999)
			{
				istr.clear();
				istr.ignore(1000, '\n');
				if (!integerValue)
				{
					cout << "Invalid Integer, retry: ";
				}
				if (integerValue<1 || integerValue>999)
				{
					cout << "Value out of range [1<=val<=999]: ";
				}
			}
			//Adding the entered integer to the container
			int addedAmount = *this += integerValue;
			cout << "Added " << addedAmount << " CCs"<<endl;
		}
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Container& rhs) {
		rhs.print(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Container& rhs) {
		rhs.read(istr);
		return istr;
	}
}