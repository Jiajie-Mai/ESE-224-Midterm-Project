#include "Teacher.h"

Teacher::Teacher() {

}

int Teacher::displayMenu() {
	cout << endl << endl << "Welcome back, Teacher" << endl << endl << "Please choose:" << endl << "\t1 -- Search Books" << endl << "\t2 -- Borrow Books" << endl << "\t3 -- Return Books" << endl << "\t4 -- Reserve Books" << endl << "\t5 -- Cancel Reservations" << endl << "\t6 -- My Information" << endl << "\t7 -- Change Password" << endl << "\t0 -- Log Out" << endl;
	return 2;
}