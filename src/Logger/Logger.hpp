/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:08:00 by nlonka            #+#    #+#             */
/*   Updated: 2024/05/04 21:32:49 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "../defines.hpp"
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cstdarg>

// modify logger options here
#define LOG_BUF_SIZE 512
#define LOG_TO_FILE false
#define LOG_TO_STDERR true
#define LOG_FILE(number) ("log" + number + ".txt")

// type colours
#define CLIENT GREEN
#define SERVER BLUE
#define ERROR_MESSAGE RED

enum e_log_level
{
	INFO,
	DEBUG,
	ERROR
};

class Logger
{
private:
	const static std::string _toString(size_t num);
	const static std::string _createTimeStamp();
	const static std::string _levelToString(e_log_level level);

public:
	static void initLogger();
	static void log(e_log_level level, const char *type, const char *msg, ...);
};

#endif // LOGGER_HPP
