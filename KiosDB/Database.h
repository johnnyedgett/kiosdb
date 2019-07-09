#pragma once
#ifndef DATABASE
#define DATABASE
#include <list>
#include "DataContainer.h"

class Database {
public:
	Database(const int PORT);
	bool isRunning() { return running; };
private:
	bool running;
	const int port;
	// Children of this root database class must be data containers 
	std::list<DataContainer> children;
};

#endif
