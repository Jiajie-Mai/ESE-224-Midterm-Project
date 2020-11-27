#pragma once
#include <string>
using namespace std;
class Book
{
private:
	int ISBN;
	string title;
	string author;
	string category;
	int index;
	int count;
	int favor;
public:
	Book();
	int getISBN();
	string getTitle();
	string getAuthor();
	string getCategory();
	int getIndex();
	int getCount();
	int getFavor();
	void setISBN();
	void setTitle();
	void setAuthor();
	void setCategory();
	void setIndex();
	void setCount();
	void setFavor();
};

