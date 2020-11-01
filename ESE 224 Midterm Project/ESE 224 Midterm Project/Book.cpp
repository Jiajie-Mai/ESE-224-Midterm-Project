#include "Book.h"
#include <string>
using namespace std;

Book::Book() {
	
}

Book::Book(int ISBN, string Title, string Author, string Category, int ID, string studentName, int startDate, int expirationDate) {
	this->ISBN = ISBN;
	this->Title = Title;
	this->Author = Author;
	this->Category = Category;
	this->ID = ID;
	this->studentName = studentName;
	this->startDate = startDate;
	this->expirationDate = expirationDate;
}


ostream& operator << (ostream& output, Book& book) { // used to output file from system
	output << "Title: " << book.getTitle() << endl;
	output << "Author: " << book.getAuthor() << endl;
	output << "Category: " << book.getCategory() << endl;
	output << "ID: " << book.getID() << endl;
	output << "ISBN: " << book.getISBN() << endl;
	output << "Student: " << book.getStudent() << endl;
	output << "StartDate: " << book.getStartDate() << endl;
	output << "ExpirationDate: " << book.getExpirationDate() << endl;
	return output;
}

istream& operator >> (istream& input, Book& book) { // used to input file into system
	string title, author, category;
	int id, isbn, startDate, expirationDate;
	string studentname;
	bool available;
	string empty;
	getline(input, empty, ':');					//we only want the title, so we remove the other parts of the line
	getline(input, title);						//we repeat this for every string
	title.erase(title.begin());					// first letter is an empty space, so we remove it
	getline(input, empty, ':');
	getline(input, author);
	author.erase(author.begin());
	getline(input, empty, ':');
	getline(input, category);
	category.erase(category.begin());
	getline(input, empty, ':');
	input >> id;								//we're not retrieving a string, so they >> operator is enough
	getline(input, empty, ':');
	input >> isbn;
	getline(input, empty, ':');
	getline(input, studentname);
	studentname.erase(studentname.begin());
	getline(input, empty, ':');
	input >> startDate;
	getline(input, empty, ':');
	input >> expirationDate;
	book.setTitle(title);
	book.setAuthor(author);
	book.setCategory(category);
	book.setID(id);
	book.setISBN(isbn);
	book.setStudent(studentname);
	book.setStartDate(startDate);
	book.setExpirationDate(expirationDate);
	return input;
}



int Book::getISBN() {
	return ISBN;
}
string Book::getTitle() {
	return Title;
}

string Book::getAuthor() {
	return Author;
}
string Book::getCategory() {
	return Category;
}
int Book::getID() {
	return ID;
}
string Book::getStudent() {
	return studentName;
}
int Book::getStartDate() {
	return startDate;
}
int Book::getExpirationDate() {
	return expirationDate;
}
void Book::setISBN(int ISBN) {
	this->ISBN = ISBN;
}
void Book::setTitle(string Title) {
	this->Title = Title;
}
void Book::setAuthor(string Author) {
	this->Author = Author;
}
void Book::setCategory(string Category) {
	this->Category = Category;
}
void Book::setID(int ID) {
	this->ID = ID;
}
void Book::setStudent(string studentName) {
	this->studentName = studentName;
}
void Book::setStartDate(int startDate) {
	this->startDate = startDate;
}
void Book::setExpirationDate(int expirationDate) {
	this->expirationDate = expirationDate;
}