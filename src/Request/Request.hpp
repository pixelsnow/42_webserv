#ifndef REQUEST_HPP
#define REQUEST_HPP

// TODO: check includes
#include "../defines.hpp"
#include <string>
#include <unordered_map>
#include <regex>
#include <algorithm>
#include <limits>
#include "../HttpMessage/HttpMessage.hpp"
#include "../StringUtils/StringUtils.hpp"

class Request : public HttpMessage
{
private:
	// STRUCTS

	struct RequestLine
	{
		std::string method;
		std::string requestTarget;
		std::string HTTPVersionMajor;
		std::string HTTPVersionMinor;
		/*
		When a major version of HTTP does not define any minor versions, the minor version "0" is implied. A recipient that receives a message with a major version number that it implements and a minor version number higher than what it implements SHOULD process the message as if it were in the highest minor version within that major version to which the recipient is conformant.
		*/
		// What about version 1.0 - do we need to ask to upgrade? probably yes
	};

	// PROPERTIES

	// Helper properties for initial data read
	std::unordered_map<std::string, std::string> _headerLines;
	RequestLine _requestLine;

	// Properties unique to Request
	bool _bodyExpected;
	std::string _userAgent;
	std::string _host;
	int _port;
	std::string _transferEncoding;
	std::string _charset;

	// OPTIONAL: handle Expect header

	// METHODS

	// helpers

	std::string removeComments(const std::string &input) const;
	// initial data reading
	void extractRequestLine(const std::string &requestLine);
	void extractHeaderLine(const std::string &headerLine);
	// parsing
	int parseMajorVersion();
	int parseMinorVersion();
	HttpMethod matchValidMethod();
	HttpMethod parseMethod();
	std::string parseTarget();
	void validateMethod();

	void parseRequestLine();
	void parseHost();
	void parseContentLength();
	void parseTransferEncoding();
	void parseUserAgent();
	void parseHeaders();
	void parseConnection();
	void parseContentType();

	// main function
	void processRequest(const std::string &requestLineAndHeaders);

public:
	Request(const ConfigData &config, const std::string &requestLineAndHeaders);
	Request(const ConfigData &config, HttpStatusCode statusCode);
	Request(const std::vector<ConfigData> &configs, const std::string &requestLineAndHeaders);
	Request(const std::vector<ConfigData> &configs, HttpStatusCode statusCode);

	// SETTERS

	void appendToBody(const std::vector<std::byte> &newBodyChunk);
	void appendToBody(char newBodyChunk[], const ssize_t &bytes);
	void resizeBody(const size_t &n);

	// GETTERS

	std::string getHost() const;
	std::string getUserAgent() const;
	bool isBodyExpected() const;
	std::string getTransferEncoding() const;
	std::string getMethodStr() const;

	// EXCEPTIONS

	class BadRequestException : public std::exception
	{
	};

	// DEBUG
	void printRequestProperties() const;
};

#endif