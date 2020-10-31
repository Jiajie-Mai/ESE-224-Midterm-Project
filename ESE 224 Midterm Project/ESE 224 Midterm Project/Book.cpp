#include "Book.h"
#include <string>
using namespace std;

Book::Book() {
	
}


ostream& operator << (ostream& output, Book& book) { //add to later
	output << "\tID:\t\t" << book.getID() << endl;
	output << "\tISBN:\t\t" << book.getISBN() << endl;
	output << "\tStudent:\t\t" << book.getStudent() << endl;
	return output;
}

istream& operator >> (istream& input, Book& book) { // add to later
	int id;
	int isbn;
	string studentname;
	bool available;
	input >> id >> isbn >> studentname;	//add more stuff later
	book.setID(id);
	book.setISBN(isbn);
	book.setStudent(studentname);
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
void Book::setISBN(int ISBN) {
	this->ISBN = ISBN;
}
void Book::setTitle(string Title) {
	this->Title=Title;
}
void Book::setAuthor(string Author) {
	this->Author=Author;
}
void Book::setCategory(string Category) {
	this->Category=Category;
}
void Book::setID(int ID) {
	this->ID = ID;
}
void Book::setStudent(string studentName) {
	this->studentName = studentName;
}