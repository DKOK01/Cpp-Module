#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}



static bool isChar(const std::string& s) {
	return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isInt(const std::string& s) {
	size_t i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i == s.length())
		return false;
	while (i < s.length()) {
		if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	return true;
}

static bool isFloat(const std::string& s) {
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return true;
	size_t i = 0;
	bool dot = false;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i == s.length())
		return false;
	while (i < s.length() - 1) {
		if (s[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!std::isdigit(s[i])) return false;
		i++;
	}
	return s[i] == 'f' && dot;
}

static bool isDouble(const std::string& s) {
	if (s == "-inf" || s == "+inf" || s == "nan")
		return true;
	size_t i = 0;
	bool dot = false;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i == s.length())
		return false;
	while (i < s.length()) {
		if (s[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	return dot;
}



static void printChar(double d, bool impossible) {
	std::cout << "char: ";
	if (impossible || std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d, bool impossible) {
	std::cout << "int: ";
	if (impossible || std::isnan(d) || std::isinf(d) || 
		d < static_cast<double>(std::numeric_limits<int>::min()) || 
		d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d, bool impossible) {
	std::cout << "float: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
		return;
    }
	float f = static_cast<float>(d);
	if (f == static_cast<int>(f) && !std::isinf(f) && !std::isnan(f))
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

static void printDouble(double d, bool impossible) {
	std::cout << "double: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
		return;
    }
	if (d == static_cast<int>(d) && !std::isinf(d) && !std::isnan(d))
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << d << std::endl;
}



void ScalarConverter::convert(const std::string& literal) {
	double d = 0;
	bool impossible = false;

	if (literal.empty()) {
		impossible = true;
	} else if (isChar(literal)) {
		d = static_cast<double>(literal[0]);
	} else if (isInt(literal)) {
		d = std::strtod(literal.c_str(), NULL);
	} else if (isFloat(literal)) {
		d = static_cast<double>(std::strtod(literal.c_str(), NULL));
	} else if (isDouble(literal)) {
		d = std::strtod(literal.c_str(), NULL);
	} else {
		impossible = true;
	}

	printChar(d, impossible);
	printInt(d, impossible);
	printFloat(d, impossible);
	printDouble(d, impossible);
}
