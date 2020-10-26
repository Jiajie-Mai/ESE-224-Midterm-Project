#pragma once
#include <iostream>
using namespace std;
class Book
{
private:
	int ISBN;
	string Title;
	string author;
	string Category;
	int ID;
	string readerName;
	int	startDate[3];
	int expirationDate[3];
public:
	Book();
	void operator>>(Book input);
	void operator<<(Book input);
};

