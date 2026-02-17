#include "Span.hpp"

// Orthodox Canonical Form

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}



// Member functions

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (std::size_t i = 2; i < sorted.size(); ++i)
	{
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(max - min);
}




// Exception classes

const char* Span::SpanFullException::what() const throw()
{
	return "Cannot add number: Span is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Cannot find span: not enough numbers stored";
}
