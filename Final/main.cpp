#include "Library.h"
using namespace std;

void initialize() {
	Library LMS;
	LMS.readFiles();
	LMS.printBooks();
	LMS.printCopies();
	LMS.printStudents();
	LMS.printLibrarians();
	LMS.printTeachers();
	/*
	LMS.addBooks(1111, "Twilight", "Stephanie Meyer", "Fantasy");
	LMS.addBooks(1111, "Twilight", "J.K. Rowling", "Fantasy");
	LMS.addBooks(1115, "Harry Potter and the Goblet of Fire", "J. K. Rowling", "Fantasy");
	LMS.deleteBook(3);
	LMS.deleteBook(4);
	LMS.deleteBook(5);
	*/
	LMS.searchUsers("AzureDiamond");
	LMS.searchUsers("teacher");
	LMS.searchUsers("librarian2");
	LMS.searchUsers("azurediamond");
	LMS.writeFiles();
	
	LMS.displayMenu();
}

int main() {
	initialize();
	return 0;
}
