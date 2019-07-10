#include "Database.h"
#include "DBListener.h"
#include <iostream>
Database::Database(const int PORT): running(true) {
	DBListener l(PORT);
	this->l = &l;
}
