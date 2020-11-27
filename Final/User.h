#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class User
{
private:
	string name;
	string username;
	string password;
public:
	User();
	string getUsername();
	string getPassword();
	int displayMenu();
};

