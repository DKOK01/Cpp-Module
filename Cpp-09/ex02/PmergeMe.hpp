#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe {
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	std::vector<size_t>	_jacobsthalOrder(size_t n);
	void				_sortVector(std::vector<int>& arr);
	void				_sortDeque(std::deque<int>& arr);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void run(int argc, char **argv);
};

#endif
