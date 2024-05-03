#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <sys/poll.h>
#include <csignal>
#include <iostream>
#include <list>
#include <unistd.h>
#include <chrono>
#include "Server.hpp"
#include "../config_parser/ConfigParser.hpp"

#define TIMEOUT 100000

class ServerManager
{

private:
	std::vector<ConfigData> serverConfigs;
	std::unordered_map<int, std::unique_ptr<Server>> servers;
	std::unordered_map<int, int> client_to_server_map;
	std::list<pollfd> pollfds;
	std::unordered_map<int, std::chrono::steady_clock::time_point> client_last_active_time;

	void createServers();
	const std::pair<const int, std::unique_ptr<Server>> *findServer(ConfigData const &config) const;
	void startServerLoop();
	void handlePoll();
	void checkClientTimeout(int const &ready);
	void handleReadyToRead(std::list<pollfd>::iterator &it);
	void handleReadyToWrite(std::list<pollfd>::iterator &it);
	void handleClientDisconnection(std::list<pollfd>::iterator &it);

public:
	void initServer(const std::vector<ConfigData> &parsedConfigs);
	int runServer();
	void cleanUpForServerShutdown(HttpStatusCode const &statusCode);
	

	class PollException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class ReventErrorFlagException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
