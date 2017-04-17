#pragma once

#define HELLO_PORT 50013

class server {
public:
	server();
	void startConnection();
	void sendMessage();
	void writeCompletitionCallback(const boost::system::error_code& error, std::size_t transfered_bytes);

private:
	boost::asio::io_service*  IO_handler;
	boost::asio::ip::tcp::socket* socket_forServer;
	boost::asio::ip::tcp::acceptor* server_acceptor;
};

void TCPserver();