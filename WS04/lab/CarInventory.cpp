/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZEE
 Date- 03/10/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <cstring>
#include <iostream>
#include<iomanip>
using namespace std;
namespace sdds {
	void CarInventory::resetInfo() {
		 m_type=nullptr;
		 m_brand=nullptr;
		 m_model=nullptr;
		 m_year = 0;
		 m_code=0;
		 m_price=0;
	}
	CarInventory::CarInventory() {
		resetInfo();
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		resetInfo();
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && (code >= 100 && code <= 999) && price > 0)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
	}
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		resetInfo();
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		return *this;
	}
	void CarInventory::printInfo() const {
		cout << "| " << left << setw(10) << m_type << " | " << setw(16) << m_brand << " | " << setw(16) << m_model
			<< " | " << setw(4) << m_year << " | " << setw(4) <<right<< m_code << " | " << setw(9) << right<<fixed << setprecision(2) << m_price << " |" << endl;
	}
	bool CarInventory::isValid() const {
		bool check = false;
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && (m_code >= 100 && m_code <= 999) && m_price > 0)
		{
			check = true;
		}
		return check;
	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		bool check = false;
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr) 
		{
			if ((strcmp(m_type, car.m_type)==0) || (strcmp(m_brand, car.m_brand)==0) || (strcmp(m_model, car.m_model)==0) || (m_year == car.m_year))
			{
				check = true;
			}
		}
		return check;
	}
	CarInventory::~CarInventory() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		resetInfo();
	}
	int find_similar(CarInventory car[], const int num_cars) {
		int index = 0;
		for (int i = 0; i < num_cars; i++) 
		{
			for (int j = i + 1; j < num_cars; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					index = i;
				}
			}
		}
		return index;
	}
}
