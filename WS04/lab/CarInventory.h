/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZEE
 Date- 03/10/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#ifndef SDDS_CARINVENTORY_H_
#define SDDS_CARINVENTORY_H_
namespace sdds
{
	class CarInventory
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year=2022, int code=100, double price=1.0);
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
		~CarInventory();
	};
	int find_similar(CarInventory car[], const int num_cars);
}
#endif