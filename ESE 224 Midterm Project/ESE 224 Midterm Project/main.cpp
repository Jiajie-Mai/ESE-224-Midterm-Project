#include <iostream>
#include "Book.h"
#include "Student.h"
#include "Library.h"
using namespace std;

int main() {
	string usernameInput, passwordInput;
	//cin >> book1;
	//cout << book1;
	/* Date testing
	int currentDay = 0;
	while (1) {
		if (currentDay != student1.returnDay()) {
			currentDay = student1.returnDay();
			cout << "It is day " << student1.returnDay() << endl;
		}
	}
	*/

	/*
	//for testing for now
	Book book1, book2; 
	Student student1;
	string usernameInput, passwordInput;
	int isbn;
	//cin >> book1;
	//cout << book1;
	cout << "Input username, password, and max copies and then type in another username and input to check the authentication" << endl;
	cin >> student1 >> usernameInput >> passwordInput;
	if (student1.authenticate(usernameInput, passwordInput)) { 
		student1.displayMenu(); 
		cout << endl << endl << student1; 
	}
	else {
		cout << "Incorrect username/password";
	}
	*/

	
	LMS Library;
	Library.readFiles();
	//Library.printLibrary();
	//.removeBook(1113);
	//cin >> book1;
	//Library.addBook(book1);
	//Library.printLibrary();
	Library.printStudents();
	//Library.createNewStudent();
	Library.printStudents();
	Library.writeFiles();

	
	return 0;
}
