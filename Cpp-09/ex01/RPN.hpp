#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN {
private:
	std::stack<double> _stack;

	bool	_isOperator(const std::string& token) const;
	void	_applyOperator(const std::string& op);

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void	evaluate(const std::string& expression);
};

#endif
