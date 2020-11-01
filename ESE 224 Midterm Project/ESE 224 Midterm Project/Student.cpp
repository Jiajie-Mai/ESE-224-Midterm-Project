#include "Student.h"

Student::Student() {

}
ostream& operator<< (ostream& output, Student& student) { // add to later
	output << "\tUsername:\t\t" << student.getUsername() << endl;
	output << "\tPassword:\t\t" << student.getPassword() << endl;
	output << "\tmaxCopies:\t\t" << student.getMaxCopies() << endl;
	return output;
}
istream& operator>> (istream& input, Student& student) { // add to later
	string username, password;
	int maxCopies;
	input >> username >> password >> maxCopies;	//add more stuff later
	student.setUsername(username);
	student.setPassword(password);
	student.setMaxCopies(maxCopies);
	return input;

}

string Student::getUsername() {
	return Username;
}
string Student::getPassword() {
	return Password;
}
int Student::getMaxCopies() {
	return maxCopies;
}

// mutator functions
void Student::setUsername(string Username) {
	this->Username = Username;
}
void Student::setPassword(string Password) {
	this->Password = Password;
}
void Student::setMaxCopies(int maxCopies) {
	this->maxCopies = maxCopies;
}

// authentication functions
bool Student::authenticate(string Username, string Password) {
	return (this->Username == Username && this->Password == Password);
}
void divider(int size) {
	for (int i = 0; i < size; i++) {
		cout << "-";
	}
}
void Student::displayMenu() {
	divider(50);
	cout << endl << "-             Welcome to My Library!             -" << endl;
	divider(50);
	cout << endl << endl << "Welcome back, Student" << endl << endl << "Please choose:" << endl << "\t1 -- Borrow Books" << endl << "\t3 -- Return Books" << endl << "\t0 -- Log Out" << endl;
}