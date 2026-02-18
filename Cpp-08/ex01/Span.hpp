#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int number);

	template <typename InputIterator>
	void	addRange(InputIterator begin, InputIterator end)
	{
		unsigned int	distance = 0;
		for (InputIterator tmp = begin; tmp != end; ++tmp)
			++distance;
		if (_numbers.size() + distance > _maxSize)
			throw SpanFullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	// Exception classes
	class SpanFullException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
