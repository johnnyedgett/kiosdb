#ifndef DBCONNECTION
#define DBCONNECTION
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
class DBConnection : public boost::enable_shared_from_this<DBConnection>
{
public:
    typedef boost::shared_ptr<DBConnection> pointer;
    static pointer create(boost::asio::io_context& io_context)
    {
        return pointer(new DBConnection(io_context));
    }
    tcp::socket& socket()
    {
        return socket_;
    }
    void start()
    {
        message_ = "Hotdog";

        boost::asio::async_write(socket_, boost::asio::buffer(message_),
            boost::bind(&DBConnection::handle_write, shared_from_this(),
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
    }

private:
    DBConnection(boost::asio::io_context& io_context)
    : socket_(io_context)
    {
    }

    void handle_write(const boost::system::error_code& /*error*/,
        size_t /*bytes_transferred*/)
    {
    }

    tcp::socket socket_;
    std::string message_;
};
#endif