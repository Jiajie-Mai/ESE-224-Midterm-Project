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
	string getUsername();
	string getPassword();
	void setUsername(string username);
	void setPassword(string password);
	int displayMenu();

	// file operations
	friend ostream& operator<< (ostream& output, User& user);
	friend istream& operator>> (istream& input, User& user);
};

