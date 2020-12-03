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
	int userType;
	bool loggedIn;
public:
	// constructor
	Library();

	//accessor functions
	vector<Book> getBooks();
	vector<Copy> getCopies();
	vector<Student> getStudents();
	vector<Teacher> getTeachers();
	vector<Librarian> getLibrarians();

	void search(int key, string data);

	// library functions
	void readFiles();	//reads files from files into vectors
	void writeFiles();	//writes files from vectors into files

	void addBook(Book book);	//adds book to books vector
	void removeBook(int index);	//removes book based on index

	void addCopy(Copy copy);	//adds copy to copies
	void removeCopy(int ID);	//removes book based on ID

	void addStudent(Student student); //adds student from file to students vector
	void removeStudent(string username); // removes student based on username
	Student* getStudent(string username); // returns student from username, if does not exist, returns NULL
	void updateStudent(Student student); // updates student so that thing show up

	void addTeacher(Teacher teacher); //adds teacher from file to teachers vector
	void removeTeacher(string username); // removes teacher based on username
	Teacher* getTeacher(string username); // returns teacher from username, if does not exist, returns NULL
	void updateTeacher(Teacher teacher); // updates teacher so that thing show up

	void addLibrarian(Librarian librarian); //adds librarian from file to librarians vector
	void removeLibrarian(string username); // removes librarian based on username
	Librarian* getLibrarian(string username); // returns librarian from username, if does not exist, returns NULL


	int findIfBookExists(int ISBN); // finds book's index in vector, returns -1 if does not exist
	Book* findBook(int ISBN); // returns book from isbn
	Book* findBookFromBookIndex(int bookIndex); // finds book's index in vector from bookIndex, returns -1 if does not exist
	int findCopyInVector(int ID); // finds copy's index in vector, returns -1 if does not exist
	Copy* findCopy(int ID); // returns copy from isbn

	//menu and user interface
	void userAuthentication(string username, string password);
	void logOut();
	void menuInput(int i);
	void displayMenu();

	//librarian functions
	void addBooks(int ISBN, string title, string author, string category);
	void deleteBook(int ID);
	void searchUsers(string username);
	void addUser();
	void deleteUser();

	//library manipulation
	bool overdue(Reader reader);
	void borrowBook(int ISBN);
	void returnBook(int id);
	void reserveBook(int ISBN);
	void cancelReserve(int ISBN);
	void renewBook(int id);

	//user functions
	void searchBooks();
	void recommendBooks();

	//testing
	void printBooks();
	void printCopies();
	void printStudents();
	void printTeachers();
	void printLibrarians();
};

