#include "Library.h"
using namespace std;

void initialize() {
	Library LMS;
	LMS.readFiles();
	LMS.writeFiles();
	LMS.displayMenu();
}

int main() {
	initialize();
	return 0;
}
