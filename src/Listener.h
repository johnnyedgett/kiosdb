#ifndef LISTENER
#define LISTENER

#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;


class Listener {
public:
	Listener(const int PORT);
	void listen();
	// string read_(tcp::socket & socket);
	// void send_(tcp::socket & socket, const string& message);
private:
	const int PORT;
};

#endif
