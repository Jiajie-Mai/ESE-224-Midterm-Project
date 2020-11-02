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
	vector<Book> library;
	vector<Book> borrowed;
	vector<Student> students;
public:
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

	void initializeBorrow(); //moving books from library to borrowed if the students have them
	bool bookAvaliable(int ID); // for checking if a book exists
	bool copiesAvaliable(int ISBN); // for checking if a copy of a book exists

	bool overdue(int ID);
	void borrowBook(int ISBN); // helper function to the one in student
	void returnBook(int ISBN); // helper function to the one in student
};

