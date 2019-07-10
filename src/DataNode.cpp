#include "DataNode.h"
#include <string.h>

template<class T> 
void DataNode::setData(DataNode::Type t, T data) {
	switch (t) {
	case DataNode::Type::INTEGER:
		break;
	case DataNode::Type::DOUBLE:
		break;
	case DataNode::Type::FLOAT:
		break;
	case DataNode::Type::STRING:
		break;
	}
}