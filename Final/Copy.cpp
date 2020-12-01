#include "Copy.h"

clock_t t_start = clock();

int Copy::getID() {
	return ID;
}

int Copy::getBook() {
	return bookIndex;
}

string Copy::getReader() {
	return readerName;
}

string Copy::getReserver() {
	return reserverName;
}

bool Copy::getAvailable() {
	return available;
}

int Copy::getBorrowDate() {
	return borrowDate;
}

int Copy::getReserveDate() {
	return reserveDate;
}

int Copy::getExpirationDate() {
	return expirationDate;
}

void Copy::setID(int ID) {
	this->ID = ID;
}

void Copy::setBook(int bookIndex) {
	this->bookIndex = bookIndex;
}

void Copy::setReader(string readerName) {
	this->readerName = readerName;
}

void Copy::setReserver(string reserverName) {
	this->reserverName = reserverName;
}

void Copy::setAvailable(bool available) {
	this->available = available;
}

void Copy::setBorrowDate(int borrowDate) {
	this->borrowDate = borrowDate;
}

void Copy::setReserveDate(int reserveDate) {
	this->reserveDate = reserveDate;
}

void Copy::setExpirationDate(int expirationDate) {
	this->expirationDate = expirationDate;
}

int Copy::returnDay() { // returns day
	clock_t t_difference = clock() - t_start; // this is used to find current time
	float seconds = t_difference / CLOCKS_PER_SEC;
	int day = seconds / 5 + 1; ;// We add 1 because the day starts at Day 1
	return day;
}


ostream& operator << (ostream& output, Copy& copy) { // used to output file from system
	output << "ID: " << copy.getID() << endl;
	output << "Book: " << copy.getBook() << endl; // stores book as index
	output << "Reader: " << copy.getReader() << endl; // stores reader as username
	output << "Reserver: " << copy.getReserver() << endl; // stores reserver as username
	output << "Available: " << copy.getAvailable() << endl;
	output << "BorrowDate: " << copy.getBorrowDate() << endl;
	output << "ReserveDate: " << copy.getReserveDate() << endl;
	output << "ExpirationDate: " << copy.getExpirationDate() << endl;
	return output;
}

istream& operator >> (istream& input, Copy& copy) { // used to input file into system
	string readerName, reserverName;
	int ID, bookIndex, borrowDate, reserveDate, expirationDate;
	bool available;
	string empty;
	getline(input, empty, ':');
	input >> ID;								//we're not retrieving a string, so they >> operator is enough

	getline(input, empty, ':');
	input >> bookIndex;

	getline(input, empty, ':'); // gets rid of the part of the line before the ':'
	getline(input, readerName); // inputs the rest of the line, which is the name
	readerName.erase(readerName.begin()); //removes first character since it is a space

	getline(input, empty, ':');
	getline(input, reserverName); 
	reserverName.erase(reserverName.begin());

	getline(input, empty, ':');
	input >> available;

	getline(input, empty, ':');
	input >> borrowDate;

	getline(input, empty, ':');
	input >> reserveDate;

	getline(input, empty, ':');
	input >> expirationDate;

	copy.setID(ID);
	copy.setBook(bookIndex);
	copy.setReader(readerName);
	copy.setReserver(reserverName);
	copy.setAvailable(available);
	copy.setBorrowDate(borrowDate);
	copy.setReserveDate(reserveDate);
	copy.setExpirationDate(expirationDate);
	return input;
}