#pragma once
#include <string>
#include <vector>
#include "User.h"
using namespace std;
class Reader : public User
{
protected:
	//username handled in user
	//password handled in user
	int maxCopies;
	int maxBorrowingPeriod; // max days that a reader is allowed to keep
	vector<int> borrowed; //list of copies borrowed
	vector<int> reserved; // list of books reserved
	int penalties;
public:
	Reader();

	// acccessor functions
	int getMaxCopies();
	int getMaxBorrowingPeriod();
	int getPenalties();
	vector<int> getBorrowed();
	vector<int> getReserved();

	// mutator functions
	void setMaxCopies(int maxCopies);
	void setMaxBorrowingPeriod(int maxBorrowingPeriod);
	void setPenalties(int penalties);

	void addBorrowed(int ID); // ID refers to copy
	void addReserved(int id);

	bool returnBook(int id); // helper funciton for the returnBook function in library
	bool cancelReserve(int id); // helper funciton for the cancelReservation function in library

	// file operations
	friend ostream& operator<< (ostream& output, Reader& reader);
	friend istream& operator>> (istream& input, Reader& reader);


	int displayMenu(); // default display menu for a generic reader
};

