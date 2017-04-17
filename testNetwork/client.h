#pragma once

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

void asioTcpClient(const char* host);