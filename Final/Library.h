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
#include "Librarian.h"
using namespace std;
class Library
{
private:
	vector<Book> books;
	vector<Copy> copies;
	vector<Student> students;
	vector<Teacher> teachers;
	vector<Librarian> librarians;
	int userIndex;
	int type;
	bool loggedIn;
public:
	// constructor
	Library();

	void search(int key, string data);

	//menu and user interface
	void userAuthentication(string username, string password);
	void logOut();
	void menuInput(int i);
	void displayMenu();

	//librarian functions
	void addBooks();
	void deleteBook();
	void searchUsers();
	void addUser();
	void deleteUser();

	//
};

