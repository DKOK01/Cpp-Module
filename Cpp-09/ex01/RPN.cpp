#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>



RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}



bool RPN::_isOperator(const std::string& token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::_applyOperator(const std::string& op) {
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	double b = _stack.top();
	_stack.pop();
	double a = _stack.top();
	_stack.pop();

	if (op == "+")
		_stack.push(a + b);
	else if (op == "-")
		_stack.push(a - b);
	else if (op == "*")
		_stack.push(a * b);
	else if (op == "/") {
		if (b == 0)
			throw std::runtime_error("Error");
		_stack.push(a / b);
	}
}

void RPN::evaluate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (_isOperator(token)) {
			_applyOperator(token);
		} else {
			if (token.length() != 1 || token[0] < '0' || token[0] > '9')
				throw std::runtime_error("Error");
			_stack.push(token[0] - '0');
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	std::cout << _stack.top() << std::endl;
}
