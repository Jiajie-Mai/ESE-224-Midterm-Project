#include "Librarian.h"

Librarian::Librarian() {

}

int Librarian::displayMenu() {
	cout << endl << endl << "Welcome back, Librarian" << endl << endl << "Please choose:" << endl << "\t1 -- Search/Recommend Books" << endl << "\t2 -- Add Books" << endl << "\t3 -- Delete Books" << endl << "\t4 -- Search Users" << endl << "\t5 -- Add Users" << endl << "\t6 -- Delete Users" << endl << "\t7 -- Display information" << endl << "\t8 -- Change Password" << endl << "\t0 -- Log Out" << endl;
	return 1;
}