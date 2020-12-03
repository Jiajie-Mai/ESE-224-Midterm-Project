#include "Book.h"

Book::Book() {

}

int Book::getISBN() {
	return ISBN;
}

string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

string Book::getCategory() {
	return category;
}

int Book::getIndex() {
	return index;
}

int Book::getCount() {
	return count;
}

int Book::getFavor() {
	return favor;
}

vector<string> Book::getReserveeList() {
	return reserveeList;
}

int Book::getNumberOfReservees() {
	return numberOfReservees;
}

void Book::setISBN(int ISBN) {
	this->ISBN = ISBN;
}

void Book::setTitle(string title) {
	this->title = title;
}

void Book::setAuthor(string author) {
	this->author = author;
}

void Book::setCategory(string category) {
	this->category = category;
}
void Book::setIndex(int index) {
	this->index = index;
}

void Book::setCount(int count) {
	this->count = count;
}

void Book::setFavor(int favor) {
	this->favor = favor;
}

void Book::addReserveeList(string username) {
	reserveeList.push_back(username);
}

void Book::setNumberOfReservees(int numberOfReservees) {
	this->numberOfReservees = numberOfReservees;
}

void Book::eraseReservee(string username) {
	int index = 0;
	for (string s : reserveeList) {
		if (username == s) {
			reserveeList.erase(reserveeList.begin() + index);
		}
		index++;
	}
}

ostream& operator << (ostream& output, Book& book) { // used to output file from system
	output << "ISBN: " << book.getISBN() << endl;
	output << "Title: " << book.getTitle() << endl;
	output << "Author: " << book.getAuthor() << endl;
	output << "Category: " << book.getCategory() << endl;
	output << "Index: " << book.getIndex() << endl;
	output << "Count: " << book.getCount() << endl;
	output << "Favor: " << book.getFavor() << endl;
	return output;
}

istream& operator >> (istream& input, Book& book) { // used to input file into system
	string title, author, category;
	int isbn, index, count, favor;
	string empty;

	getline(input, empty, ':');					//we're not retrieving a string, so they >> operator is enough
	input >> isbn;

	getline(input, empty, ':');					//we only want the title, so we remove the other parts of the line
	getline(input, title);						//we repeat this for every string
	title.erase(title.begin());					// first letter is an empty space, so we remove it

	getline(input, empty, ':');
	getline(input, author);
	author.erase(author.begin());

	getline(input, empty, ':');
	getline(input, category);
	category.erase(category.begin());

	getline(input, empty, ':');					//we're not retrieving a string, so they >> operator is enough
	input >> index;

	getline(input, empty, ':');					//we're not retrieving a string, so they >> operator is enough
	input >> count;

	getline(input, empty, ':');					//we're not retrieving a string, so they >> operator is enough
	input >> favor;


								
	book.setISBN(isbn);
	book.setTitle(title);
	book.setAuthor(author);
	book.setCategory(category);
	book.setIndex(index);
	book.setCount(count);
	book.setFavor(favor);
	return input;
}

