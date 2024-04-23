#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <netinet/in.h>
#include <vector>
#include <queue>
#include <iostream>
#include "../Request/Request.hpp"
#include "../Response/Response.hpp"
#include "../config_parser/ConfigData.hpp"

class Client
{

private:
	struct sockaddr_in address;
	socklen_t addrlen;
	Request *request;
	Response *response;
	size_t bytes_to_receive;
	std::string request_body_buf;

public:
	Client();
	~Client();

	struct sockaddr_in &getAndSetAddress(void);
	socklen_t &getAndSetAddrlen(void);

	void createRequest(std::string const &request_header, ConfigData const &config);
	void createResponse(void);

	void removeRequest(void);
	void removeResponse(void);

	Request *getRequest(void);
	Response *getResponse(void);
	size_t &getBytesToReceive(void);

	std::string &getRequestBodyBuf(void);
	void setRequestBodyBuf(std::string const &buf);

	bool isNewRequest(void) const;

	void setBytesToReceive(size_t bytes);
};

#endif