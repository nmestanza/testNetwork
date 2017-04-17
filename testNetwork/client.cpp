#include "client.h"
#include <iostream>
#include <boost/asio.hpp>

#define HELLO_PORT_STR "50013"
#define SERVER_IP "localhost"

class client {
public:
	client();
	void startConnection(const char* host);
	void receiveMessage();

private:
	boost::asio::io_service* IO_handler;
	boost::asio::ip::tcp::socket* socket_forClient;
	boost::asio::ip::tcp::resolver* client_resolver;
	boost::asio::ip::tcp::resolver::iterator endpoint;
};

client::client() {
	IO_handler = new boost::asio::io_service();
	socket_forClient = new boost::asio::ip::tcp::socket(*IO_handler);
	client_resolver = new boost::asio::ip::tcp::resolver(*IO_handler);
}

void client::startConnection(const char* host) {
	endpoint = client_resolver->resolve(
		boost::asio::ip::tcp::resolver::query(host, HELLO_PORT_STR));
	std::cout << "Trying to connect to " << host << " on port " << HELLO_PORT_STR << std::endl;
	boost::asio::connect(*socket_forClient, endpoint);
}

void client::receiveMessage() {
	boost::system::error_code error;
	char buf[512];
	size_t len = 0;
	std::cout << "Receiving Message" << std::endl;
	do
	{
		len = socket_forClient->read_some(boost::asio::buffer(buf), error);

		if (!error)
		{
			std::cout << '|';
			buf[len] = '\0';
		}

	} while (!error);

	if (error != boost::asio::error::eof)
		std::cout << std::endl << "Server sais: " << buf << std::endl;
	else
		std::cout << "Error while trying to connect to server %d" << error.message() << std::endl;
}

void asioTcpClient(const char* host)
{
	client conquering;
	conquering.startConnection(host);
	conquering.receiveMessage();

}
#include <Windows.h>
int main(int argc, char* argv[])
{
	asioTcpClient(SERVER_IP);
	Sleep(10000);
}