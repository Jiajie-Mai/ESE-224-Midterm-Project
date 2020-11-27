#pragma once
#include "User.h"
#include <string>
using namespace std;
class Librarian : public User
{
public:
	Librarian();
	void addBooks(int ISBN, string title, string author, string category);
	void deleteBooks(int id);
	void searchUsers(string username);
	void addUsers(int type, string username, string password);
	void deleteUser(string username);
	int displayMenu();
};

