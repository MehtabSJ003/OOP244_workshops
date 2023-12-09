/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 11/ 11 / 2023

I have completed all my assignments myself respecting academic integrity.

*/
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>
namespace sdds
{
	const int MAX_CONTENT_LENGTH = 50;
	class Container
	{
		char m_content[MAX_CONTENT_LENGTH+1];
		int m_capacity;
		int m_contentVolume;
	protected:
		//Sets the Container to an invalid empty state
		void setEmpty();
		//returns the capacity of the container
		int capacity()const;
		//returns the content volume of the container
		int volume()const;
	public:
		Container(const char* content, int capacity, int contentVolume=0);
		//A value can be added to the Container. If the container has enough space for the value, it will be added to the content volume. 
		int operator+=(int value);
		//A value can be deducted from the Container. If the container has enough amount, it will reduce the content volume by the value.
		int operator-=(int value);
		//Returns true if the Container is in a valid state or false if it is not.
		operator bool() const;
		// it will set the corresponding attributes and therefore making the Container valid.
		void clear(int capacity, const char* description);
		//the print will display a valid container
		std::ostream& print(std::ostream& ostr)const;
		//read will get an amount to be added to the container
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Container& rhs);
	std::istream& operator>>(std::istream& istr, Container& rhs);
}
#endif