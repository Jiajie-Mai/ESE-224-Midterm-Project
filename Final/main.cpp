#include "Library.h"
using namespace std;

void initialize() {
	Library LMS;
	LMS.readFiles();
	/*
	LMS.printBooks();
	LMS.printCopies();
	LMS.printStudents();
	LMS.printLibrarians();
	LMS.printTeachers();
	*/
	LMS.writeFiles();
	LMS.displayMenu();
}

int main() {
	initialize();
	return 0;
}
