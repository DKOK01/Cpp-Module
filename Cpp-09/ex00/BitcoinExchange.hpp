#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _database;

	bool	_isValidDate(const std::string& date) const;
	bool	_isLeapYear(int year) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	loadDatabase(const std::string& filename);
	void	processInput(const std::string& filename);
};

#endif
