/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZEE
 Date- 29/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
	void Train::initialize() {
		m_name = nullptr;
		m_noOfPeople = -1;
		m_departureTime = -1;
	}
	bool Train::validTime(int value)const {
		bool check = false;
		//Converts the time into minutes
		int minutes = value % 100;
		if (value >= MIN_TIME && value <= MAX_TIME && minutes <= 59)
		{
			check = true;
		}
		return check;
	}
	bool Train::validNoOfPassengers(int value)const {
		bool check = false;
		if (value > 0 && value <= MAX_NO_OF_PASSENGERS)
		{
			check = true;
		}
		return check;
	}
	void Train::set(const char* name) {
		//deleting m_name
		finalize();
		if (name != nullptr && name[0] != '\0')
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	}
	void Train::set(int noOfPassengers, int departure) {
		if (validNoOfPassengers(noOfPassengers) && validTime(departure))
		{
			m_noOfPeople = noOfPassengers;
			m_departureTime = departure;
		}
		else
		{
			m_noOfPeople = -1;
			m_departureTime = -1;
		}
	}
	void Train::set(const char* name, int noOfPassengers, int departure) {
		set(name);
		set(noOfPassengers, departure);
	}
	void Train::finalize() {
		delete[] m_name;
		m_name=nullptr;
	}
	bool Train::isInvalid()const {
		bool check = false;
		if (m_name == nullptr || m_noOfPeople == -1 || m_departureTime == -1)
		{
			check = true;
		}
		return check;
	}
	int Train::noOfPassengers() const {
		return m_noOfPeople;
	}
	const char* Train::getName() const {
		return m_name;
	}
	int Train::getDepartureTime() const {
		return m_departureTime;
	}
	void Train::display() const {
		if (!isInvalid())
		{
			cout << "NAME OF THE TRAIN:    " << getName() << endl;
			cout << "NUMBER OF PASSENGERS: " << noOfPassengers() << endl;
			cout << "DEPARTURE TIME:       " << getDepartureTime() << endl;
		}
		else
		{
			cout << "Train in an invalid State!" << endl;
		}
	}
	bool Train::load(int& unboarded) {
		bool check = false;
		int totalPassengers;
		cout << "Enter number of passengers boarding:" << endl;
		cout << "> ";
		cin >> totalPassengers;
		if (totalPassengers > (MAX_NO_OF_PASSENGERS-m_noOfPeople))
		{
			unboarded = totalPassengers - (MAX_NO_OF_PASSENGERS-m_noOfPeople);
			totalPassengers = MAX_NO_OF_PASSENGERS;
		}
		else
		{
			m_noOfPeople += totalPassengers;
			check = true;
		}
		return check;
	}
	bool Train::updateDepartureTime() {
		bool check = false;
		int newDepartTime;
		cout << "Enter new departure time:" << endl;
		cout << "> ";
		cin >> newDepartTime;
		if (validTime(newDepartTime))
		{
			m_departureTime = newDepartTime;
			check = true;
		}
		else
		{
			m_departureTime = -1;
		}
		return check;
	}
	bool Train::transfer(const Train& train) {
		bool check = false;
		if (isInvalid() || train.isInvalid())
		{
			check = false;
		}
		else
		{
			//+3 for a comma, space and a null terminator
			char* combinedName = new char[strlen(m_name) + strlen(train.m_name) + 3];
			strcpy(combinedName, m_name);
			strcat(combinedName, ", ");
			strcat(combinedName, train.m_name);
			delete[] m_name;
			//Dynamically allocating the name of the train to the size of the combined name
			m_name = new char[strlen(combinedName) + 1];  
			strcpy(m_name, combinedName);
			delete[] combinedName;
			if ((m_noOfPeople + train.m_noOfPeople) <= MAX_NO_OF_PASSENGERS)
			{
				m_noOfPeople += train.m_noOfPeople;
				check = true;
			}
			else
			{
				int leftPassengers = (m_noOfPeople+train.m_noOfPeople) - MAX_NO_OF_PASSENGERS;
				cout << "Train is full; " << leftPassengers << " passengers of " << train.m_name << " could not be boarded!" << endl;
				//Loading the train with number of people less than the Maximum allowed
				m_noOfPeople = (m_noOfPeople + train.m_noOfPeople) - leftPassengers;
				check = true;
			}
		}
		return check;
	}
}