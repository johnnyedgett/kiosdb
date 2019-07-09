#pragma once
#ifndef DB_NODE
#define DB_NODE

#include <list>
#include <string>
#include <functional>

struct DbNode {
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
		std::string dataString;
	};
};

#endif
