#pragma once
#include <iostream>
#include <vector>
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
	vector<string> reserveeList;
public:
	Book();
	int getISBN();
	string getTitle();
	string getAuthor();
	string getCategory();
	int getIndex();
	int getCount();
	int getFavor();
	vector<string> getReserveeList();
	void setISBN(int ISBN);
	void setTitle(string title);
	void setAuthor(string author);
	void setCategory(string category);
	void setIndex(int index);
	void setCount(int count);
	void setFavor(int favor);
	void addReserveeList(string username);

	friend ostream& operator<< (ostream& output, Book& book);
	friend istream& operator>> (istream& input, Book& book);
};
