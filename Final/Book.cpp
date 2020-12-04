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
	output << "Reservee List: ";
	if (!book.getReserveeList().empty())
		for (int i = 0; i < book.getReserveeList().size(); i++) {
			output << book.getReserveeList()[i] << " ";
		}
	output << endl;
	output << "Number of Reservees: " << book.getNumberOfReservees() << endl;
	return output;
}

istream& operator >> (istream& input, Book& book) { // used to input file into system
	string title, author, category;
	int isbn, index, count, favor, numberOfReservees;
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

	string vectorString;
	getline(input, empty, ':');
	getline(input, vectorString);
	vectorString.push_back(' '); // necessary to find the the last element in the string
	string str1 = "";
	if (vectorString != " ")
		for (int i = 1; i < vectorString.length(); i++) { // i starts as 1 because first character is space
			if (vectorString[i] == ' ') {
				if (str1 != "") {
					book.addReserveeList(str1);
					string str1 = "";
				}
			}
			else {
				str1 += vectorString[i];
			}
		}

	getline(input, empty, ':');					//we're not retrieving a string, so they >> operator is enough
	input >> numberOfReservees;


								
	book.setISBN(isbn);
	book.setTitle(title);
	book.setAuthor(author);
	book.setCategory(category);
	book.setIndex(index);
	book.setCount(count);
	book.setFavor(favor);
	book.setNumberOfReservees(numberOfReservees);
	return input;
}

