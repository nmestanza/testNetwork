#include "Server.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>



void server::writeCompletitionCallback(const boost::system::error_code& error, std::size_t transfered_bytes) {
	std::cout << std::endl << "Write Callback called" << std::endl;
}

void server::startConnection() {
	server_acceptor->accept(*socket_forServer);
}

void server::sendMessage() {
	std::string message("Hello from server.");

	boost::function<void(const boost::system::error_code&, std::size_t)> handler(
		boost::bind(&server::writeCompletitionCallback, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));

	boost::asio::async_write(*socket_forServer, boost::asio::buffer(message), handler);
}

server::server() {
	IO_handler = new boost::asio::io_service();
	socket_forServer = new boost::asio::ip::tcp::socket(*IO_handler);
	server_acceptor = new boost::asio::ip::tcp::acceptor(*IO_handler,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), HELLO_PORT));
	std::cout << std::endl << "Ready. Port " << HELLO_PORT << " created" << std::endl;
}

void TCPserver()
{
	server conquering;
	std::cout << std::endl << "Start Listening on port " << HELLO_PORT << std::endl;
	conquering.startConnection();
	std::cout << "Somebody connected to port " << HELLO_PORT << std::endl;
	conquering.sendMessage();
}

