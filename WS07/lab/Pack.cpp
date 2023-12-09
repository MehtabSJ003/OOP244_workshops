/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 11/ 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Pack.h"
using namespace std;
namespace sdds {
	Pack::Pack(const char* description, int size, int unitSize, int numberOfUnits):Container(description,size*unitSize,numberOfUnits*unitSize) {
		if (unitSize >= 0)
		{
			m_unitSize = unitSize;
		}
		else
		{
			Container::setEmpty();
		}
	}
	int Pack::operator+=(int value) {
		int addedAmount;
		addedAmount = Container::operator+=(value * m_unitSize);
		return addedAmount / m_unitSize;
	}
	int Pack::operator-=(int value) {
		int reducedAmount;
		reducedAmount = Container::operator-=(value * m_unitSize);
		return reducedAmount / m_unitSize;
	}
	int Pack::unit()const {
		return m_unitSize;
	}
	int Pack::noOfUnits()const {
		return volume() / m_unitSize;
	}
	int Pack::size()const {
		return capacity() / m_unitSize;
	}
	void Pack::clear(int packSize, int unitSize, const char* description) {
		if (unitSize > 0)
		{
			Container::clear(packSize * unitSize, description);
			m_unitSize = unitSize;
		}
	}
	ostream& Pack::print(std::ostream& ostr)const {
		if (*this)
		{
			Container::print(ostr);
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}
	istream& Pack::read(std::istream& istr) {
		if (!*this)
		{
		cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(1000, '\n');
		}
		else
		{
			//Calculating missing units
			int missingUnits = size() - noOfUnits();
			if (noOfUnits() < size())
			{
				cout << "Add to ";
				print(cout);
				cout << endl;
				cout << "> ";
				int integerValue;
				//Taking the input till invalid integer is entered
				while (!(istr>>integerValue)||integerValue<1 || integerValue>missingUnits)
				{
					istr.clear();
					istr.ignore(1000, '\n');
					if (!integerValue)
					{
						cout << "Invalid Integer, retry: ";
					}
				    if (integerValue<1 || integerValue>missingUnits)
					{
						cout << "Value out of range [1<=val<=" << missingUnits << "]: ";
					}
				}
				//Adding the integer value to pack
				int addedAmount = *this += integerValue;
				cout << "Added " << addedAmount << endl;
			}
			else
			{
				cout << "Pack is full!, press <ENTER> to continue..." << endl;
				istr.ignore(1000, '\n');
			}
		}
		return istr;
	}
	ostream& operator<<(ostream& ostr, Pack& rhs) {
		rhs.print(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Pack& rhs) {
		rhs.read(istr);
		return istr;
	}
}