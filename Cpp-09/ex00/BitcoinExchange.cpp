#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}




bool BitcoinExchange::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;


	for (size_t i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;

	return day <= daysInMonth[month - 1];
}




void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
        throw	std::runtime_error("Error: invalid database header.");

	while (std::getline(file, line)) {

		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date    = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);

		float rate = static_cast<float>(std::strtod(rateStr.c_str(), NULL));
		_database[date] = rate;
	}
	file.close();
}


void BitcoinExchange::processInput(const std::string& filename) {

	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid input header.");

	while (std::getline(file, line)) {

		size_t sep = line.find(" | ");
		if (sep == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date		= line.substr(0, sep);
		std::string valueStr	= line.substr(sep + 3);

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (valueStr.empty()) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		char	*endptr;
		double	value = std::strtod(valueStr.c_str(), &endptr);
		if (endptr == valueStr.c_str()) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		while (*endptr) {
			if (!std::isspace(static_cast<unsigned char>(*endptr)))
				break;
			endptr++;
		}
		if (*endptr != '\0') {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}


		if (value != value) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = _database.lower_bound(date);

		if (it != _database.end() && it->first == date) {
		} else if (it != _database.begin()) {
			--it;
		} else {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		float result = static_cast<float>(value) * it->second;
		std::cout << date << " => " << valueStr << " = " << result << std::endl;
	}
	file.close();
}
