#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
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

	// library functions
	void readFiles();	//reads files from files into vectors
	void writeFiles();	//writes files from vectors into files

	void addBook(Book book);	//adds book to books
	void removeBook(int index);	//removes book based on index

	void addCopy(Copy copy);	//adds copy to copies
	void removeCopy(int ID);	//removes book based on ID

	void addStudent(Student student); //adds student from file to students vector
	void removeStudent(string username); // removes student based on username

	void addTeacher(Teacher teacher); //adds teacher from file to teachers vector
	void removeTeacher(string username); // removes teacher based on username

	void addLibrarian(Librarian librarian); //adds librarian from file to librarians vector
	void removeLibrarian(string username); // removes librarian based on username



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

