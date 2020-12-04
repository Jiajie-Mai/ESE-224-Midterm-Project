#pragma once
#include "User.h"
#include <string>
using namespace std;
class Librarian : public User
{
public:
	Librarian();
	int displayMenu(); // default display menu for a generic librarian
};

