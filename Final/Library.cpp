#include "Library.h"

Library::Library() {

}

vector<Book> Library::getBooks() {
	return books;
}

vector<Copy> Library::getCopies() {
	return copies;
}

vector<Student> Library::getStudents() {
	return students;
}

vector<Teacher> Library::getTeachers() {
	return teachers;
}


vector<Librarian> Library::getLibrarians() {
	return librarians;
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

Student* Library::getStudent(string username) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getUsername() == username) {
			return &students[i];
		}
	}
	return NULL;
}

void Library::updateStudent(Student student) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getUsername() == student.getUsername()) {
			students[i] = student;
		}
	}
}

void Library::addTeacher(Teacher teacher) {
	teachers.push_back(teacher);
}

void Library::removeTeacher(string username) {
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getUsername() == username) {
			teachers.erase(teachers.begin() + i);
		}
	}
}

Teacher* Library::getTeacher(string username) {
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getUsername() == username) {
			return &teachers[i];
		}
	}
	return NULL;
}

void Library::updateTeacher(Teacher teacher) {
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getUsername() == teacher.getUsername()) {
			teachers[i] = teacher;
		}
	}
}

void Library::addLibrarian(Librarian librarian) {
	librarians.push_back(librarian);
}

void Library::removeLibrarian(string username) {
	for (int i = 0; i < librarians.size(); i++) {
		if (librarians[i].getUsername() == username) {
			librarians.erase(librarians.begin() + i);
		}
	}
}

Librarian* Library::getLibrarian(string username) {
	for (int i = 0; i < librarians.size(); i++) {
		if (librarians[i].getUsername() == username) {
			return &librarians[i];
		}
	}
	return NULL;
}

void Library::userAuthentication(string username, string password) { // used to check if the username and password matches a user
	if (!loggedIn) {
		int index = 0;
		for (Librarian librarian : librarians) { // checks librarian vector for a user that matches the credentials
			if (librarian.getUsername() == username && librarian.getPassword() == password) {
				cout << "\nLog in successful." << endl;
				loggedIn = true;
				userIndex = index;
				userType = 0;
				break;
			}
			index++;
		}
		index = 0;
		for (Teacher teacher : teachers) { // checks teachers vector for a user that matches the credentials
			if (teacher.getUsername() == username && teacher.getPassword() == password) {
				cout << "\nLog in successful." << endl;
				loggedIn = true;
				userIndex = index;
				userType = 1;
				break;
			}
			index++;
		}
		index = 0;
		for (Student student : students) { // checks students vector for a user that matches the credentials
			if (student.getUsername() == username && student.getPassword() == password) {
				cout << "\nLog in successful." << endl;
				loggedIn = true;
				userIndex = index;
				userType = 2;
				break;
			}
			index++;
		}
	}
	if (!loggedIn) { // if no user is logged in after credentials are checked, the login has failed
		cout << "Logged in failed, try again." << endl;
		displayMenu(); // loop 
	}
	else { // else, clear screen for tidiness
		system("cls");
		displayMenu();
	}
}

void Library::logOut() {
	cout << "Logging Out.." << endl;
	loggedIn = false;
}

void divider(int size) { // used for the title of the menu
	for (int i = 0; i < size; i++) {
		cout << "-";
	}
}

bool isNum(string input) { // checks if all characters in the input are numbers, does not work if input is a negative number because of the '-' character
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			cout << "\nInvalid Input!\n" << endl;
			return false;
		}
	}
	return true;
}

void Library::menuInput(int i) { // switch case to determine which operation the user wants
	string input;
	int counter = 0;
	switch (i) { 
	case 1: // search/recommend books for all users
		cout << "Do you want to search books to find recommended books?\n(1) - Search Books\n(2) - Recommend Books" << endl;
		cin >> input;
		if (isNum(input)) {
			if (stoi(input) == 1) { // search if input is 1
				searchBooks();
			}
			else if (stoi(input) == 2) { // recommend if input is 2
				recommendBooks();
			}
		}
		break;
	case 2: // borrow/renew books for reader or add book if librarian
		if (userType != 0) { // if user is reader
			cout << "Do you want to borrow or renew books?\n(1) - Borrow Books\n(2) - Renew Books" << endl;
			cin >> input;
			if (isNum(input)) { // checks if the reader wants to borrow or renew
				if (stoi(input) == 1) { // borrow if input is 1
					cout << "Input an ISBN in order to borrow it: ";
					cin >> input;
					if (isNum(input)) {
						borrowBook(stoi(input));
					}
				} 
				else if (stoi(input) == 2) { // renew if input is 2
					cout << "Input an ID to renew it: ";
					cin >> input;
					if (isNum(input)) {
						renewBook(stoi(input));
					}
				}
			}
		}
		else { // if user is librarian
			int ISBN = 0;
			string title, author, category, empty;
			cout << "Input the ISBN of the book: " << endl;
			cin >> input;
			if (isNum(input)) {

				ISBN = stoi(input);
				cout << "Input the title of the book: " << endl;
				getline(cin, empty); // eats enter input
				getline(cin, title);
				cout << "Input the author of the book: " << endl;
				//getline(cin, empty);
				getline(cin, author);
				cout << "Input the category of the book: " << endl;
				//getline(cin, empty);
				getline(cin, category);
				addBooks(ISBN, title, author, category);
			}
		}
		break;
	case 3: // return if user is reader or delete if user is librarian
		if (userType != 0) { // if user is reader
			cout << "Input an ID in order to return it: ";
			cin >> input;
			if (isNum(input)) {
				returnBook(stoi(input));
			}
		}
		else { // if user is librarian
			cout << "Input an id of a copy to delete it: " << endl;
			cin >> input;
			if (isNum(input)) {
				deleteBook(stoi(input));
			}
		}
		break;
	case 4: // reserve if user is reader or search user if user is librarian
		if (userType != 0) { // if user is reader
			cout << "Input an ISBN to reserve a copy: " << endl;
			cin >> input;
			if (isNum(input)) {
				reserveBook(stoi(input));
			}
		}
		else { // if user is librarian
			cout << "Input a username to search the user: " << endl;
			cin >> input;
			searchUsers(input);
		}
		break;
	case 5: // cancel reservation if user is reader or add user if user is librarian
		if (userType != 0) { // if user is reader
			cout << "Input the ISBN to cancel the reservation: " << endl;
			cin >> input;
			if (isNum(input)) {
				cancelReserve(stoi(input));
			}
		}
		else { // if user is librarian
			addUser();
		}
		break;
	case 6: // information if user is reader or delete user if user is librarian
		if (userType != 0) { // if user is reader
			if (userType == 1) { // if user is teacher
				cout << teachers[userIndex] << endl;
			}
			else { // if user is students
				cout << students[userIndex] << endl;
			}
		}
		else { // if user is librarian
			deleteUser();
		}
		break;
	case 7: // change password if user or information if user is librarian
		if (userType != 0) { // if user is reader
			cout << "Input a new password:" << endl;
			cin >> input;
			cout << "Are you sure?\n(1) - yes\n(2) - no" << endl; // checks if user actually wants to change password
			cin >> input;
			if (isNum(input) && stoi(input) == 1) {
				if (userType == 1) { // if reader is teacher
					string sure;
					cout << "Input a new password:" << endl;
					cin >> input;
					cout << "Are you sure?\n(1) - yes\n(2) - no" << endl;
					cin >> sure;
					if (isNum(sure) && stoi(sure) == 1) {
						teachers[userIndex].setPassword(input);
					}
				}
				else { // if user is student
					string sure;
					cout << "Input a new password:" << endl;
					cin >> input;
					cout << "Are you sure?\n(1) - yes\n(2) - no" << endl;
					cin >> sure;
					if (isNum(sure) && stoi(sure) == 1) {
						students[userIndex].setPassword(input);
					}
				}
			}
		}
		else { // if user is librarian
			cout << "Do you want to display your information, or the the entire library?\n(1) - Display your information\n(2) - Display entire library" << endl;
			cin >> input;
			if (isNum(input)) {
				if (stoi(input) == 1) {
					cout << librarians[userIndex] << endl; // display your information
				}
				else {
					printAll(); // display entire library
				}
			}
		}
		break;
	case 8: // change password only for librarian
		if (userType != 0) {
			cout << "\nInvalid Input!\n" << endl;
		}
		else {
			string sure;
			cout << "Input a new password:" << endl;
			cin >> input;
			cout << "Are you sure?\n(1) - yes\n(2) - no" << endl;
			cin >> sure;
			if (isNum(sure) && stoi(sure) == 1) {
				librarians[userIndex].setPassword(input);
			}
		}
		break;
	case 0: // log out for all users
		logOut();
		break;
	default: // invalid input for all other users
		cout << "\nInvalid Input!\n" << endl;
		break;
	}
}

void Library::displayMenu() { // used as update for reservation cancelling and displaying the menu
	// update for reservation
	string username = " ";
	int ISBN = -1;
	for (int i = 0; i < copies.size(); i++) {
		if (copies[i].getReader() != "No Reader" && copies[i].getReserver() != "No Reserver") { // updates the reserve date if there is a reserver and a reader
			copies[i].setReserveDate(copies[i].returnDay());
		}
		else if (copies[i].getReserver() != "No Reserver") { // if there is no reader but there is a reserver
			if (copies[i].getReserveDate() + 5 <= copies[i].returnDay()) { // check if reservation date is over
				int index = copies[i].getBook();
				for (int j = 0; j < books.size(); j++) {
					if (books[j].getIndex() == index) { // check if the book is the correct one
						username = copies[i].getReserver();
						ISBN = books[j].getISBN();
						books[j].eraseReservee(username);
						// updates copies
						if (books[j].getNumberOfReservees() > 0) { // updates to next reservee 
							copies[i].setReserver(books[j].getReserveeList()[0]);
							copies[i].setReserveDate(copies[i].returnDay());
							books[j].setNumberOfReservees(books[j].getNumberOfReservees() - 1);
						}
						else { // reset if default if there are no reservees left
							copies[i].setReserver("No Reserver");
							copies[i].setReserveDate(-1);
						}
						cout << "The reserver for the copy with the id of " << copies[i].getID() << " has not borrowed the book within the 5 day period.\nThe next reserver will now the the first in line for the book." << endl;
					}
				}
				// updates user
				cout << "ISBN: " << ISBN << endl;
				for (int j = 0; j < teachers.size(); j++) {
					if (teachers[j].getUsername() == username && ISBN != -1) {
						teachers[j].cancelReserve(ISBN);
					}
				}
				for (int j = 0; j < students.size(); j++) {
					if (students[j].getUsername() == username && ISBN != -1) {
						students[j].cancelReserve(ISBN);
					}
				}
			}
		}
	}
	writeFiles();

	// display menu
	if (loggedIn) { 
		string input;
		divider(50);
		cout << endl << "-             Welcome to My Library!             -" << endl;
		divider(50);

		// custom menu display for each user type
		switch (userType) {
		case 0:
			librarians[userIndex].displayMenu();
			break;
		case 1:
			teachers[userIndex].displayMenu();
			break;
		case 2:
			students[userIndex].displayMenu();
			break;
		default:
			cout << "Warning: Fatal error with user type." << endl;
			break;
		}

		cin >> input;

		if (isNum(input)) {
			menuInput(stoi(input));
		}
		displayMenu(); // loops
	}
	else {
		string username, password;
		char ch;
		cout << "Input username and password to continue.\nUsername: ";
		cin >> username;
		cout << "Password: ";
		ch = _getch(); // get next character
		// loops until enter 
		while (ch != 13) { // character 13 is enter
			if (ch != 8) { // check if backspace is not inputted
				password.push_back(ch); // adds to string
				cout << '*'; // replace with '*'
			}
			else { // if backspace is inputted
				if (password.size() > 0) { // check if password is empty already
					password.pop_back(); // deletes the previous character
					cout << "\b \b"; // move cursor back 
				}
			}
			ch = _getch(); // get next character
		}
		userAuthentication(username, password); // goes to userAuthentication
	}
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

	fin5.close();

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

template <typename T>
void Library::print(vector<T> vectorName) { // prints every item in the vector
	for (int i = 0; i < vectorName.size(); i++) {
		cout << vectorName[i];
	}
}

int Library::findIfBookExists(int ISBN) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getISBN() == ISBN)
			return i; // returns index of book in vector
	}
	return -1; // checked every book, so returns -1
}

Book* Library::findBook(int ISBN) { // finds book based on ISBN
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getISBN() == ISBN)
			return &books[i];
	}
	return NULL;
}

int Library::findCopyInVector(int ID) {
	for (int i = 0; i < copies.size(); i++) {
		if (copies[i].getID() == ID)
			return i; // returns index of copy in vector
	}
	return -1; // checked every copy, so returns -1
}

Copy* Library::findCopy(int ID) {
	for (int i = 0; i < copies.size(); i++) {
		if (copies[i].getID() == ID)
			return &copies[i];
	}
	return NULL;
}

Book* Library::findBookFromBookIndex(int bookIndex) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].getIndex() == bookIndex)
			return &books[i]; // returns book
	}
	return NULL;
}


void Library::addBooks(int ISBN, string title, string author, string category) {
	if (findIfBookExists(ISBN) == -1) { // case if book is not in the library
		Book newBook;
		newBook.setISBN(ISBN);
		newBook.setTitle(title);
		newBook.setAuthor(author);
		newBook.setCategory(category);
		if (books.size() == 0) { // to handle case if books is empty
			newBook.setIndex(1);
		}
		else {
			newBook.setIndex(books.back().getIndex() + 1);
		}
		newBook.setCount(1);
		newBook.setFavor(0);
		books.push_back(newBook); // updates books array
		Copy newCopy;
		if (copies.size() == 0) { // handles case if copies is empty
			newCopy.setID(1);
		}
		else {
			newCopy.setID(copies.back().getID() + 1); // take the ID of the last copy and add 1
		}
		newCopy.setBook(findBook(ISBN)->getIndex());
		newCopy.setReader("No Reader");
		newCopy.setReserver("No Reserver");
		newCopy.setAvailable(1);
		newCopy.setBorrowDate(-1);
		newCopy.setReserveDate(-1);
		newCopy.setExpirationDate(-1);
		copies.push_back(newCopy); // updates copies array
		writeFiles(); // updates library
	}
	else if ((findBook(ISBN)->getTitle() == title) && (findBook(ISBN)->getAuthor() == author) && (findBook(ISBN)->getCategory() == category)){ // case if book is in the library
		findBook(ISBN)->setCount(findBook(ISBN)->getCount() + 1); // increment count by 1
		Copy newCopy;
		newCopy.setID(copies.back().getID()+1); // take the ID of the last copy and add 1
		newCopy.setBook(findBook(ISBN)->getIndex());
		newCopy.setReader("No Reader");
		newCopy.setReserver("No Reserver");
		newCopy.setAvailable(1);
		newCopy.setBorrowDate(-1);
		newCopy.setReserveDate(-1);
		newCopy.setExpirationDate(-1);
		copies.push_back(newCopy); // updates copies array
		writeFiles(); // updates library
	}
	else { // book shares ISBN but differs in title/author/category
		cout << "Different book in the Library shares the same ISBN." << endl;
	}
}

void Library::deleteBook(int ID) {
	if (findCopyInVector(ID) == -1) { // copy does not exist
		cout << "Copy does not exist." << endl;
	}
	else if (findCopy(ID)->getAvailable() == 0) { // copy is not available
		cout <<						 "Copy is currently lent out, so it cannot be deleted." << endl;
	}
	else { // book count needs to be decreased and copy needs to be deleted
		Book* bookPtr = findBookFromBookIndex(findCopy(ID)->getBook()); // from ID, find the copy, from the copy, find the bookIndex, from bookIndex find book pointer
		if (bookPtr->getCount() == 1) { // if there is only 1 book, delete the book from reservations, then delete the book

			if (findCopy(ID)->getReserver() != "No Reserver") { // if there is a reserver, remove the copy from their reserved books
				if (getStudent(findCopy(ID)->getReserver()) != NULL) { // check if reserver is a student
					Student* studentPtr = getStudent(findCopy(ID)->getReserver());
					vector<int> reservedVector = studentPtr->getReserved();
					int vectorSize = reservedVector.size();
					for (int i = 0; i < vectorSize; i++) {
						if (reservedVector[i] == bookPtr->getIndex()) { 
							studentPtr->getReserved().erase(studentPtr->getReserved().begin() + i); // erase reserved book from reserved vector
						}
					}
				}
				else { // reserver must be a teacher
					Teacher* teacherPtr = getTeacher(findCopy(ID)->getReserver());
					vector<int> reservedVector = teacherPtr->getReserved();
					int vectorSize = reservedVector.size();
					for (int i = 0; i < vectorSize; i++) {
						if (reservedVector[i] == bookPtr->getIndex()) {
							teacherPtr->getReserved().erase(teacherPtr->getReserved().begin() + i); // erase reserved book from reserved vector
						}
					}
				}
			}

			books.erase(books.begin() + findIfBookExists(bookPtr->getISBN())); // delete book if book count is at 1
		}
		else { // otherwise, decrease book count
			bookPtr->setCount(bookPtr->getCount() - 1);
		}

		copies.erase(copies.begin() + findCopyInVector(ID)); // erase copy
		writeFiles(); // update files
	}
}

bool Library::overdue(Reader reader) {
	bool overdue = false;
	int current_day, due_day, index = 0;
	for (int i : reader.getBorrowed()) { // goes through all borrowed ids in reader's borrowed vector
		current_day = copies[index].returnDay();
		due_day = copies[index].getExpirationDate();
		if (current_day > due_day && due_day != -1) { // checks if the book is overdue with the exception of if it's the default -1
			return true;
		}
		index++;
	}
	return overdue;
}

void Library::borrowBook(int ISBN) {
	if (findIfBookExists(ISBN) == -1 || ISBN == -1) { // check if book exists
		cout << "This book does not exist." << endl;
		return;
	}
	if (userType == 1) { // if user is teacher
		for (Copy copy : copies) { // goes through the copies to check if the user has already borrowed it 
			if (copy.getReader() == teachers[userIndex].getUsername()) {
				cout << "You have already borrowed this book." << endl;
				return;
			}
		}
		if (overdue(teachers[userIndex])) { // checks if books are overdue
			cout << "You have overdue books." << endl;
			return;
		}
		else if (teachers[userType].getMaxCopies() >= teachers[userType].getBorrowed().size()) { // checks if the user has too many books currently being borrowed
			cout << "You have too many books currently being borrowed." << endl;
			return;
		}
		else {
			bool borrowedBook = false;
			int index = findIfBookExists(ISBN);

			if (index != -1) { // checks if book exists
				int copyIndex = 0;
				for (Copy copy : copies) { // goes through all the copies for a copy of the book that currently has no reader or reserver that is not the user
					if (copy.getBook() == index + 1 && copy.getReader() == "No Reader" && (books[index].getNumberOfReservees() <= 0 || books[index].getReserveeList()[0] == students[userIndex].getUsername())) {
						copies[copyIndex].setReader(teachers[userIndex].getUsername());
						// adds it to the user
						if (teachers[userIndex].getBorrowed()[0] == -1) { // gets rid of default case if user has no other books borrowed
							teachers[userIndex].returnBook(-1);
						}
						teachers[userIndex].addBorrowed(copy.getID());
						// sets info in copy
						copies[copyIndex].setBorrowDate(copies[copyIndex].returnDay());
						copies[copyIndex].setExpirationDate(copies[copyIndex].returnDay() + (30 - (books[index].getNumberOfReservees() / 20)));
						copies[copyIndex].setAvailable(0);
						cout << "Borrowing book of an ISBN " << ISBN << " and with an ID of " << copy.getID() << ". Please return within " << (30 - (books[index].getNumberOfReservees() / 20)) << " days." << endl;
						// if user was the first in the reserve list, updates reserve
						if (!(books[index].getNumberOfReservees() <= 0) && books[index].getReserveeList()[0] == teachers[userIndex].getUsername()) {
							books[index].eraseReservee(teachers[userIndex].getUsername());
							books[index].setNumberOfReservees(books[index].getNumberOfReservees() - 1);
							if (books[index].getNumberOfReservees() <= 0) {
								copies[copyIndex].setReserver("No Reserver"); // base case
							}
							else {
								copies[copyIndex].setReserver(books[index].getReserveeList()[0]); // next reserver
							}
						}
						borrowedBook = true;
						break;
					}
					copyIndex++;
				}
				if (!borrowedBook) {
					cout << "This book is currently not available to be borrowed" << endl;
				}
			}
			else {
				cout << "This book does not exist." << endl;
			}
		}
	}
	else { // reader is student
		for (Copy copy : copies) {
			if (copy.getReader() == students[userIndex].getUsername()) {
				cout << "You have already borrowed this book." << endl;
				return;
			}
		}
		if (overdue(students[userIndex])) {
			cout << "You have overdue books." << endl;
			return;
		}
		else if (students[userIndex].getMaxCopies() <= students[userIndex].getBorrowed().size()) {
			cout << "You have too many books currently being borrowed." << endl;
			return;
		}
		else {
			bool borrowedBook = false;
			int index = findIfBookExists(ISBN);

			if (index != -1) {
				int copyIndex = 0;
				for (Copy copy : copies) {
					if (copy.getBook() == index + 1 && copy.getReader() == "No Reader" && (books[index].getNumberOfReservees() <= 0 || books[index].getReserveeList()[0] == students[userIndex].getUsername())) {
						copies[copyIndex].setReader(students[userIndex].getUsername());
						if (students[userIndex].getBorrowed()[0] == -1) {
							students[userIndex].returnBook(-1);
						}
						students[userIndex].addBorrowed(copy.getID());
						copies[copyIndex].setBorrowDate(copies[copyIndex].returnDay());
						copies[copyIndex].setExpirationDate(copies[copyIndex].returnDay() + (30 - (books[index].getNumberOfReservees() / 20)));
						copies[copyIndex].setAvailable(0);
						cout << "Borrowing book of an ISBN " << ISBN << " and with an ID of " << copy.getID() << ". Please return within " << (30 - (books[index].getNumberOfReservees() / 20)) << " days." << endl;
						if (!(books[index].getNumberOfReservees() <= 0) && books[index].getReserveeList()[0] == students[userIndex].getUsername()) {
							books[index].eraseReservee(students[userIndex].getUsername());
							books[index].setNumberOfReservees(books[index].getNumberOfReservees() - 1);	
							if (books[index].getNumberOfReservees() <= 0) {
								copies[copyIndex].setReserver("No Reserver");
							}
							else {
								copies[copyIndex].setReserver(books[index].getReserveeList()[0]);
							}
						}
						borrowedBook = true;
						break;
					} 
					copyIndex++;
				}
				if (!borrowedBook) {
					cout << "This book is currently not available to be borrowed" << endl;
				}
			}
			else {
				cout << "This book does not exist." << endl;
			}
		}
	}
	writeFiles();
}

void Library::returnBook(int id) {
	bool overdue = false;
	int index = 0;
	for (Copy copy : copies) { // check if the book exists
		if (copy.getID() == id) {
			index = 1;
		}
	}
	if (index != 1) {
		cout << "This book does not exist" << endl;
		return;
	}
	index = 0;
	if (userType == 1) { // reader is teacher
		for (int i : teachers[userIndex].getBorrowed()) { // checks if the book is overdue
			if (i = id) {
				if (copies[i].returnDay() > copies[i].getExpirationDate()) {
					overdue = true;
				}
			}
			index++;
		}
		if (teachers[userIndex].returnBook(id)) { // helper function for returning
			// sets information in the copy
			copies[findCopyInVector(id)].setReader("No Reader");
			copies[findCopyInVector(id)].setBorrowDate(-1);
			copies[findCopyInVector(id)].setExpirationDate(-1);
			copies[findCopyInVector(id)].setAvailable(1);
			if (overdue) { // if overdue, give 1 penalty
				teachers[userIndex].setPenalties(teachers[userIndex].getPenalties() + 1); 
				cout << "You have returned this book late and will get a penalty. Get 5 penalties and your maximum number of borrowed books will be reduced by 1." << endl;
				if (teachers[userIndex].getPenalties() % 5 == 0) { // if there are a multiple of 5 copies, the max copies is reduced by 1
					teachers[userIndex].setMaxCopies(teachers[userIndex].getMaxCopies() - 1);
					cout << "You have another 5 penalties, as a result, your maximum number of borrowed books will be reduced by 1." << endl;
				}
			}
			favor(id);
		}
	}
	else { // if reader is a student
		for (int i : students[userIndex].getBorrowed()) {
			if (i = id) {
				if (copies[findCopyInVector(i)].returnDay() > copies[findCopyInVector(i)].getExpirationDate()) {
					overdue = true;
				}
			}
		}
		if (students[userIndex].returnBook(id)) {
			copies[findCopyInVector(id)].setReader("No Reader");
			copies[findCopyInVector(id)].setBorrowDate(-1);
			copies[findCopyInVector(id)].setExpirationDate(-1);
			copies[findCopyInVector(id)].setAvailable(1);
			if (overdue) {
				students[userIndex].setPenalties(students[userIndex].getPenalties() + 1);
				cout << "You have returned this book late and will get a penalty. Get 5 penalties and your maximum number of borrowed books will be reduced by 1." << endl;
				if (students[userIndex].getPenalties() % 5 == 0) {
					students[userIndex].setMaxCopies(students[userIndex].getMaxCopies() - 1);
					cout << "You have another 5 books returned late, as a result, your maximum number of borrowed books will be reduced by 1." << endl;
				}
			}
			favor(id);
		}
	}
	writeFiles();
}

void Library::favor(int id) { // polls whether a user enjoyed their book
	int i;
	string input;
	cout << "Did you like the book?\n(0) - It was ok\n(1) - It was good\n(2) - It was bad\nIf you do not wish to participate, input any other input than the ones listed." << endl;
	cin >> input;
	if (isNum(input)) {
		for (i = 0; i < books.size(); i++) {
			if (books[i].getIndex() == copies[findCopyInVector(id)].getBook()) {
				break;
			}
		}
		switch (stoi(input)) {
		case 1:
			books[i].setFavor(books[i].getFavor() + 1); // if 1, increase favor
			break;
		case 2:
			books[i].setFavor(books[i].getFavor() - 1); // if 2, decrease favor
			break;
		default: // skip
			break;
		}
	}
}

void Library::reserveBook(int ISBN) { 
	// check for book validity
	if (findIfBookExists(ISBN) == -1 || ISBN == -1) {
		cout << "This book does not exist." << endl;
		return;
	}
	bool index = -1;
	if (userType == 1) { // if reader is a teacher
		// checks for if the reader has already reserved the book
		for (int isbn : teachers[userIndex].getReserved()) { 
			if (isbn == ISBN) {
				cout << "You have already reserved this book" << endl;
				break;
			}
		}
		// if users have overdue books, stop function
		if (overdue(teachers[userIndex])) {
			cout << "You have overdue books, please return them before reserving books." << endl;
			return;
		}
		else {
			// get the index of the book
			for (Book book : books) {
				index++;
				if (book.getISBN() == ISBN) {
					break;
				}
			}
			if (index != -1) { // book is valid
				for (string username : books[index].getReserveeList()) { // checks for if the reader has reserved the book within the reserveeList
					if (username == teachers[userIndex].getUsername()) {
						cout << "You have already reserved this book." << endl;
						return;
					}
				}
				// set information in book
				cout << "Reserved book of ISBN " << ISBN << endl;
				books[index].addReserveeList(teachers[userIndex].getUsername());
				books[index].setNumberOfReservees(books[index].getNumberOfReservees() + 1);
				// set information in reader
				if (teachers[userIndex].getReserved()[0] == -1) { // deletes base case '-1' if user has no books reserved
					teachers[userIndex].cancelReserve(-1);
				}
				teachers[userIndex].addReserved(ISBN);
				// set information in copy
				for (int i = 0; i < copies.size(); i++) {
					if (copies[i].getBook() == index) {
						if (copies[i].getReserver() == "No Reserver") {
							copies[i].setReserver(teachers[userIndex].getUsername());
							copies[i].setReserveDate(copies[i].returnDay());
						}
					}
				}
			}
			else {
				cout << "There were no available copies of that book to reserve or this book does not exist." << endl;
			}
		}
	}
	else { // reader is a student
		if (overdue(students[userIndex])) {
			cout << "You have overdue books, please return them before reserving books." << endl;
			return;
		}
		else {
			for (Book book : books) {
				index++;
				if (book.getISBN() == ISBN) {
					break;
				}
			}
			if (index != -1) {
				for (string username : books[index].getReserveeList()) {
					if (username == students[userIndex].getUsername()) {
						cout << "You have already reserved this book." << endl;
						return;
					}
				}
				cout << "Reserved book of ISBN " << ISBN << endl;
				books[index].addReserveeList(students[userIndex].getUsername());
				books[index].setNumberOfReservees(books[index].getNumberOfReservees() + 1);
				if (students[userIndex].getReserved()[0] == -1) {
					students[userIndex].cancelReserve(-1);
				}
				students[userIndex].addReserved(ISBN);
				for (int i = 0; i < copies.size(); i++) {
					if (copies[i].getBook() == index) {
						if (copies[i].getReserver() == "No Reserver") {
							copies[i].setReserver(students[userIndex].getUsername());
							copies[i].setReserveDate(copies[i].returnDay());
						}
					}
				}
			}
			else {
				cout << "There were no available copies of that book to reserve or this book does not exist." << endl;
			}
		}
	}
	writeFiles(); // update
}

void Library::cancelReserve(int ISBN) {
	int index = findIfBookExists(ISBN), copyIndex = 0;
	if (index == -1) { // if book does not exist
		cout << "This book does not exist" << endl;
		return;
	}
	if (userType == 1) { // reader is a teacher
		if (teachers[userIndex].cancelReserve(ISBN)) { // helper function in reader for cancel reserve
			// delete reader from the book
			books[index].eraseReservee(teachers[userIndex].getUsername());
			books[index].setNumberOfReservees(books[index].getNumberOfReservees() - 1);
			// delete users from the copies of the book
			for (Copy copy : copies) {
				if (copies[copyIndex].getBook() == index + 1 && copies[copyIndex].getReserver() == teachers[userIndex].getUsername()) {
					if (findBook(ISBN)->getNumberOfReservees() <= 0) { // if there are no resrvers
						copies[copyIndex].setReserver("No Reserver"); // return to default
						copies[copyIndex].setReserveDate(-1);
					}
					else { // if there are reservers
						copies[copyIndex].setReserver(findBook(ISBN)->getReserveeList()[0]); // display first reserver
						copies[copyIndex].setReserveDate(copies[copyIndex].returnDay());
					}
					break;
				}
				copyIndex++;
			}
		}
	}
	else { // reader is a student
		if (students[userIndex].cancelReserve(ISBN)) {
			books[index].eraseReservee(students[userIndex].getUsername());
			books[index].setNumberOfReservees(books[index].getNumberOfReservees() - 1);
			for (Copy copy : copies) {
				if (copies[copyIndex].getBook() == index + 1 && copies[copyIndex].getReserver() == teachers[userIndex].getUsername()) {
					if (findBook(ISBN)->getNumberOfReservees() <= 0) {
						copies[copyIndex].setReserver("No Reserver");
						copies[copyIndex].setReserveDate(-1);
					}
					else {
						copies[copyIndex].setReserver(findBook(ISBN)->getReserveeList()[0]);
						copies[copyIndex].setReserveDate(copies[copyIndex].returnDay());
					}
					break;
				}
				copyIndex++;
			}
		}
	}
	writeFiles();
}

void Library::renewBook(int id) {
	int index = -1, day = 0;
	if (userType == 1) { // reader is a teacher
		day = teachers[userIndex].getMaxBorrowingPeriod(); // set day to maxBorrowingDay
		if (teachers[userIndex].getBorrowed().size() == 0 && !overdue(teachers[userIndex])) { // checks if there are books and if there are no overdue book
			for (int i : teachers[userIndex].getBorrowed()) { // checks for the correct index of the book
				if (i == id) {
					break;
				}
				index++;
			}
		}
	}
	else { // reader is a student
		day = students[userIndex].getMaxBorrowingPeriod();
		if (students[userIndex].getBorrowed().size() == 0 && !overdue(students[userIndex])) {
			for (int i : students[userIndex].getBorrowed()) {
				if (i == id) {
					break;
				}
				index++;
			}
		}
	}
	if (index != -1) { // if there is a book
		copies[index].setExpirationDate(copies[index].getExpirationDate() + day); // add day to the expiration date
	}
	else {
		cout << "You do not have this book or it does not exist to be renewed." << endl;
	}
	writeFiles();
}

void Library::searchBooks() {
	cout << "Search by:\n\t1-ISBN\n\t2-Title\n\t3-Author's Name\n\t4-Category" << endl;
	string inputStr1, inputStr2, inputStr3;
	cin >> inputStr1;
	if (isNum(inputStr1)) { // checks if input is number
		switch (stoi(inputStr1)) {
			case 1: {
				cout << "\nSearch: ";
				cin >> inputStr2;
				//getline(cin, inputStr2);
				if (isNum(inputStr2)) { // checks if input is number
					int ISBN = stoi(inputStr2);
					if (findIfBookExists(ISBN) != -1) { // checks if book exists
						Book* bookPtr = findBook(ISBN);
						cout << *bookPtr; // output book
						cout << "Here are the available copies: " << endl;
						for (int i = 0; i < copies.size(); i++) {
							if ((bookPtr->getIndex() == copies[i].getBook()) && (copies[i].getAvailable() != false)) { // if the books are the same, and the copy is available
								cout << copies[i]; //output copy
							}
						}
					}
					else {
						cout << "No books can be found." << endl;
					}
				}
				else {
					cout << "Input is not a number." << endl;
				}
				break;
			}
			case 2: {
				cout << "\nSearch: ";
				getline(cin, inputStr3);
				getline(cin, inputStr2);
				vector<Book> bookVector;
				for (int i = 0; i < getBooks().size(); i++) {
					if (getBooks()[i].getTitle() == inputStr2) {
						bookVector.push_back(getBooks()[i]);
					}
				}

				if (bookVector.empty()) {
					cout << "No books can be found." << endl;
					return;
				}
				else {
					for (int i = 0; i < bookVector.size(); i++) {
						cout << "Here are the available copies of " << bookVector[i].getTitle() << ": " << endl;
						for (int j = 0; j < getCopies().size(); j++) {
							if ((bookVector[i].getIndex() == copies[j].getBook()) && (copies[i].getAvailable() != false)) {
								cout << copies[j]; //output copy
							}
						}
					}
				}
				break;
			}
			case 3: {
				cout << "\nSearch: ";
				getline(cin, inputStr3);
				getline(cin, inputStr2);
				vector<Book> bookVector;
				for (int i = 0; i < getBooks().size(); i++) {
					if (getBooks()[i].getAuthor() == inputStr2) {
						bookVector.push_back(getBooks()[i]);
					}
				}

				if (bookVector.empty()) {
					cout << "No books can be found." << endl;
					return;
				}
				else {
					for (int i = 0; i < bookVector.size(); i++) {
						cout << "Here are the available copies of " << bookVector[i].getTitle() << ": " << endl;
						for (int j = 0; j < getCopies().size(); j++) {
							if ((bookVector[i].getIndex() == copies[j].getBook()) && (copies[i].getAvailable() != false)) {
								cout << copies[j]; //output copy
							}
						}
					}
				}
				break;
			}
			case 4: {
				cout << "\nSearch: ";
				getline(cin, inputStr3);
				getline(cin, inputStr2);
				vector<Book> bookVector;
				for (int i = 0; i < getBooks().size(); i++) {
					if (getBooks()[i].getCategory() == inputStr2) {
						bookVector.push_back(getBooks()[i]);
					}
				}

				if (bookVector.empty()) {
					cout << "No books can be found." << endl;
					return;
				}
				else {
					for (int i = 0; i < bookVector.size(); i++) {
						cout << "Here are the available copies of " << bookVector[i].getTitle() << ": " << endl;
						for (int j = 0; j < getCopies().size(); j++) {
							if ((bookVector[i].getIndex() == copies[j].getBook()) && (copies[i].getAvailable() != false)) {
								cout << copies[j]; //output copy
							}
						}
					}
				}
				break;
			}
			default:
				cout << "Invalid input was given." << endl;
		}
	}
}

void Library::searchUsers(string username) {
	if (getStudent(username) != NULL) { // user is a student
		cout << *getStudent(username) << "User Type: Student" << endl << endl;
	}
	else if (getTeacher(username) != NULL) { // user is a teacher
		cout << *getTeacher(username) << "User Type: Teacher" << endl << endl;
	}
	else if (getLibrarian(username) != NULL) { // user is a librarian
		cout << *getLibrarian(username) << "User Type: Librarian" << endl << endl;
	}
	else {
		cout << "User does not exist." << endl;
	}
}


void Library::addUser() {
	cout << "Type:\n\t1-Student\n\t2-Teacher\n\t3-Librarian" << endl;
	string input;
	string username, password;
	cin >> input;
	if (isNum(input)) {
		switch(stoi(input)) {
		case 1: {
			cout << "Input username" << endl;
			cin >> username;
			if ((getStudent(username) != NULL) || (getTeacher(username) != NULL) || (getLibrarian(username) != NULL)) { // check if username is taken
				cout << "Username is already taken." << endl;
				return;
			}
			cout << "Input password" << endl;
			cin >> password;
			Student student;
			student.setUsername(username);
			student.addBorrowed(-1);
			student.addReserved(-1);
			student.setPassword(password);
			students.push_back(student);
			writeFiles();
			break;
		}
		case 2: {
			cout << "Input username" << endl;
			cin >> username;
			if ((getStudent(username) != NULL) || (getTeacher(username) != NULL) || (getLibrarian(username) != NULL)) {
				cout << "Username is already taken." << endl;
				return;
			}
			cout << "Input password" << endl;
			cin >> password;
			Teacher teacher;
			teacher.setUsername(username);
			teacher.addBorrowed(-1);
			teacher.addReserved(-1);
			teacher.setPassword(password);
			teachers.push_back(teacher);
			writeFiles();
			break;
		}
		case 3: {
			cout << "Input username" << endl;
			cin >> username;
			if ((getStudent(username) != NULL) || (getTeacher(username) != NULL) || (getLibrarian(username) != NULL)) {
				cout << "Username is already taken." << endl;
				return;
			}
			cout << "Input password" << endl;
			cin >> password;
			Librarian librarian;
			librarian.setUsername(username);
			librarian.setPassword(password);
			librarians.push_back(librarian);
			writeFiles();
			break;
		}
		default:
			cout << input << " is not a valid input." << endl;
		}
	}
}

void Library::deleteUser() {
	string username;
	cout << "Input the user's username: ";
	cin >> username;
	if (getStudent(username) != NULL) { // user is a student
		Student* studentPtr = getStudent(username);
		if (!studentPtr->getBorrowed().empty()) {
			cout << "Cannot delete user because user still has copies." << endl;
			return;
		}
		else {
			//remove from reservee list
			vector<int> reservedBooks = studentPtr->getReserved();
			for (int i = 0; i < reservedBooks.size(); i++) { // erase user form every book in their reserved books
				Book* bookPtr = findBookFromBookIndex(reservedBooks[i]);
				for (int j = 0; j < bookPtr->getReserveeList().size(); j++) {
					if (bookPtr->getReserveeList()[j] == studentPtr->getUsername()) {
						bookPtr->getReserveeList().erase(bookPtr->getReserveeList().begin() + j); // erase user from reservee list of book
					}
				}
				
			}
			removeStudent(username);
		}
	}
	else if (getTeacher(username) != NULL) { // user is a teacher
		Teacher* teacherPtr = getTeacher(username);
		if (!teacherPtr->getBorrowed().empty()) {
			cout << "Cannot delete user because user still has copies." << endl;
			return;
		}
		else {
			//remove from reservee list
			vector<int> reservedBooks = teacherPtr->getReserved();
			for (int i = 0; i < reservedBooks.size(); i++) { // erase user form every book in their reserved books
				Book* bookPtr = findBookFromBookIndex(reservedBooks[i]);
				for (int j = 0; j < bookPtr->getReserveeList().size(); j++) {
					if (bookPtr->getReserveeList()[j] == teacherPtr->getUsername()) {
						bookPtr->getReserveeList().erase(bookPtr->getReserveeList().begin() + j); // erase user from reservee list of book
					}
				}

			}
			removeTeacher(username);
		}
		
	}
	else if (getLibrarian(username) != NULL) { // user is a librarian
		if (getLibrarians().size() == 1) {
			cout << "Last librarian cannot be deleted." << endl;
		}
		else {
			removeLibrarian(username); // librarians cannot reserve books
			cout << "User will be logged out. Afterwards, the librarian will be removed. Please log back in to continue." << endl;
			// This is to handle the case where the librarian deletes themself.
			logOut();
		}
	}
	else {
		cout << "User does not exist." << endl;
	}
	writeFiles();

}

void Library::printAll() {
	print(getBooks()); // uses template to print every vector of different types
	print(getCopies());
	print(getStudents());
	print(getTeachers());
	print(getLibrarians());
}

void Library::recommendBooks() {
	vector<Book> booksToSort = getBooks();
	for (int i = 0; i < booksToSort.size() - 1; i++) { // bubble sort booksToSort by the number of reservees from greatest to least
		for (int j = 0; j < booksToSort.size() - 1; j++) {
			if (booksToSort[j].getNumberOfReservees() > booksToSort[j + 1].getNumberOfReservees()) {
				Book temp = booksToSort[j];
				booksToSort[j] = booksToSort[j + 1];
				booksToSort[j + 1] = temp;
			}
		}

	}

	if (userType == 2) { // student type
		vector<int> borrowedIDs;
		if (students[userIndex].getBorrowed()[0] != -1) {
			borrowedIDs = getStudents()[userIndex].getBorrowed();
		}
		vector<Book> booksToRecommend;

		if (borrowedIDs.empty()) { // case if borrowed is empty

			while ((booksToRecommend.size() < 10) && !booksToSort.empty()) { // grab 10 books or wait for the vector to be empty
				booksToRecommend.push_back(booksToSort.back());
				booksToSort.pop_back();
			}
			for (int i = 0; i < booksToRecommend.size(); i++) { //output each book to recommend
				cout << booksToRecommend[i];
			}
		}
		else {
			while ((booksToRecommend.size() < 10) && !booksToSort.empty()) { // grab 10 books or wait for the vector to be empty
				Copy bookCopy = *findCopy(borrowedIDs.back());
				Book lastBook = *findBookFromBookIndex(bookCopy.getBook());
				if (booksToSort.back().getCategory() == lastBook.getCategory()) { // if the category is the same as the last category the user borrowed, recommend it
					booksToRecommend.push_back(booksToSort.back());
				}
				booksToSort.pop_back(); // remove book from vector
			}
			for (int i = 0; i < booksToRecommend.size(); i++) { //output each book to recommend
				cout << booksToRecommend[i];
			}
		}
	}

	else if (userType == 1) { // teacher type
		vector<int> borrowedIDs;
		if (teachers[userIndex].getBorrowed()[0] != -1) {
			borrowedIDs = getTeachers()[userIndex].getBorrowed();
		}
		vector<Book> booksToRecommend;

		if (borrowedIDs.empty()) { // case if borrowed is empty

			while ((booksToRecommend.size() < 10) && !booksToSort.empty()) { // grab 10 books or wait for the vector to be empty
				booksToRecommend.push_back(booksToSort.back());
				booksToSort.pop_back();
			}
			for (int i = 0; i < booksToRecommend.size(); i++) { //output each book to recommend
				cout << booksToRecommend[i];
			}
		}
		else {
			while ((booksToRecommend.size() < 10) && !booksToSort.empty()) { // grab 10 books or wait for the vector to be empty
				Copy bookCopy = *findCopy(borrowedIDs.back());
				Book lastBook = *findBookFromBookIndex(bookCopy.getBook());
				if (booksToSort.back().getCategory() == lastBook.getCategory()) { // if the category is the same as the last category the user borrowed, recommend it
					booksToRecommend.push_back(booksToSort.back());
				}
				booksToSort.pop_back(); // remove book from vector
			}
			for (int i = 0; i < booksToRecommend.size(); i++) { //output each book to recommend
				cout << booksToRecommend[i];
			}
		}
	}
	else { // if this is ever used by librarians
		cout << "User cannot get book recommendations." << endl;
	}

}