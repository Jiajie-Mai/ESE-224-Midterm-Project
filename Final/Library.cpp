#include "Library.h"

Library::Library() {

}

void Library::search(int key, string data) {

}

void Library::addBook(Book book) { //adds book to library
	books.push_back(book);
}

void Library::removeBook(int index) { // removes book from library based on index
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getIndex() == index) {
			books.erase(books.begin() + i);
		}
	}
}


void Library::addCopy(Copy copy) { //adds copy to library
	copies.push_back(copy);
}

void Library::removeCopy(int ID) { // removes copy from library based on ID
	for (int i = 0; i < books.size(); i++) {
		if (copies[i].getID() == ID) {
			copies.erase(copies.begin() + i);
		}
	}
}

void Library::addStudent(Student student) {
	students.push_back(student);
}

void Library::removeStudent(string username) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getUsername() == username) {
			students.erase(students.begin() + i);
		}
	}
}

void Library::addTeacher(Teacher teacher) {
	teachers.push_back(teacher);
}

void Library::removeTeacher(string username) {
	for (int i = 0; i < students.size(); i++) {
		if (teachers[i].getUsername() == username) {
			teachers.erase(teachers.begin() + i);
		}
	}
}

void Library::addLibrarian(Librarian librarian) {
	librarians.push_back(librarian);
}

void Library::removeLibrarian(string username) {
	for (int i = 0; i < students.size(); i++) {
		if (librarians[i].getUsername() == username) {
			librarians.erase(librarians.begin() + i);
		}
	}
}


void Library::userAuthentication(string username, string password) {
	int index = 0;
	if (!loggedIn) {
		for (Student student : students) {
			if (student.getUsername() == username && student.getPassword() == password) {
				cout << "Log in successful." << endl;
				loggedIn = true;
				userIndex = index;
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

void Library::logOut() {
	cout << "Logging Out.." << endl;
	loggedIn = false;
}

void divider(int size) {
	for (int i = 0; i < size; i++) {
		cout << "-";
	}
}

bool isNum(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			cout << "\nInvalid Input!\n" << endl;
			return false;
		}
	}
	return true;
}

void Library::menuInput(int i) {
	string input;
	int counter = 0;
	switch (i) {
	case 1:
		//for (User user : users) {
		//	if (counter == userLoggedOn) {
		//		cout << student << endl;
		//		break;
		//	}
		//	else {
		//		counter++;
		//	}
		//}
		break;
	case 2:
		//cout << "Input an ISBN in order to borrow it: ";
		//cin >> input;
		//if (isNum(input)) {
		//	for (User user : users) {
		//		if (counter == studentLoggedOn) {
		//			borrowBook(user, stoi(input));
		//			break;
		//		}
		//		else {
		//			counter++;
		//		}
		//	}
		//}
		break;
	case 3:
		//cout << "Input an ID in order to return it: ";
		//cin >> input;
		//if (isNum(input)) {
		//	for (User user : users) {
		//		if (counter == userLoggedOn) {
		//			returnBook(user, stoi(input));
		//			break;
		//		}
		//		else {
		//			counter++;
		//		}
		//	}
		//}
		break;
	case 0:
		logOut();
		break;
	default:
		cout << "\nInvalid Input!\n" << endl;
		break;
	}
}

void Library::displayMenu() {
	if (loggedIn) {
		string input;
		divider(50);
		//user.displayMenu();
		cout << endl << "-             Welcome to My Library!             -" << endl;
		divider(50);
		cin >> input;

		if (isNum(input)) {
			menuInput(stoi(input));
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

void Library::addBooks() {
}

void Library::deleteBook() {

}

void Library::searchUsers() {

}

// needs an update
void Library::addUser() {
	cout << "Type:\n\t1-Student\n\t2-Teacher\n\t3-Librarian" << endl;
	string input;
	string username, password;
	cin >> input;
	if (isNum(input)) {
		switch (stoi(input)) {
		case 1:
			cout << "Input username" << endl;
			cin >> username;
			cout << "Input password" << endl;
			cin >> password;
			Student student;
			student.setUsername(username);
			student.setPassword(password);
			students.push_back(student);
			break;
		}
	}
}

void Library::deleteUser() {

}


void Library::readFiles() { 
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

	ifstream fin5;
	fin5.open("copy.txt");
	if (fin5.fail()) {
		cerr << "Cannot find file copy.txt." << endl;
		exit(1);
	}
	while (!fin5.eof()) {
		Copy copy;
		fin5 >> copy;
		if (!copy.getReader().empty()) 
			addCopy(copy);
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
		if (!student.getUsername().empty())
			addStudent(student);
	}
	fin2.close();

	ifstream fin3;
	fin3.open("teacher.txt");
	if (fin3.fail()) {
		cerr << "Cannot find file teacher.txt." << endl;
		exit(1);
	}
	while (!fin3.eof()) {
		Teacher teacher;
		fin3 >> teacher;
		if (!teacher.getUsername().empty())
			addTeacher(teacher);
	}
	fin3.close();

	ifstream fin4;
	fin4.open("librarian.txt");
	if (fin4.fail()) {
		cerr << "Cannot find file librarian.txt." << endl;
		exit(1);
	}
	while (!fin4.eof()) {
		Librarian librarian;
		fin4 >> librarian;
		if (!librarian.getUsername().empty())
			addLibrarian(librarian);
	}
	fin4.close();
}
void Library::writeFiles() {
	ofstream fout1;
	fout1.open("book.txt");
	if (fout1.fail()) {
		cerr << "Cannot find file book.txt." << endl;
		exit(1);
	}
	int vector_size = books.size();
	for (int i = 0; i < vector_size; i++) {
		fout1 << books[i];
	}
	fout1.close();

	ofstream fout5;
	fout5.open("copy.txt");
	if (fout5.fail()) {
		cerr << "Cannot find file copy.txt." << endl;
		exit(1);
	}
	vector_size = copies.size();
	for (int i = 0; i < vector_size; i++) {
		fout5 << copies[i];
	}
	fout5.close();

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

	ofstream fout3;
	fout3.open("teacher.txt");
	if (fout3.fail()) {
		cerr << "Cannot find file teacher.txt." << endl;
		exit(1);
	}
	vector_size = teachers.size();
	for (int i = 0; i < vector_size; i++) {
		fout3 << teachers[i];
	}
	fout3.close();

	ofstream fout4;
	fout4.open("librarian.txt");
	if (fout4.fail()) {
		cerr << "Cannot find file librarian.txt." << endl;
		exit(1);
	}
	vector_size = librarians.size();
	for (int i = 0; i < vector_size; i++) {
		fout4 << librarians[i];
	}
	fout4.close();


}
