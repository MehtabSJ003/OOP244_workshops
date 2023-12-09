/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  MEHTAB SINGH JAGDE      Date            Reason
***********************************************************************/

/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 12 / 10 / 2023

I have completed all my assignments myself respecting academic integrity.

*/

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;//min 600
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char* () const;
      bool operator ~() const;
      Flight& operator=(Flight& src);
      Flight& operator=(int passengers);
      Flight& operator=(double fuel);
      Flight& operator+=(double fuel);
      Flight& operator+=(int passsengers);
      Flight& operator-=(double fuel);
      Flight& operator-=(int passengers);
      Flight& operator<<(Flight& flight);
      Flight& operator>>(Flight& flight);
      int operator+(const Flight& src)const;
   };
   int operator+=(int& lhs, const Flight& rhs);

}
#endif // SDDS_FLIGHT_H