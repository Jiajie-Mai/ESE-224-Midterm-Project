#pragma once
#include <string>
#include <vector>
#include "User.h"
using namespace std;
class Reader : public User
{
private:
	int maxCopies;
	int maxBorrowingPeriod;
	int penalties;
	vector<int> borrowed;
	vector<int> borrowingPeriod;
	vector<int> reserved;
public:
	Reader();
	int getMaxCopies();
	int getMaxBorrowingPeriod();
	int getPenalties();
	vector<int> getBorrowed();
	vector<int> getBorrowingPeriod();
	vector<int> getReserved();
	void setMaxCopies();
	void setMaxBorrowingPeriod();
	void setPenalties();
	void addBorrowed();
	void addBorrowingPeriod();
	void addReserved();
	void borrowBook();
	void returnBook();
	void reserveBook();
	void cancelReservation();
	void renewBook();
	int displayMenu();
};

