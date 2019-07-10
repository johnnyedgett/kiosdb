// #include "DBListener.h"
// #include <thread>

// string read_(tcp::socket & socket) {
// 	boost::asio::streambuf buf;
// 	boost::asio::read_until(socket, buf, "\n");
// 	string data = boost::asio::buffer_cast<const char*>(buf.data());
// 	return data;
// }

// void send_(tcp::socket & socket, const string& message) {  
// 	const string msg = message + "\n";  
// 	boost::asio::write( socket, boost::asio::buffer(message) );  
// } 
// void DBListener::handle_accept(const boost::system::error_code& err)
// {
// 	if (err)
// 	{
// 		disconnect();
// 	}
// 	else
// 	{
// 		async_read(socket_, boost::asio::buffer(user_),
// 			boost::bind(&Connection::handle_user_read, shared_from_this(),
// 			placeholders::error, placeholders::bytes_transferred));
// 	}
// }
// void DBListener::doListen(){
// 	boost::asio::io_service io_service;

// 	cout << "Listening on port " << 30606 << endl;
	
// 	// Listen
// 	tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 30606));

// 	// Create the socket
// 	tcp::socket socket_(io_service);

// 	// Wait for an incoming connection
// 	acceptor_.accept(socket_);

// 	acceptor_.async_accept(socket_, boost::bind(handle_accept, shared_from_this()));

// 	// Read the incoming data
// 	string message=read_(socket_);

// 	cout << message << endl;

// 	// Write back
// 	send_(socket_, "Works!");
// }
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

