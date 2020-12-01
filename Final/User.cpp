#include "User.h"

User::User() {

}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

void User::setUsername(string username) {
	this->username = username;
}

void User::setPassword(string password) {
	this->password = password;
}

int User::displayMenu() {
	cout << endl << endl << "Welcome back, User" << endl << endl << "Please choose:" << endl << "\t0 -- Log Out" << endl;
	return 0;
}

ostream& operator<< (ostream& output, User& user) { //write to file
	output << "Username: " << user.getUsername() << endl;
	output << "Password: " << user.getPassword() << endl;
	return output;
}
istream& operator>> (istream& input, User& user) { // read from file
	string username, password;
	string empty;
	getline(input, empty, ':'); // gets rid of the part of the line before the ':'
	getline(input, username); // inputs the rest of the line, which is the name
	username.erase(username.begin()); //removes first character since it is a space

	getline(input, empty, ':');
	getline(input, password);
	password.erase(password.begin());

	user.setUsername(username);
	user.setPassword(password);
	return input;

}