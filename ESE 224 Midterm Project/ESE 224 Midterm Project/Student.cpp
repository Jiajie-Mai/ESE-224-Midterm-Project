#include "Student.h"

clock_t t_start = clock();

Student::Student() {

}

ostream& operator<< (ostream& output, Student& student) { //write to file
	output << "Student Name: " << student.getStudentName() << endl;
	output << "Username: " << student.getUsername() << endl;
	output << "Password: " << student.getPassword() << endl;
	output << "Max Copies: " << student.getMaxCopies() << endl;
	output << "IDs of Borrowed Books: ";
	for (int i = 0; i < student.borrowed.size(); i++) {
		output << student.getBorrowed()[i] << " ";
	}
	output << endl;
	output << "Length of Borrowing Period (in Days): ";
	for (int i = 0; i < student.borrowingPeriod.size(); i++) {
		output << student.borrowingPeriod[i] << " ";
	}
	output << endl;
	return output;
}
istream& operator>> (istream& input, Student& student) { // read from file
	string studentName, username, password;
	int maxCopies;
	string empty;
	string vectorString;
	getline(input, empty, ':'); // gets rid of the part of the line before the ':'
	getline(input, studentName); // inputs the rest of the line, which is the name
	studentName.erase(studentName.begin()); //removes first character since it is a space

	getline(input, empty, ':'); 
	getline(input, username); 
	username.erase(username.begin()); 

	getline(input, empty, ':');
	getline(input, password);
	password.erase(password.begin());

	getline(input, empty, ':');
	input >> maxCopies;

	getline(input, empty, ':');
	getline(input, vectorString);
	vectorString.push_back(' '); // necessary to find the the last number in the string
	string str1="";
	for (int i = 1; i < vectorString.length(); i++) { // i starts as 1 because first character is space
		if (vectorString[i] == ' ') {
			if (str1 != "") {
				int book_id = stoi(str1);
				str1 = "";
				student.setBorrowed(book_id);
			}
		}
		else {
			str1 += vectorString[i];
		}
	}

	getline(input, empty, ':');
	getline(input, vectorString);
	vectorString.push_back(' '); // necessary to find the the last number in the string
	string str2 = "";
	for (int i = 1; i < vectorString.length(); i++) { // i starts as 1 because first character is space
		if (vectorString[i] == ' ') {
			if (str2 != "") {
				int borrowing_period = stoi(str2);
				str2 = "";
				student.setBorrowingPeriod(borrowing_period);
			}
		}
		else {
			str2 += vectorString[i];
		}
	}


	student.setStudentName(studentName);
	student.setUsername(username);
	student.setPassword(password);
	student.setMaxCopies(maxCopies);
	return input;

}

string Student::getStudentName() {
	return studentName;
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
vector<int> Student::getBorrowed() {
	return borrowed;
}
vector<int> Student::getBorrowingPeriod() {
	return borrowingPeriod;
}

// mutator functions
void Student::setStudentName(string studentName) {
	this->studentName = studentName;
}
void Student::setUsername(string Username) {
	this->Username = Username;
}
void Student::setPassword(string Password) {
	this->Password = Password;
}
void Student::setMaxCopies(int maxCopies) {
	this->maxCopies = maxCopies;
}

void Student::setBorrowed(int ID) {
	borrowed.push_back(ID);
}
void Student::setBorrowingPeriod(int date) {
	borrowingPeriod.push_back(date);
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

void Student::borrowBook(LMS library, int ISBN) {
	if (!library.copiesAvaliable(ISBN)) {
		cout << "This book is either currently being borrowed or does not exist!" << endl;
	} else if(overdue) {

	}

	else {
		library.borrowBook(ISBN);
	}
}

void Student::returnBook(LMS library, int ISBN) {

}

int Student::returnDay() { // returns day
	clock_t t_difference = clock() - t_start; // this is used to find current time
	float seconds = t_difference / CLOCKS_PER_SEC;
	int day = seconds / 5 + 1; ;// We add 1 because the day starts at Day 1
	return day;
}
