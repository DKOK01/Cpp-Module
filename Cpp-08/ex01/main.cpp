#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

int main()
{
    std::cout << "\n--- Subject Example Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;  // Expected: 14
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Exception: Full Span Test ---" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exception: Not Enough Numbers Test ---" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Range Add Test (using std::list) ---" << std::endl;
    try {
        std::list<int> myList;
        myList.push_back(100);
        myList.push_back(200);
        myList.push_back(300);

        Span sp(10);
        sp.addRange(myList.begin(), myList.end());
        std::cout << "Added 3 numbers from a list. Current size: 3" << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Big Load Test: 10,000 Numbers ---" << std::endl;
    try {
        unsigned int n = 10000;
        Span sp(n);
        std::vector<int> v;

        std::srand(std::time(NULL));
        for (unsigned int i = 0; i < n; ++i)
            v.push_back(std::rand());

        sp.addRange(v.begin(), v.end());
        std::cout << "Successfully added " << n << " numbers." << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}