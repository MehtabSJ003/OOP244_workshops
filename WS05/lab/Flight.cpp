/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name MEHTAB SINGH JAGDE        Date            Reason
***********************************************************************/

/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 12 / 10 / 2023

I have completed all my assignments myself respecting academic integrity.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"
#include <iostream>
using namespace std;
namespace sdds { 

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    // Operator overload for converting Flight to bool.
    Flight::operator bool() const {
        bool check = false;
        if (m_passengers > 0 && m_fuel >= m_passengers * 600)
        {
            check = true;
        }
        return check;
    }

    // Operator overload for converting Flight to int (passengers).
    Flight::operator int() const {
        return m_passengers;
    }

    // Operator overload for converting Flight to double (fuel).
    Flight::operator double() const {
        return m_fuel;
    }

    // Operator overload for converting Flight to const char* (title).
    Flight::operator const char* () const {
        return m_title;
    }

    // Operator overload for bitwise negation (~) to check if passengers are zero.
    bool Flight::operator ~() const {
        bool check = false;
        if (m_passengers == 0)
        {
            check = true;
        }
        return check;
    }

    // Assignment operator overload for Flight.
    Flight& Flight::operator=(Flight& src) {
        if (this != &src)
        {
            strcpy(m_title, src.m_title);
            strcpy(src.m_title, "EmptyPlane");
            m_fuel += src.m_fuel;
            src.m_fuel = 0.0;
            m_passengers+= src.m_passengers;
            src.m_passengers = 0;
        }
        return *this;
    }

    // Assignment operator overload for setting passengers.
    Flight& Flight::operator=(int passengers) {
        if (passengers >0 && passengers <= Boen747Capacity)
        {
            m_passengers = passengers;
        }
        return *this;
    }

    // Assignment operator overload for setting fuel.
    Flight& Flight::operator=(double fuel) {
        if (fuel > 0 && fuel <= FuelTankCapacity)
        {
            m_fuel = fuel;
        }
        return *this;
    }

    // Compound assignment operator overload for adding fuel.
    Flight& Flight::operator+=(double fuel) {
        if (fuel > 0 && m_fuel+fuel <= FuelTankCapacity)
        {
            m_fuel += fuel;
        }
        return *this;
    }

    // Compound assignment operator overload for adding passengers.
    Flight& Flight::operator+=(int passengers) {
        if (passengers > 0 && passengers + m_passengers <= Boen747Capacity)
        {
            m_passengers += passengers;
        }
        return *this;
    }

    // Compound assignment operator overload for subtracting fuel.
    Flight& Flight::operator-=(double fuel) {
        if (fuel > 0 && m_fuel >= fuel)
        {
            m_fuel -= fuel;
        }
        else
        {
            m_fuel = 0;
        }
        return *this;
    }

    // Compound assignment operator overload for subtracting passengers.
    Flight& Flight::operator-=(int passengers) {
        if (passengers > 0 && m_passengers >= passengers)
        {
            m_passengers -= passengers;
        }
        else
        {
            m_passengers=0;
        }
        return *this;
    }

    // Operator overload for combining passengers from two Flights.
    Flight& Flight::operator<<(Flight& rhs) {
        if (this != &rhs)
        {
            int totalPassengers = m_passengers + rhs.m_passengers;
            if (totalPassengers <= Boen747Capacity)
            {
                m_passengers = totalPassengers;
                rhs.m_passengers = 0;
            }
            else
            {
                m_passengers = Boen747Capacity;
                rhs.m_passengers = totalPassengers - Boen747Capacity;
            }
        }
        return *this;
    }

    // Operator overload for transferring passengers to another Flight.
    Flight& Flight::operator>>(Flight& rhs) {
        if (this != &rhs)
        {
            int totalPassengers = m_passengers + rhs.m_passengers;
            if (totalPassengers <= Boen747Capacity)
            {
                m_passengers = 0;
                rhs.m_passengers = totalPassengers;
            }
            else
            {
                rhs.m_passengers = Boen747Capacity;
                m_passengers = totalPassengers - Boen747Capacity;
            }
        }
        return *this;
    }

    // Operator overload for adding passengers from two Flights.
    int Flight::operator+(const Flight& src)const {
        return m_passengers + src.m_passengers;
    }

    // Operator overload for adding passengers to an integer.
    int operator+=(int& lhs, const Flight& rhs) {
        lhs += int(rhs); 
        return lhs;
    }
}