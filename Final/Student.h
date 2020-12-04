#pragma once
#include "Reader.h"
using namespace std;
class Student : public Reader
{
public:
	Student();
	int displayMenu(); // default display menu for a generic student
};

