#include "DbNode.h"
#include <string.h>

template<class T> 
void DbNode::setData(DbNode::Type t, T data) {
	switch (t) {
	case DbNode::Type::INTEGER:
	case DbNode::Type::DOUBLE:
	case DbNode::Type::FLOAT:
	case DbNode::Type::STRING:
	}
}