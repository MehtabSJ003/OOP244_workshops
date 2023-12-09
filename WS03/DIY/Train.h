/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZEE
 Date- 29/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#ifndef SDDS_TRAIN_H_
#define SDDS_TRAIN_H_
const int MIN_TIME = 700;
const int MAX_TIME = 2300;
const int MAX_NO_OF_PASSENGERS = 1000;
namespace sdds {
	class Train
	{
		char* m_name;
		int m_noOfPeople;
		int m_departureTime;
		
	public:
		//Initializes the Train object to an invalid state
		void initialize();

		//Returns true if the value is between the minimum and maximum acceptable values 
		bool validTime(int value)const;

		//Returns true if the number of passengers is positive and less than the maximum number of passengers allowed on a train
		bool validNoOfPassengers(int value)const;

		//Sets the name of the Train dynamically
		void set(const char* name);

		//sets the two attributes for the number of passengers and departure time to the incomming values if the are valid
		void set(int noOfPassengers, int departure);

		//sets the name, the number of passengers and the departure time to incomming arguments
		void set(const char* name, int noOfPassengers, int departure);

		//Finlizes the use of the Train object by deleting the memory pointed by the name attribute pointer.
		void finalize();

		//returns true if any of the attributes are set to their invalid state
		bool isInvalid()const;

		//This query returns the number of people on a train
		int noOfPassengers() const;

		//This query returns the name of a train
		const char* getName() const;

		//This query returns the time of departure
		int getDepartureTime() const;

		//This member function sends the information about a Train to the standard output in the following format if the object holds valid data values
		void display() const;

		//The function returns true if everyone is boarded and false if some are left behind
		bool load(int& unboarded);

		//This function returns a boolean to indicate if the action was successful or not
		bool updateDepartureTime();

		//Transfers the passengers of a Train to the current Train
		bool transfer(const Train& train);
	};
}
#endif