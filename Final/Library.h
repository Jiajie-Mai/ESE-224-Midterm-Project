#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Reader.h"
#include "Book.h"
#include "Copy.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;
class Library
{
private:
	vector<Book> books;
	vector<Copy> copies;
	vector<User> users;
	int userLoggedOn;
	bool loggedIn;
public:
	Library();
	void search(int key, string data);
	void userAuthentication(string username, string password);
	void logOut();
	void menuInput(int i);
	void displayMenu();
};

