#include "Client.hpp"

Client::Client()
	: addrlen(sizeof(address)), request(NULL), response(NULL), is_connection_close(false)
{
}

Client::~Client()
{
	delete request;
	delete response;
}

sockaddr_in &Client::getAndSetAddress()
{
	return (address);
}

socklen_t &Client::getAndSetAddrlen()
{
	return (addrlen);
}

void Client::createRequest(std::string const &request_header, ConfigData const &config)
{
	removeRequest();
	request = new Request(config, request_header); // Create a Request object with the provided header
	request->setChunkSize(0);
}

void Client::createErrorRequest(ConfigData const &config, HttpStatusCode statusCode)
{
	removeRequest();
	request = new Request(config, statusCode); // Create a Request object with the provided header
}

void Client::createResponse()
{
	removeResponse();
	response = new Response(*request); // Create a Response object with the corresponding request
}

void Client::removeRequest()
{
	if (request)
	{
		delete request;
		request = NULL;
	}
}

void Client::removeResponse()
{
	if (response)
	{
		delete response;
		response = NULL;
	}
}

bool Client::isNewRequest() const
{
	return request ? false : true;
}

Request *Client::getRequest() const
{
	return (request);
}

Response *Client::getResponse() const
{
	return (response);
}

// std::string const &Client::getRequestHeaderBuf() const
// {
// 	return (request_header_buf);
// }

bool const &Client::getIsConnectionClose() const
{
	return (is_connection_close);
}

unsigned short int const &Client::getPortNumber() const
{
	return (address.sin_port);
}

in_addr const &Client::getIPv4Address() const
{
	return (address.sin_addr);
}

// void Client::appendToRequestHeaderBuf(char buf[], const ssize_t &bytes)
// {
// 	request_header_buf.append(buf, bytes);
// }

// void Client::resizeRequestHeaderBuf(const size_t &size)
// {
// 	request_header_buf.resize(size);
// }

// void Client::clearRequestHeaderBuf()
// {
// 	request_header_buf.clear();
// }

void Client::setIsConnectionClose(bool const &status)
{
	is_connection_close = status;
}
