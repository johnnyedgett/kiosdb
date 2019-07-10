#ifndef DBLISTENER
#define DBLISTENER

#include "DBConnection.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>

using boost::asio::ip::tcp;

class DBListener
{
public:
	DBListener(boost::asio::io_context& io_context)
	: io_context_(io_context),
		acceptor_(io_context, tcp::endpoint(tcp::v4(), 13))
  	{
    	start_accept();
  	}

private:
	void start_accept()
  	{
    	DBConnection::pointer new_connection = DBConnection::create(io_context_);

		acceptor_.async_accept(new_connection->socket(),
			boost::bind(&DBListener::handle_accept, this, new_connection,
			boost::asio::placeholders::error));
  	}

	void handle_accept(DBConnection::pointer new_connection,
		const boost::system::error_code& error)
  	{
		if (!error)
    	{
     		new_connection->start();
    	}
    	start_accept();
	}

	boost::asio::io_context& io_context_;
	tcp::acceptor acceptor_;
};

#endif