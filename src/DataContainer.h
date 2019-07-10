#pragma once
#ifndef DATA_CONTAINER
#define DATA_CONTAINER

#include "DataNode.h"

class DataContainer {
public:
	std::string hash;
private:
	std::list<DataNode> children;
};
#endif
