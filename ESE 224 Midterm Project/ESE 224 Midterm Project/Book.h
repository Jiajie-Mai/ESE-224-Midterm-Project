#pragma once
#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
	int ISBN;
	string Title;
	string Author;
	string Category;
	int ID;
	string studentName;
	int	startDate;
	int expirationDate;
public:
	//constructors
	Book();
	Book(int ISBN, string Title, string Author, string Category, int ID, string studentName, int startDate, int expirationDate);

	// accessor functions
	int getISBN();
	string getTitle();
	string getAuthor();
	string getCategory();
	int getID();
	string getStudent();
	int getStartDate();
	int getExpirationDate();
	

	// mutator functions
	void setISBN(int ISBN);
	void setTitle(string Title);
	void setAuthor(string Author);
	void setCategory(string Category);
	void setID(int ID);
	void setStudent(string studentName);
	void setStartDate(int startDate);
	void setExpirationDate(int expirationDate);


	friend ostream& operator<< (ostream& output, Book& book);
	friend istream& operator>> (istream& input, Book& book);



};

