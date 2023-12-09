/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 04 / 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "HealthCard.h"
const int MaxNameLength = 55;
using namespace std;
namespace sdds {
   
    //Private Methods
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
        bool check = false;
        //Checking validity of each attribute
        if (name && *name != '\0' && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9)
        {
            check = true;
        }
        return check;
    }
    void HealthCard::setEmpty() {
        delete[] m_name;
        m_name = nullptr;
    }
    void HealthCard::allocateAndCopy(const char* name) {
        setEmpty();
        //Allocated dynamic memory
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
    void HealthCard::extractChar(istream& istr, char ch) const {
        char next;
        next = istr.peek();
        if (next == ch)
        {
            //Removing next character from keyboard
            istr.ignore();
        }
        else
        {
            //Ignoring all remaining characters
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }
    ostream& HealthCard::printIDInfo(ostream& ostr)const {
        ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
        return ostr;
    }
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber))
        {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        else
        {
            setEmpty();
        }
    }

    //Public Methods
    HealthCard::HealthCard() {
        m_name = nullptr;
        m_number = 0;
        m_vCode[0] = '\0';
        m_sNumber[0] = '\0';
    }
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        set(name, number, vCode, sNumber);
    }
    HealthCard::HealthCard(const HealthCard& hc) {
        set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
    }
    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        if (this != &hc)
        {
            setEmpty();
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    }
    HealthCard::~HealthCard() {
        delete[] m_name;
        m_name = nullptr;
    }
    HealthCard::operator bool() const {
        bool check = false;
        if (m_name != nullptr)
        {
            check = true;
        }
        return check;
    }
    ostream& HealthCard::print(ostream& ostr, bool toFile) const {
        if (*this)
        {
            if (toFile == true)
            {
                ostr << m_name << ",";
                printIDInfo(ostr);
                ostr << endl;
            }
            else
            {
                //In 50 characters
                ostr.width(50);
                //left justified
                ostr.setf(ios::left);
                //filled with dots
                ostr.fill('.');
                ostr << m_name;
                printIDInfo(ostr);
            }
        }
        return ostr;
    }
    istream& HealthCard::read(istream& istr) {
        char name[MaxNameLength];
        long long number{ 0 };
        char vCode[3];
        char sNumber[10];
        //getting input
        istr.get(name, MaxNameLength,',');
        //calling the extract function
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');
        if (!istr.fail())
        {
            set(name, number, vCode, sNumber);
        }
        else
        {
            //Clearing the state
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }
    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else
        {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }
    istream& operator>>(istream& istr, HealthCard& hc) {
        hc.read(istr);
        return istr;
    }
}
