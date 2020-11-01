#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstring>
using namespace std;

extern clock_t t_start;

class Student
{
private:
	string studentName;
	string Username;
	string Password;
	int maxCopies;
	vector<int> borrowed; // borrowed holds the IDs of books that are borrowed
	vector<int> borrowingPeriod; // the stream operators rely on the size of this vector. Make sure the vector size cannot exceed max copies for this vector and the one above.
public:
	// constructors
	Student();

	// accessor functions
	string getStudentName();
	string getUsername();
	string getPassword();
	int getMaxCopies();
	vector<int> getBorrowed();
	vector<int> getBorrowingPeriod();

	// mutator functions
	void setStudentName(string studentName);
	void setUsername(string Username);
	void setPassword(string Password);
	void setMaxCopies(int maxCopies);
	void setBorrowed(int ID); //setBorrowed pushes an ID to the back of the vector
	void setBorrowingPeriod(int date); //setBorrowingPeriod pushes a date into the back of the vactor

	// file operations
	friend ostream& operator<< (ostream& output, Student& student);
	friend istream& operator>> (istream& input, Student& student);
	

	// authentication function, returns boolean for if the authentication is successful
	bool authenticate(string Username, string Password);
	void displayMenu();

	// student operations
	void borrowBook();
	void returnBook();

	// date counter
	int returnDay();	// returns day (day 1 begins once program starts)
	bool isOverdue(int date);	// returns 1 if student has overdue books

	
};

