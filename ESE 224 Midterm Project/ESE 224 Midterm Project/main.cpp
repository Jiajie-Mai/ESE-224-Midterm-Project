#include <iostream>
#include "Book.h"
#include "Student.h"
#include "Library.h"
using namespace std;

void initialize();

int main() {
	initialize();
	return 0;
}

void initialize() {
	LMS Library;
	Library.readFiles();
	Library.printStudents();
	Library.printStudents();
	Library.writeFiles();
	Library.displayMenu();
}