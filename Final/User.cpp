#include "User.h"

User::User() {

}

string User::getUsername() {
	return "1";
}

string User::getPassword() {
	return "1";
}

int User::displayMenu() {
	cout << endl << endl << "Welcome back, User" << endl << endl << "Please choose:" << endl << "\t0 -- Log Out" << endl;
	return 0;
}