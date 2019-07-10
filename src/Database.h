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
	~Database(){ thread_.join(); }
	bool isRunning() { return running; };
private:
	std::thread thread_;
	bool running;
	std::list<DataContainer> children;
	DBListener* l;
};

#endif
