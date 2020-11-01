#include <iostream>
#include "Book.h"
#include "Student.h"
using namespace std;

int main() {
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
	return 0;
}
