#include "Library.h"
#include "Student.h"
#include <iostream>

LMS::LMS() {
	loggedIn = false;
}

void LMS::readFiles() { // reads to library from book.txt
	ifstream fin1;
	fin1.open("book.txt");
	if (fin1.fail()) {
		cerr << "Cannot find file book.txt." << endl;
		exit(1);
	}
	while (!fin1.eof()) {
		Book temp;
		fin1 >> temp;
		if (!temp.getTitle().empty()) // if the title is not empty ( meaning we didn't read an empty line)
			addBook(temp);
	}

	fin1.close();
	
	ifstream fin2;
	fin2.open("student.txt");
	if (fin2.fail()) {
		cerr << "Cannot find file student.txt." << endl;
		exit(1);
	}
	while (!fin2.eof()) {
		Student student;
		fin2 >> student;
		if(!student.getUsername().empty())
			addStudent(student);
	}
	fin2.close();
}
void LMS::writeFiles() { // writes to book.txt from library
	ofstream fout1;
	fout1.open("book.txt");
	if (fout1.fail()) {
		cerr << "Cannot find file book.txt." << endl;
		exit(1);
	}
	int vector_size = library.size();
	for (int i = 0; i < vector_size; i++) {
		fout1 << library[i];
	}
	fout1.close();
	ofstream fout2;
	fout2.open("student.txt");
	if (fout2.fail()) {
		cerr << "Cannot find file student.txt." << endl;
		exit(1);
	}
	vector_size = students.size();
	for (int i = 0; i < vector_size; i++) {
		fout2 << students[i];
	}
	fout2.close();
}

void LMS::printLibrary() {
	for (int i = 0; i < library.size(); i++) {
		cout << library[i];
	}
}

void LMS::printStudents() {
	for (int i = 0; i < students.size(); i++) {
		cout << students[i];
	}
}

void LMS::addBook(Book book) { //adds book to library
	library.push_back(book);
}

Book LMS::findBook(int ID) { // finds book based on ID
	for (int i = 0; i < library.size(); i++) {
		if (library[i].getID() == ID)
			return library[i];
	}
}

void LMS::removeBook(int ID) { // removes book from library based on ID
	for (int i = 0; i < library.size(); i++) {
		if (library[i].getID() == ID) {
			library.erase(library.begin()+i);
		}
	}
}

void LMS::addStudent(Student student) {
	students.push_back(student);
}

void LMS::removeStudent(string username) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getUsername() == username) {
			students.erase(students.begin() + i);
		}
	}
}

void LMS::createNewStudent() {
	string studentName, Username, Password;
	int maxCopies;
	Student newStudent;
	cout << "Write a student name: ";
	cin >> studentName;
	cout << "Write a Username: ";
	cin >> Username;
	cout << "Write a Password: ";
	cin >> Password;
	cout << "Add Max Copies: ";
	cin >> maxCopies;
	newStudent.setStudentName(studentName);
	newStudent.setUsername(Username);
	newStudent.setPassword(Password);
	newStudent.setMaxCopies(maxCopies);
	addStudent(newStudent);
}

Book LMS::recommendBooks(Book Book) {
	while (1) {
		int vector_size = library.size();
		int rand_index = rand_int(0, vector_size-1);
		if ((library[rand_index].getCategory() == Book.getCategory()) && (library[rand_index].getISBN() != Book.getISBN())) { // if they're not the same book
			return library[rand_index];
		}
	}
	
}

int LMS::rand_int(int a, int b) { // random int from a to b
	srand(1234);
	return rand() % (b - a + 1) + a;
}

bool overdue(Student student) {
	bool overdue = false;
	cout << "hi" << endl;
	int current_day = student.returnDay();
	for (int day : student.getBorrowingPeriod()) {
		cout << "hi" << endl;
		cout << current_day << day << endl;
		if (current_day > day) {
			return true;
		}
	}
	return overdue;
}

void LMS::borrowBook(Student student, int ISBN) {
	if (overdue) {
		cout << "Student " << student.getStudentName() << " has some books that are overdue." << endl;
	}
	else if (student.getBorrowed().size() <= student.getMaxCopies()) {
		cout << "Student " << student.getStudentName() << " has too many books borrowed." << endl;
	}
	else {
		int deadline = student.returnDay() + 30;
		student.setBorrowed(ISBN);
		student.setBorrowingPeriod(deadline);
	}
}

void LMS::returnBook(Student student, int ID) {
	student.returnBook(ID);
}

void LMS::userAuthentication(string username, string password) {
	int index = 0;
	if (!loggedIn) {
		for (Student student : students) {
			if (student.getUsername() == username && student.getPassword() == password) {
				cout << "Log in successful." << endl;
				loggedIn = true;
				studentLoggedOn = index;
				break;
			}
			index++;
		}
	}
	if (!loggedIn) {
		cout << "Logged in failed, try again." << endl;
		displayMenu();
	}
	else {
		displayMenu();
	}
}

void LMS::logOut() {
	cout << "Logging Out.." << endl;
	loggedIn = false;
}

void divider(int size) {
	for (int i = 0; i < size; i++) {
		cout << "-";
	}
}

void LMS::displayMenu() {
	int counter = 0;
	students.begin();
	if (loggedIn) {
		int input;
		divider(50);
		cout << endl << "-             Welcome to My Library!             -" << endl;
		divider(50);
		cout << endl << endl << "Welcome back, Student" << endl << endl << "Please choose:" << endl << "\t1 -- User Information\n\t2 -- Borrow Books" << endl << "\t3 -- Return Books" << endl << "\t0 -- Log Out" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
		while (cin.fail()) {
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;	
		}
		switch (input) {
		case 1:
			for (Student student : students) {
				if (counter == studentLoggedOn) {
					cout << student << endl;
					break;
				}
				else {
					counter++;
				}
			}
			cout << studentLoggedOn << endl;
			break;
		case 2:
			cout << "Input an ISBN in order to borrow it: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;
			for (Student student : students) {
				if (counter == studentLoggedOn) {
					borrowBook(student, input);
					break;
				}
				else {
					counter++;
				}
			}
			break;
		case 3:
			cout << "Input an ID in order to return it: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;
			for (Student student : students) {
				if (counter == studentLoggedOn) {
					returnBook(student, input);
					break;
				}
				else {
					counter++;
				}
			}
		case 0:
			logOut();
		default:
			break;
		}
		displayMenu();
	}
	else {
		string username, password;
		cout << "Input username and password to continue.\nUsername: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		userAuthentication(username, password);
	}
}