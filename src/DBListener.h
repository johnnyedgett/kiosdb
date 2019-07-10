#ifndef DBLISTENER
#define DBLISTENER

#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;


class DBListener {
public:
	DBListener(const int PORT) : PORT(PORT) {
		// std::thread{&DBListener::doListen}.detch();
		 std::thread(&DBListener::doListen, this).detach();
	}

	~DBListener() { 
		// thread_.join();
	}
	// string read_(tcp::socket & socket);
	// void send_(tcp::socket & socket, const string& message);
private:
	const int PORT;
	// std::thread thread_;
	void doListen();
};

#endif
