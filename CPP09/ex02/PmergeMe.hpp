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
#include <climits>


class PmergeMe{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        std::vector<size_t> generateJacobsSeqVec(size_t size);
        std::deque<size_t> generateJacobsSeqDeq(size_t size);
        void FordJohnsonSortVec(std::vector<int>& arr);
        void FordJohnsonSortDeq(std::deque<int>& arr);
        void createSortedPairsVec(const std::vector<std::pair<int, int> >& pairs,const std::vector<int>& mainChain, std::vector<std::pair<int,int> >& sortedPairs);
        std::vector<int>::iterator boundByPartnerVec(std::vector<int>& mainChain, std::vector<int>::iterator partner, int element);
        void createSortedPairsDeq(const std::deque<std::pair<int, int> >& pairs,const std::deque<int>& mainChain, std::deque<std::pair<int,int> >& sortedPairs);
        std::deque<int>::iterator boundByPartnerDeq(std::deque<int>& mainChain, std::deque<int>::iterator partner, int element);
    public:
        void processInput(int ac, char **av);
        void sortAndDisplay();
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
};

#endif