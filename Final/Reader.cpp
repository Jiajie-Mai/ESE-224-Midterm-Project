#include "Reader.h"

Reader::Reader() {

}

int Reader::getMaxCopies() {
	return 1;
}

int Reader::getMaxBorrowingPeriod() {
	return 1;
}

int Reader::getPenalties() {
	return 1;
}

vector<int> Reader::getBorrowed() {
	vector<int> yeah;
	return yeah;
}

vector<int> Reader::getBorrowingPeriod() {
	vector<int> yeah;
	return yeah;
}

vector<int> Reader::getReserved() {
	vector<int> yeah;
	return yeah;
}

void Reader::setMaxCopies() {

}

void Reader::setMaxBorrowingPeriod() {

}

void Reader::setPenalties() {

}

void Reader::addBorrowed() {

}

void Reader::addBorrowingPeriod() {

}

void Reader::addReserved() {

}

void Reader::borrowBook() {

}

void Reader::returnBook() {

}

void Reader::reserveBook() {

}

void Reader::cancelReservation() {

}

void Reader::renewBook() {

}

int Reader::displayMenu() {
	cout << endl << endl << "Welcome back, Reader" << endl << endl << "Please choose:" << endl << "\t0 -- Log Out" << endl;
	return 0;
}