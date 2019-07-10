#pragma once
#ifndef DATABASE
#define DATABASE
#include <list>
#include "DataContainer.h"
#include "Listener.h"

class Database {
public:
	Database(const int PORT);
	bool isRunning() { return running; };
private:
	bool running;
	std::list<DataContainer> children;
	Listener* l;
};

#endif
