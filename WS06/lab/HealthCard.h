/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 04 / 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
#include <iostream>
using namespace std;
namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
      //Returns true is the four parts of the ID card are valid
      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;

      //Sets the HeathCard object to a recognizable empty (invalid) state
      void setEmpty();

      //Free the memory and allocate it
      void allocateAndCopy(const char* name);

      //Check if the next character in the keyboard buffer is the same as the ch argument
      void extractChar(istream& istr, char ch) const;

      //Inserts the three parts related to the main card number, version code and stock number
      ostream& printIDInfo(ostream& ostr)const;

      //Validates the arguments, reallocates memory for the name and sets the object attributes to their corresponding values.
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);
   public:
       //No-Argument contructor
       HealthCard();

       //4 Argument constructor
       HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]);

       //Copy Constructor
       HealthCard(const HealthCard& hc);

       //Copy Assignment Operator
       HealthCard& operator=(const HealthCard& hc);

       //Destructor
       ~HealthCard();

       //Returns true if m_name is not nullptr, else it will return false
       operator bool() const;

       //If the current object is in a valid state it inserts the values of the card information
       ostream& print(ostream& ostr, bool toFile = true) const;

       //Reads the Health Card information
       istream& read(istream& istr);

   };

   ostream& operator<<(ostream& ostr, const HealthCard& hc);
   istream& operator>>(istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H


