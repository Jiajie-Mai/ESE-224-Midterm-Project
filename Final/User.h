#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class User
{
protected:
	string name;
	string username;
	string password;
public:
	User();

	// acccessor functions
	string getUsername();
	string getPassword();

	// mutator functions
	void setUsername(string username);
	void setPassword(string password);

	int displayMenu(); // default display menu for a generic User

	// file operations
	friend ostream& operator<< (ostream& output, User& user);
	friend istream& operator>> (istream& input, User& user);
};

