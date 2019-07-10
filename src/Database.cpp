#include "Database.h"
#include "Listener.h"

Database::Database(const int PORT): running(true) {
	Listener l(PORT);
	this->l = &l;

}
