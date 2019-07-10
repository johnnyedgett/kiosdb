#include <iostream>
#include <fstream>
#include "Database.h"

const int PORT = 30606;

int main() {
	// "Start" the database
	Database dbInstance(PORT);
	if (dbInstance.isRunning()) {
		std::cout << "Database is running on port " << PORT << std::endl;
	}
	std::cout << dbInstance.isRunning() << std::endl;
}