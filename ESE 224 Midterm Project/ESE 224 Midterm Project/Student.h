#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
private:
	string Username;
	string Password;
	int maxCopies;
	vector<Book> borrowed;
	vector<int> borrowingPeriod;
public:
	// constructors
	Student();

	// accessor functions
	string getUsername();
	string getPassword();
	int getMaxCopies();

	// mutator functions
	void setUsername(string Username);
	void setPassword(string Password);
	void setMaxCopies(int maxCopies);

	friend ostream& operator<< (ostream& output, Student& student);
	friend istream& operator>> (istream& input, Student& student);

	// authentication function, returns boolean for if the authentication is successful
	bool authenticate(string Username, string Password);
	void displayMenu();

	// student operations
	void borrowBook();
	void returnBook();
};

