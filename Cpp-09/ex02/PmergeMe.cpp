#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <utility>
#include <stdexcept>



PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
: _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}



// Generate Jacobsthal-based insertion order (0-indexed)
std::vector<size_t> PmergeMe::_jacobsthalOrder(size_t n) {
	std::vector<size_t> order;
	if (n == 0) return order;

	order.push_back(0);
	if (n == 1) return order;

	size_t prev2 = 0;
	size_t prev1 = 1;

	while (true) {
		size_t jk = prev1 + 2 * prev2;
		size_t start = jk < n ? jk : n;

		for (size_t i = start; i > prev1; i--)
			order.push_back(i - 1);

		if (jk >= n) break;
		prev2 = prev1;
		prev1 = jk;
	}

	return order;
}



// Ford-Johnson merge-insertion sort for std::vector
void PmergeMe::_sortVector(std::vector<int>& arr) {

	if (arr.size() <= 1) return;

	// 1. Handle odd element (straggler)
	bool hasStraggler = arr.size() % 2 != 0;
	int straggler = 0;
	if (hasStraggler)
		straggler = arr.back();

	// 2. Pair up elements: (larger, smaller)
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] >= arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// 3. Extract larger elements and recursively sort
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	std::vector<std::pair<int, int> > pool = pairs;
	_sortVector(largers);

	// 4. Build main chain and pend (recover pairings after sort)
	std::vector<int> mainChain;
	std::vector<int> pend;

	for (size_t i = 0; i < largers.size(); i++) {
		mainChain.push_back(largers[i]);
		for (size_t j = 0; j < pool.size(); j++) {
			if (pool[j].first == largers[i]) {
				pend.push_back(pool[j].second);
				pool.erase(pool.begin() + j);
				break;
			}
		}
	}

	// 5. Insert pend[0] at beginning (b1 < a1, always true)
	mainChain.insert(mainChain.begin(), pend[0]);

	// Track the position of each winner in mainChain
	// After inserting B1: mainChain = [B1, A1, A2, A3, ...]
	// So A_k is at index k + 1
	std::vector<size_t> winnerPos;
	for (size_t i = 0; i < pend.size(); i++)
		winnerPos.push_back(i + 1);

	// 6. Insert remaining pend elements in Jacobsthal order
	//    with BOUNDED binary search (only search up to paired winner)
	std::vector<size_t> order = _jacobsthalOrder(pend.size());
	for (size_t i = 0; i < order.size(); i++) {
		if (order[i] == 0 || order[i] >= pend.size()) continue;
		size_t idx = order[i];
		int val = pend[idx];

		// Search only from begin to the winner's position (bounded!)
		std::vector<int>::iterator bound = mainChain.begin() + winnerPos[idx];
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), bound, val);

		size_t insertPos = pos - mainChain.begin();
		mainChain.insert(pos, val);

		// Update all winner positions >= insertPos (they shifted right by 1)
		for (size_t j = 0; j < winnerPos.size(); j++) {
			if (winnerPos[j] >= insertPos)
				winnerPos[j]++;
		}
	}

	// 7. Insert straggler
	if (hasStraggler) {
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}



// Ford-Johnson merge-insertion sort for std::deque
void PmergeMe::_sortDeque(std::deque<int>& arr) {
	if (arr.size() <= 1) return;

	bool hasStraggler = arr.size() % 2 != 0;
	int straggler = 0;
	if (hasStraggler)
		straggler = arr.back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] >= arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	std::vector<std::pair<int, int> > pool = pairs;
	_sortDeque(largers);

	std::deque<int> mainChain;
	std::deque<int> pend;

	for (size_t i = 0; i < largers.size(); i++) {
		mainChain.push_back(largers[i]);
		for (size_t j = 0; j < pool.size(); j++) {
			if (pool[j].first == largers[i]) {
				pend.push_back(pool[j].second);
				pool.erase(pool.begin() + j);
				break;
			}
		}
	}

	mainChain.push_front(pend[0]);

	// Track the position of each winner in mainChain
	std::vector<size_t> winnerPos;
	for (size_t i = 0; i < pend.size(); i++)
		winnerPos.push_back(i + 1);

	// Insert remaining pend elements with BOUNDED binary search
	std::vector<size_t> order = _jacobsthalOrder(pend.size());
	for (size_t i = 0; i < order.size(); i++) {
		if (order[i] == 0 || order[i] >= pend.size()) continue;
		size_t idx = order[i];
		int val = pend[idx];

		std::deque<int>::iterator bound = mainChain.begin() + winnerPos[idx];
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), bound, val);

		size_t insertPos = pos - mainChain.begin();
		mainChain.insert(pos, val);

		for (size_t j = 0; j < winnerPos.size(); j++) {
			if (winnerPos[j] >= insertPos)
				winnerPos[j]++;
		}
	}

	if (hasStraggler) {
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}



void PmergeMe::run(int argc, char **argv) {

	// Parse and validate arguments
	for (int i = 1; i < argc; i++) {
		char *endptr;
		long val = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || endptr == argv[i])
			throw std::runtime_error("Error");
		if (val < 0 || val > INT_MAX)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");

	// Print before
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	// Sort and measure time
	clock_t t1 = clock();
	_sortVector(_vec);
	clock_t t2 = clock();

	clock_t t3 = clock();
	_sortDeque(_deq);
	clock_t t4 = clock();

	// Print after
	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	// Print times
	double timeVec = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000000;
	double timeDeq = static_cast<double>(t4 - t3) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
