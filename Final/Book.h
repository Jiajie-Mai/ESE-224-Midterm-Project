#pragma once
#include <iostream>
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
	void setISBN(int ISBN);
	void setTitle(string title);
	void setAuthor(string author);
	void setCategory(string category);
	void setIndex(int index);
	void setCount(int count);
	void setFavor(int favor);


	friend ostream& operator<< (ostream& output, Book& book);
	friend istream& operator>> (istream& input, Book& book);
};
