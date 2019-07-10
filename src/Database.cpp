#include "Database.h"
#include "DBListener.h"
#include <iostream>

Database::Database(const int PORT): running(true) {
	try{
		boost::asio::io_context io_context;
		DBListener listener(io_context);
		io_context.run();
	} catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
