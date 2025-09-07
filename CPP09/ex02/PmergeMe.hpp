#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <climits>


class PmergeMe{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        std::vector<size_t> generateJacobsSeqVec(size_t size);
        std::deque<size_t> generateJacobsSeqDeq(size_t size);
        void FordJohnsonSortVec(std::vector<int>& arr);
        void FordJohnsonSortDeq(std::deque<int>& arr);
    public:
        void processInput(int ac, char **av);
        void sortAndDisplay();
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
};

#endif