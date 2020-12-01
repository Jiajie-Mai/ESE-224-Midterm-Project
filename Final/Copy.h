#pragma once
#include <ctime>
#include "Book.h"
#include "Reader.h"

extern clock_t t_start;

class Copy
{
private:
	int ID;
	/*
	Book book;
	Reader reader;
	Reader reserver;
	*/
	int bookIndex; // refers to book
	string readerName; // refers to reader
	string reserverName; // refers to reserver
	bool available;
	int borrowDate;
	int reserveDate;
	int expirationDate;
public:
	int getID();
	/* // if you have any idea how to code this, try it
	Book* getBook();
	Reader* getReader();
	Reader* getReserver();
	*/
	int getBook();
	string getReader();
	string getReserver();
	bool getAvailable();
	int getBorrowDate();
	int getReserveDate();
	int getExpirationDate();

	void setID(int ID);
	void setBook(int bookIndex);
	void setReader(string readerName);
	void setReserver(string ReserverName);
	void setAvailable(bool available);
	void setBorrowDate(int borrowDate);
	void setReserveDate(int reserveDate);
	void setExpirationDate(int expirationDate);

	// date counter
	int returnDay();	// returns day (day 1 begins once program starts)

	// file operations
	friend ostream& operator<< (ostream& output, Copy& copy);
	friend istream& operator>> (istream& input, Copy& copy);
};

