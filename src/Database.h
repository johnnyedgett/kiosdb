#pragma once
#ifndef DATABASE
#define DATABASE
#include <list>
#include <thread>
#include "DataContainer.h"
#include "DBListener.h"

class Database {
public:
	Database(const int PORT);
	bool isRunning() { return running; };
private:
	bool running;
	std::list<DataContainer> children;
	DBListener* l;
};

#endif
