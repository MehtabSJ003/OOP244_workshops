
/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name MEHTAB SINGH JAGDE   Date 18/09/2023           Reason
***********************************************************************/
/*
 Name - MEHTAB SINGH JAGDE
 Student ID - 119003226
 Email - mjagde@myseneca.ca
 Section - ZBB
Date- 18/09/2023

I have completed all my assignments myself respecting the academic integrity.

*/

#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employee) {
        bool check = false;
        // return the combined success result of the three read functions. These read 
        // functions should set the properties of the reference argument of the load function
        bool empNum = read(employee.m_empNo);
        bool empSal = read(employee.m_salary);
        bool empName = read(employee.m_name);
        if (empNum && empSal && empName)
        {
            check = true;
        }
        return check;
    }

    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool check = false;
        bool file = openFile(DATAFILE);
        if (!file)
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        else
        {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (int i = 0;i < noOfEmployees;i++)
            {
                if (load(employees[i]))
                {
                    check = true;
                }
                else
                {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                   //Deallocating memory followed by closing the file
                    deallocateMemory();
                    closeFile();
                    check = false;
                }
            }
        }
        closeFile();
        return check;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& employeeDetails) {
        cout << employeeDetails.m_empNo << ": " << employeeDetails.m_name << ", $" << employeeDetails.m_salary << endl;
    }

    void display() {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        //sorting the final data which will be displayed
        sort();
        for (int i = 0;i < noOfEmployees;i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        for (int i = 0;i < noOfEmployees;i++)
        {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        //reinitiallizing values
        employees = nullptr;
        noOfEmployees = 0;
    }
}