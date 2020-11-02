#include "Library.h"

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

bool LMS::bookAvaliable(int ID) {
	bool avaliable = false;
	library.begin();
	for (Book b : library) {
		if (b.getID() == ID) {
			return true;
		}
	}
	return avaliable;
}

bool LMS::copiesAvaliable(int ISBN) {
	bool avaliable = false;
	for (Book b : library) {
		if (b.getISBN() == ISBN) {
			return true;
		}
	}
	return avaliable;
}

bool LMS::overdue(int ID) {

}

void LMS::borrowBook(int ISBN) {
	int index = 0;
	library.begin();
	for (Book b : library) {
		if (b.getISBN() == ISBN) {
			library.erase(library.begin() + index);
			break;
		}
		index++;
	}
}

void LMS::returnBook(int ISBn) {

}