#pragma once
#include "book.h"
#include <iostream>
#include <vector>
using namespace std;
class Student
{
private:
	string username;
	string password;
	int maxCopies;
	vector<Book> borrowed;
	vector<int> borrowingPeriod;
public:
	Student();
	void operator>>(Student input);
	void operator<<(Student input);
};

