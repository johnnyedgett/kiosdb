#include "DBListener.h"
#include <thread>

string read_(tcp::socket & socket) {
	boost::asio::streambuf buf;
	boost::asio::read_until(socket, buf, "\n");
	string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;
}

void send_(tcp::socket & socket, const string& message) {  
	const string msg = message + "\n";  
	boost::asio::write( socket, boost::asio::buffer(message) );  
} 

void DBListener::doListen(){
	boost::asio::io_service io_service;

	cout << "Listening on port " << 30606 << endl;
	
	// Listen
	tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 30606));

	// Create the socket
	tcp::socket socket_(io_service);

	// Wait for an incoming connection
	acceptor_.accept(socket_);

	// Read the incoming data
	string message=read_(socket_);

	cout << message << endl;

	// Write back
	send_(socket_, "Works!");
}

