/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name MEHTAB SINGH JAGDE   Date  14/09/2023     Reason
***********************************************************************/
/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 14 / 10 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"

using namespace std;
namespace sdds {


	Portfolio::Portfolio() {
		emptyPortfolio();
	}

	void Portfolio::emptyPortfolio()
	{
		m_value = 0;
		m_stock[0] = 0;
		m_type = 'E';
	}
	Portfolio::Portfolio(double value, const char* stock, char type) {
		emptyPortfolio();
		if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
			m_value = value;
			m_type = type;
			strcpy(m_stock, stock);
		}
	}

	void Portfolio::dispPortfolio() const {
		cout << " ";
		cout.width(10);
		cout << (const char*)(*this);
		cout << " | ";
		cout << "Value: ";
		cout.width(10);
		cout << double(*this);
		cout << " | ";
		cout << " Type: ";
		cout << char(*this);
	}
	std::ostream& Portfolio::display() const {

		if (~*this) {
			cout << " Portfolio  |  Bad-NG |";
			dispPortfolio();
		}
		else if (*this) {
			cout << " Portfolio  |  Active |";
			dispPortfolio();

		}
		else {
			cout << " Portfolio  |  EMPTY  |";
			dispPortfolio();
		}
		return cout;
	}
	//Portfolio is casted to a double (double type)
	Portfolio::operator double() const {
		return m_value;
	}
	//Portfolio is casted to C-string
	Portfolio::operator const char* () const {
		return m_stock;
	}
	//Portfolio is casted to a char
	Portfolio::operator char() const {
		return m_type;
	}
	//Portfolio is casted to a bool 
	Portfolio::operator bool() const {
		bool check = false;
		if (m_type == 'G' || m_type == 'V' || m_type == 'I')
		{
			check = true;
		}
		return check;
	}
	//A double can be added to the value of the Portfolio m_value using += operator
	Portfolio& Portfolio::operator+=(double valuePortfolio) {
		if (*this && valuePortfolio >= 0)
		{
			m_value += valuePortfolio;
		}
		return *this;
	}
	//A double can be subtracted from the value of the Portfolio m_value using -= operator
	Portfolio& Portfolio::operator-=(double valuePortfolio) {
		if (*this && valuePortfolio >= 0)
		{
			m_value -= valuePortfolio;
		}
		return *this;
	}
	//This bool operator ~() will return true if m_value is negative
	bool Portfolio::operator ~() const {
		bool check = false;
		if (m_value < 0)
		{
			check = true;
		}
		return check;
	}
	//overload the << operator* (left shift operator) to move $dollar investment value m_value from Portfolio in the right to the left
	Portfolio& Portfolio::operator<<(Portfolio& rhs) {
		if (*this && rhs)
		{
			m_value += rhs.m_value;
			//emptying the portfolio on right
			rhs.emptyPortfolio();
		}
		return *this;
	}
	//overload the >> operator* (right shift operator) to move $dollar investment value m_value from Portfolio in the left to the right
	Portfolio& Portfolio::operator>>(Portfolio& rhs) {
		if (*this && rhs)
		{
			rhs.m_value += m_value;
			//emptying this portfolio
			emptyPortfolio();
		}
		return *this;
	}
	//The double value of the sum of the m_values of the two Flights is returned
	double operator+(const Portfolio& lhs, const Portfolio& rhs) {
		double sum = 0.0;
		if (lhs && rhs)
		{
			// adding m_values of the two portfolio references
			sum = double(lhs) + double(rhs);
		}
		return sum;
	}
	//The $dollar investment value of the right operand (Portfolio reference) is added to the left operand (double reference)
	double &operator+=(double& lhs, const Portfolio& rhs) {
		if (rhs)
		{
			lhs += double(rhs);
		}
		return lhs;
	}
}