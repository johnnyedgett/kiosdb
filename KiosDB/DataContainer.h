#pragma once
#ifndef DATA_CONTAINER
#define DATA_CONTAINER

#include "DbNode.h"

class DataContainer {
public:
	std::string hash;
private:
	std::list<DbNode> children;
};
#endif
