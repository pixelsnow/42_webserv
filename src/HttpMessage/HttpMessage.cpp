#include "HttpMessage.hpp"

HttpMessage::HttpMessage(ConfigData const &config,
						 HttpStatusCode statusCode,
						 HttpMethod method,
						 size_t contentLength,
						 bool chunked,
						 ConnectionValue connection,
						 int httpVersionMajor,
						 int httpVersionMinor)
	: _config(config),
	  _statusCode(statusCode),
	  _method(method),
	  _contentLength(contentLength),
	  _chunked(chunked),
	  _connection(connection),
	  _httpVersionMajor(httpVersionMajor),
	  _httpVersionMinor(httpVersionMinor)
{
}

ConfigData const &HttpMessage::getConfig() const
{
	return this->_config;
}

std::vector<std::byte> HttpMessage::getBody() const
{
	return this->_body;
}

HttpStatusCode HttpMessage::getStatusCode() const
{
	return this->_statusCode;
}

size_t HttpMessage::getContentLength() const
{
	return this->_contentLength;
}

ConnectionValue HttpMessage::getConnection() const
{
	return this->_connection;
}

std::chrono::system_clock::time_point HttpMessage::getDate() const
{
	return this->_date;
}

HttpMethod HttpMessage::getMethod() const
{
	return this->_method;
}

std::string HttpMessage::getTarget() const
{
	return this->_target;
}

int HttpMessage::getHttpVersionMajor() const
{
	return this->_httpVersionMajor;
}

int HttpMessage::getHttpVersionMinor() const
{
	return this->_httpVersionMinor;
}

bool HttpMessage::isChunked() const
{
	return this->_chunked;
}

ContentType HttpMessage::getContentType() const
{
	return this->_contentType;
}