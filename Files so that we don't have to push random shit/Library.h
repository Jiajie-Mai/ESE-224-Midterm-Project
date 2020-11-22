#pragma once
#include "Book.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
class LMS
{
private:
	bool loggedIn;
	int studentLoggedOn;
	vector<Book> library;
	vector<Student> students;
public:
	LMS();
	Book findBook(int ID); // ids are unique (does not work if book does not exist)
	void readFiles();	//reads files from book.txt
	void writeFiles();	//writes files into book.txt
	void addBook(Book book);	//adds book to library
	void removeBook(int ID);	//removes book based on ID

	void createNewStudent();	// Creates a new student by entering in data
	void addStudent(Student student); //adds student from file to students vector
	void removeStudent(string username); // removes student based on username

	void printLibrary(); // for testing, prints library
	void printStudents(); // for testing, prints students
	Book recommendBooks(Book Book);
	int rand_int(int a, int b);

	bool available(int ISBN);
	void borrowBook(Student student, int ISBN);
	void returnBook(Student student, int ID);

	void userAuthentication(string username, string password); // identifies if a student exists with given parameters
	void logOut(); // logs out of current user
	void displayMenu(); // display prompt
	void menuInput(int i);
};

