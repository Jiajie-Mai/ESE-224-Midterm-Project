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

Teacher* Library::getTeacher(string username) {
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getUsername() == username) {
			return &teachers[i];
		}
	}
	return NULL;
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

Librarian* Library::getLibrarian(string username) {
	for (int i = 0; i < librarians.size(); i++) {
		if (librarians[i].getUsername() == username) {
			return &librarians[i];
		}
	}
	return NULL;
}


void Library::userAuthentication(string username, string password) {
	if (!loggedIn) {
		int index = 0;
		for (Librarian librarian : librarians) {
			if (librarian.getUsername() == username && librarian.getPassword() == password) {
				cout << "Log in successful." << endl;
				loggedIn = true;
				userIndex = index;
				userType = 0;
				break;
			}
			index++;
		}
		index = 0;
		for (Teacher teacher : teachers) {
			if (teacher.getUsername() == username && teacher.getPassword() == password) {
				cout << "Log in successful." << endl;
				loggedIn = true;
				userIndex = index;
				userType = 1;
				break;
			}
			index++;
		}
		index = 0;
		for (Student student : students) {
			if (student.getUsername() == username && student.getPassword() == password) {
				cout << "Log in successful." << endl;
				loggedIn = true;
				userIndex = index;
				userType = 2;
				break;
			}
			index++;
		}
	}
	cout << "index" << userIndex << endl;
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

		cout << "search" << endl;
		// search();

		break;
	case 2:
		if (userType != 0) {
			cout << "Input an ISBN in order to borrow it: ";
			cin >> input;
			if (isNum(input)) {
				if (userType == 1) {

					cout << "teacher borrow book" << endl;
					/*borrowBook(teachers[userIndex], stoi(input));*/

				}
				else {

					cout << "student borrow book" << endl;
					/*borrowBook(students[userIndex], stoi(input));*/

				}
			}
		}
		else {

			cout << "librarian add book" << endl;
			// addBook();

		}

		break;
	case 3:
		if (userType != 0) {
			cout << "Input an ID in order to return it: ";
			cin >> input;
			if (isNum(input)) {
				if (userType == 1) {

					cout << "teacher return book" << endl;
					// returnBook(user, stoi(input));

				}
				else {

					cout << "student return book" << endl;
					// returnBook(user, stoi(input));

				}
			}
		}
		else {

			cout << "librarian delete book" << endl;
			// deleteBook();
		}
		break;
	case 4:
		if (userType != 0) {
			cout << "Input an ISBN to reserve a copy: " << endl;
			cin >> input;
			if (isNum(input)) {
				if (userType == 1) {

					cout << "teacher reserve book" << endl;
					// reserveBook();

				}
				else {

					cout << "student reserve book" << endl;
					// reserveBook();

				}
			}
		}
		else {

			cout << "librarian search users" << endl;
			// searchUsers();

		}
		break;
	case 5:
		if (userType != 0) {
			cout << "Input the id of the copy to cancel the reservation: " << endl;
			cin >> input;
			if (isNum(input)) {
				if (userType == 1) {

					cout << "teacher cancel reserve" << endl;
					// cancelReserve();

				}
				else {

					cout << "student cancel reserve" << endl;
					// cancelReserve();

				}
			}
		}
		else {

			cout << "librarian add users" << endl;
			// addUsers();

		}
		break;
	case 6:
		if (userType != 0) {
			if (userType == 1) {

				cout << "teacher my information" << endl;
				// cout << user << endl;

			}
			else {

				cout << "student my information" << endl;
				// cout << user << endl;

			}
		}
		else {

			cout << "librarian delete users" << endl;
			// deleteUsers();

		}
		break;
	case 7:
		if (userType != 0) {
			cout << "Input a new password:" << endl;
			cin >> input;
			cout << "Are you sure?\n(1) - yes\n(2) - no" << endl;
			cin >> input;
			if (isNum(input) && stoi(input) == 1) {
				if (userType == 1) {

					cout << "teacher change password" << endl;
					// setPassword();

				}
				else {

					cout << "student change password" << endl;
					// setPassword();

				}
			}
		}
		else {

			cout << "librarian my information" << endl;
			// cout << user << endl;

		}
		break;
	case 8:
		if (userType != 0) {
			cout << "\nInvalid Input!\n" << endl;
		}
		else {
			cout << "Input a new password:" << endl;
			cin >> input;
			cout << "Are you sure?\n(1) - yes\n(2) - no" << endl;
			cin >> input;
			if (isNum(input) && stoi(input) == 1) {

				cout << "librarian change password" << endl;
				// setPassword();

			}

		}
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
		cout << endl << "-             Welcome to My Library!             -" << endl;
		divider(50);

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

void Library::printBooks() {
	for (int i = 0; i < books.size(); i++) {
		cout << books[i];
	}
}

void Library::printCopies() {
	for (int i = 0; i < copies.size(); i++) {
		cout << copies[i];
	}
}

void Library::printStudents() {
	for (int i = 0; i < students.size(); i++) {
		cout << students[i];
	}
}

void Library::printTeachers() {
	for (int i = 0; i < teachers.size(); i++) {
		cout << teachers[i];
	}
}

void Library::printLibrarians() {
	for (int i = 0; i < librarians.size(); i++) {
		cout << librarians[i];
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
		cout << "Copy is currently lent out, so it cannot be deleted." << endl;
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

void Library::searchBooks() {
	cout << "Search by:\n\t1-ISBN\n\t2-Title\n\t3-Author's Name\n\t4-Category" << endl;
	string inputStr1, inputStr2;
	cin >> inputStr1;
	if (isNum(inputStr1)) { // checks if input is number
		switch (stoi(inputStr1)) {
			case '1': {
				cout << "\nSearch: ";
				cin >> inputStr2;
				if (isNum(inputStr2)) { // checks if input is number
					int ISBN = stoi(inputStr2);
					if (findIfBookExists(ISBN) != -1) { // checks if book exists
						Book* bookPtr = findBook(ISBN);
						cout << *bookPtr; // output book
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
			case '2': {
				cout << "\nSearch: ";
				cin >> inputStr2;
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
						for (int j = 0; j < getCopies().size(); j++) {
							if ((bookVector[i].getIndex() == copies[i].getBook()) && (copies[i].getAvailable() != false)) {
								cout << copies[i]; //output copy
							}
						}
					}
				}
				break;
			}
			case '3': {
				cout << "\nSearch: ";
				cin >> inputStr2;
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
						for (int j = 0; j < getCopies().size(); j++) {
							if ((bookVector[i].getIndex() == copies[i].getBook()) && (copies[i].getAvailable() != false)) {
								cout << copies[i]; //output copy
							}
						}
					}
				}
				break;
			}
			case '4': {
				cout << "\nSearch: ";
				cin >> inputStr2;
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
						for (int j = 0; j < getCopies().size(); j++) {
							if ((bookVector[i].getIndex() == copies[i].getBook()) && (copies[i].getAvailable() != false)) {
								cout << copies[i]; //output copy
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
		removeLibrarian(username); // librarians cannot reserve books
	}
	else {
		cout << "User does not exist." << endl;
	}
	writeFiles();

}

void Library::recommendBooks() {
	vector<Book> booksToSort = getBooks();
	for (int i = 0; i < booksToSort.size() - 1; i++) { // bubble sort booksToSort by the number of reservees from greatest to least
		for (int j = 0; j < booksToSort.size() - 1; j++) {
			if (booksToSort[j].getNumberOfReservees() < booksToSort[j + 1].getNumberOfReservees()) {
				Book temp = booksToSort[j];
				booksToSort[j] = booksToSort[j + 1];
				booksToSort[j + 1] = temp;
			}
		}

	}

	if (userType == 1) { // student type
		vector<int> borrowedIDs = getStudents()[userIndex].getBorrowed();
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

	else{ // teacher type
		vector<int> borrowedIDs = getTeachers()[userIndex].getBorrowed();
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

}