#pragma once
#include "Book.h"
#include "Reader.h"
class Copy
{
private:
	int id;
	Book book;
	Reader reader;
	Reader reserver;
	bool available;
	////use time object probably
	//int borrowDate;
	//int reserveDate;
	//int expirationDate;
public:
	int getID();
	Book* getBook();
	Reader* getReader();
	Reader* getReserver();
	bool getAvailable();

	void setID(int id);
	void setBook(Book book);
	void setReader(Reader reader);
	void setReserver(Reader reserver);
	void setAvailable(bool available);
};

