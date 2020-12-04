#include "Student.h"

Student::Student() {
	maxBorrowingPeriod = 30;
	maxCopies = 5;
}

int Student::displayMenu() {
	cout << endl << endl << "Welcome back, Student" << endl << endl << "Please choose:" << endl << "\t1 -- Search/Recommend Books" << endl << "\t2 -- Borrow Books" << endl << "\t3 -- Return Books" << endl << "\t4 -- Reserve Books" << endl << "\t5 -- Cancel Reservations" << endl << "\t6 -- My Information" << endl << "\t7 -- Change Password" << endl << "\t0 -- Log Out" << endl;
	return 2;
}