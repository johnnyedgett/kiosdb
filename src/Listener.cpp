#include "Listener.h"
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

void Listener::listen(){
	boost::asio::io_service io_service;

	cout << "Listening on port " << PORT << endl;
	
	// Listen
	tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), PORT));

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

Listener::Listener(const int PORT) : PORT(PORT) {
	std::thread doListen(Listener::listen);
	doListen.join();
}