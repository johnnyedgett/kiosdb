#pragma once
#ifndef DATA_NODE
#define DATA_NODE

#include <list>
#include <string>
#include <functional>

struct DataNode {
public:
	std::string hash;
	enum Type { INTEGER, DOUBLE, FLOAT, STRING };
	Type t;
	template<class T> void setData(const Type t, const T data);
private:
	union _data {
		int dataInt;
		double dataDouble;
		float dataFloat;
		char dataString[];
	};
};

#endif
