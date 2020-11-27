#include "Library.h"

Library::Library() {

}

void Library::search(int key, string data) {

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