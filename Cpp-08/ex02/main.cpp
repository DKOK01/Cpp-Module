#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::cout << "--- Subject Main Test ---" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n--- Comparison with std::list ---" << std::endl;
    std::list<int> ltest;

    ltest.push_back(5);
    ltest.push_back(17);
    ltest.pop_back();
    ltest.push_back(3);
    ltest.push_back(5);
    ltest.push_back(737);
    ltest.push_back(0);

    std::list<int>::iterator it_l = ltest.begin();
    std::list<int>::iterator ite_l = ltest.end();

    while (it_l != ite_l)
    {
        std::cout << *it_l << std::endl;
        ++it_l;
    }

    std::cout << "\n--- Additional Test: Reverse Iterators ---" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}