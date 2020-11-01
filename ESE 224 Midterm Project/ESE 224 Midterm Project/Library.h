#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LMS
{
private:
	vector<Book> library;
public:
	void findBook(string title);
};

