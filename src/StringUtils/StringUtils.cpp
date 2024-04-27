#include "StringUtils.hpp"

std::vector<std::string> StringUtils::splitByDelimiter(const std::string &input, const std::string &delimiter)
{
	std::vector<std::string> result;
	size_t pos = 0;
	size_t prev = 0;
	while ((pos = input.find(delimiter, prev)) != std::string::npos)
	{
		if (pos > prev)
		{
			result.push_back(input.substr(prev, pos - prev));
		}
		prev = pos + delimiter.length(); // Move past delimiter
	}
	// Add the last substring if it exists
	if (prev < input.length())
	{
		result.push_back(input.substr(prev, std::string::npos));
	}
	return result;
}

std::string StringUtils::trim(const std::string &str)
{
	size_t first = str.find_first_not_of(WHITESPACE);
	if (std::string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(WHITESPACE);
	return str.substr(first, (last - first + 1));
}

bool StringUtils::isDigitsOnly(const std::string &str)
{
	return std::all_of(
		str.begin(), str.end(), [](unsigned char c)
		{ return std::isdigit(c); });
}

size_t StringUtils::strToSizeT(const std::string &str)
{
	if (str.empty() || !isDigitsOnly(str))
	{
		throw std::invalid_argument("Invalid string argument");
	}
	try
	{
		unsigned long long value = std::stoull(str);
		if (value > std::numeric_limits<size_t>::max())
		{
			throw std::out_of_range("Value out of range for size_t");
		}
		return static_cast<size_t>(value);
	}
	catch (const std::exception &e)
	{
		throw std::invalid_argument("Invalid string argument");
	}
}

void StringUtils::replaceAll(std::string &str, const std::string &from, const std::string &to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
}