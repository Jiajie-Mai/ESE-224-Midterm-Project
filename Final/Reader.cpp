#include "Reader.h"

Reader::Reader() {
	maxCopies = 4;
	maxBorrowingPeriod = 30;
	penalties=0;
}

int Reader::getMaxCopies() {
	return maxCopies;
}

int Reader::getMaxBorrowingPeriod() {
	return maxBorrowingPeriod;
}

int Reader::getPenalties() {
	return penalties;
}

vector<int> Reader::getBorrowed() {
	return borrowed;
}


vector<int> Reader::getReserved() {
	return reserved;
}

void Reader::setMaxCopies(int maxCopies) {
	this->maxCopies = maxCopies;
}

void Reader::setMaxBorrowingPeriod(int maxBorrowingPeriod) {
	this->maxBorrowingPeriod = maxBorrowingPeriod;
}

void Reader::setPenalties(int penalties) {
	this->penalties = penalties;
}

void Reader::addBorrowed(int ID) {
	borrowed.push_back(ID);
}


void Reader::addReserved(int index) {
	reserved.push_back(index);
}

void overdue() {

}

void Reader::borrowBook(int index) {

}

void Reader::returnBook(int index) {

}

void Reader::reserveBook(int ID) {

}

void Reader::cancelReservation(int ID) {

}

void Reader::renewBook(int index) {
	if (reserved.size() == 0 && ) {

	}
}

int Reader::displayMenu() {
	cout << endl << endl << "Welcome back, Reader" << endl << endl << "Please choose:" << endl << "\t0 -- Log Out" << endl;
	return 0;
}

ostream& operator<< (ostream& output, Reader& reader) { //write to file
	output << "Username: " << reader.getUsername() << endl;
	output << "Password: " << reader.getPassword() << endl;
	output << "Max Copies: " << reader.getMaxCopies() << endl;
	output << "Max Borrowing Period: " << reader.getMaxBorrowingPeriod() << endl;
	output << "IDs of Borrowed Copies: ";
	for (int i = 0; i < reader.getBorrowed().size(); i++) {
		output << reader.getBorrowed()[i] << " ";
	}
	output << endl;
	output << "Indexes of Reserved Books: ";
	for (int i = 0; i < reader.getReserved().size(); i++) {
		output << reader.getReserved()[i] << " ";
	}
	output << endl;
	output << "Penalties: " << reader.getPenalties() << endl;
	return output;
}
istream& operator>> (istream& input, Reader& reader) { // read from file
	string readerName, username, password;
	int maxCopies, maxBorrowingPeriod, penalties;
	string empty;
	string vectorString;
	getline(input, empty, ':'); // gets rid of the part of the line before the ':'
	getline(input, username); // inputs the rest of the line, which is the name
	username.erase(username.begin()); //removes first character since it is a space

	getline(input, empty, ':');
	getline(input, password);
	password.erase(password.begin());

	getline(input, empty, ':');
	input >> maxCopies;

	getline(input, empty, ':');
	input >> maxBorrowingPeriod;

	getline(input, empty, ':');
	getline(input, vectorString);
	vectorString.push_back(' '); // necessary to find the the last number in the string
	string str1 = "";
	for (int i = 1; i < vectorString.length(); i++) { // i starts as 1 because first character is space
		if (vectorString[i] == ' ') {
			if (str1 != "") {
				int book_id = stoi(str1);
				str1 = "";
				reader.addBorrowed(book_id);
			}
		}
		else {
			str1 += vectorString[i];
		}
	}
	
	getline(input, empty, ':');
	getline(input, vectorString);
	vectorString.push_back(' '); // necessary to find the the last number in the string
	string str2 = "";
	for (int i = 1; i < vectorString.length(); i++) { // i starts as 1 because first character is space
		if (vectorString[i] == ' ') {
			if (str2 != "") {
				int reservedIndex = stoi(str2);
				str2 = "";
				reader.addReserved(reservedIndex);
			}
		}
		else {
			str2 += vectorString[i];
		}
	}

	getline(input, empty, ':');
	input >> penalties;
	

	reader.setUsername(username);
	reader.setPassword(password);
	reader.setMaxCopies(maxCopies);
	reader.setMaxBorrowingPeriod(maxBorrowingPeriod);
	reader.setPenalties(penalties);
	return input;

}

