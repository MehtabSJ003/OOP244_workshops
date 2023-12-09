/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZEE
Date - 02 / 12 / 2023

We have completed this assignment ourselves respecting academic integrity.

*/
#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H
using namespace std;
namespace sdds
{
	//Seaeches an array for all occurences of a specified key and returns a pointer to new array
	template<typename arrayType, typename keyType>
	int* select(const arrayType array[], const keyType& key, size_t size){
		int* updatedArray = new int[size + 1];
		int count = 0;
		for (size_t i = 0; i < size; ++i) 
		{
			if (array[i] == key) 
			{
				//updating the new array while incrementing the count variable
				updatedArray[count++] = static_cast<int>(i);
			}
		}
		//Setting the last element of the array to -1
		updatedArray[count] = -1;
		return updatedArray;
	}
	//Takes title and an array and displays the elements at the indicies specified in a second array
	template<typename arrayType>
	void csvDisplaySelection(const char* title, const arrayType array[], const int* indices){
		cout << title << endl;
		if (indices!=nullptr && indices[0] != -1) 
		{
			for (int i = 0; indices[i] != -1; ++i) 
			{
	            cout << array[indices[i]];
				if (indices[i + 1] != -1) 
				{
					cout << ", ";
				}
			}
		}
		else
		{
			cout << "Empty Selection";
		}
		cout << endl;
	}
}
#endif
