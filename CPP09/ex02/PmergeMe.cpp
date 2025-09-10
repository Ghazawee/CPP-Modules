#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq){}
PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

void PmergeMe::processInput(int ac, char **av){
    if (ac < 2){
        throw std::runtime_error("Usage: ./PmergeMe <positive integers>\n Example: ./PmergeMe 3 5 9 7 1 ...");
    }
    for (int i = 1; i < ac; ++i){
        char* end;
        long value = std::strtol(av[i], &end, 10);
        if (*end != '\0' || value < 0 || value > INT_MAX)
            throw std::runtime_error("Error: Invalid Input. Must be positive integers are allowed and within the range of int.\n(int max: 2147483647).");
        vec.push_back(static_cast<int>(value));
        deq.push_back(static_cast<int>(value));
    }
}
void PmergeMe::sortAndDisplay(){
    
    if (vec.size() == 1)
        return;
    std::vector<int> vecCopy = vec;
    std::cout << "Vector before sorting: ";

    std::vector<int>::iterator itv;
    for (itv = vecCopy.begin(); itv != vecCopy.end(); ++itv){
        std::cout << *itv << " ";
    }
    std::cout << std::endl;
    clock_t vecStart = clock();
    FordJohnsonSortVec(vec);
    clock_t vecEnd = clock();
    double vecTime = double(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;
    
    clock_t deqStart = clock();
    FordJohnsonSortDeq(deq);
    clock_t deqEnd = clock();
    double deqTime = double(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "Vector after sorting: ";
    for (itv = vec.begin(); itv != vec.end(); ++itv){
        std::cout << *itv << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us"<< std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
}

void PmergeMe::createSortedPairsVec(const std::vector<std::pair<int, int> >& pairs,const std::vector<int>& mainChain, std::vector<std::pair<int,int> >& sortedPairs){
    
        std::vector<char> used(pairs.size(), 0);
        sortedPairs.clear();
        sortedPairs.reserve(pairs.size());
        for (size_t i = 0; i < mainChain.size(); ++i){
            int leader = mainChain[i];
            for(size_t j = 0; j < pairs.size(); ++j){
                if (!used[j] && pairs[j].second == leader){
                    sortedPairs.push_back(pairs[j]);
                    used[j] = 1;
                    break;
                }
            }
        }

}
std::vector<int>::iterator PmergeMe::boundByPartnerVec(std::vector<int>& mainChain, std::vector<int>::iterator partner, int element){
    return std::lower_bound(mainChain.begin(), partner, element);
}

std::vector<size_t> PmergeMe::generateJacobsSeqVec(size_t size){
    std::vector<size_t> jacobseq;

    size_t a = 0, b = 1;
    jacobseq.push_back(a);
    if (size > 0)
        jacobseq.push_back(b);
    while (jacobseq.back() < size){
        size_t next = b + 2 * a;
        if (next > size)
            break;
        jacobseq.push_back(next);
        a = b;
        b = next;
    }
    return jacobseq;
}
void PmergeMe::FordJohnsonSortVec(std::vector<int>& arr){
    std::vector<int> vec = arr;
    size_t n = vec.size();
    size_t numberOfPairs = n / 2;
    bool hasBlackSheep = (vec.size() % 2 != 0);
    int blackSheep = -1;
    if (hasBlackSheep)
        blackSheep = vec.back();

    if(vec.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < numberOfPairs * 2; i += 2){
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    std::vector<int> largeElements;
    for (size_t i = 0; i < pairs.size(); ++i){
        largeElements.push_back(pairs[i].second);
    }
      
    FordJohnsonSortVec(largeElements);
    std::vector<int> mainChain = largeElements;
    std::vector<std::pair<int, int> > sortedPairs;
    createSortedPairsVec(pairs, mainChain, sortedPairs);
    if (!sortedPairs.empty()){
        int B0 = sortedPairs[0].first;
        int A0 = sortedPairs[0].second;
        std::vector<int>::iterator posA0 = std::lower_bound(mainChain.begin(), mainChain.end(), A0);
        std::vector<int>::iterator posB0 = boundByPartnerVec(mainChain, posA0, B0);
        mainChain.insert(posB0, B0);
    }

    std::vector<size_t> jacobsSeq = generateJacobsSeqVec(sortedPairs.size());
    std::vector<size_t> insertionOrder;
    for (size_t i = 1; i < jacobsSeq.size(); i++){
        for(size_t j = jacobsSeq[i]; j > jacobsSeq[i - 1]; j--){
            if (j < sortedPairs.size()){
                insertionOrder.push_back(j);
            }
        }
    }

    size_t last = jacobsSeq.empty() ? 0 : jacobsSeq.back();
    for (size_t j = sortedPairs.size() -1; j > last; j--){
        insertionOrder.push_back(j);
    }
 
    for (size_t i = 0; i < insertionOrder.size(); ++i){
        size_t idx = insertionOrder[i];
        int A = sortedPairs[idx].second;
        int B = sortedPairs[idx].first;
        std::vector<int>::iterator posA = std::lower_bound(mainChain.begin(), mainChain.end(), A);
        std::vector<int>::iterator posB = boundByPartnerVec(mainChain, posA, B);

        mainChain.insert(posB, B);
    }

    if (hasBlackSheep){
        std::vector<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), blackSheep);// if it doesnt find 
        mainChain.insert(posToInsert, blackSheep);
        
    }
    arr = mainChain;
}



void PmergeMe::createSortedPairsDeq(const std::deque<std::pair<int, int> >& pairs,const std::deque<int>& mainChain, std::deque<std::pair<int,int> >& sortedPairs){
    
    std::deque<char> used(pairs.size(), 0);
    sortedPairs.clear();
    for (size_t i = 0; i < mainChain.size(); ++i){
        int leader = mainChain[i];
        for(size_t j = 0; j < pairs.size(); ++j){
            if (!used[j] && pairs[j].second == leader){
                sortedPairs.push_back(pairs[j]);
                used[j] = 1;
                break;
            }
        }
    }

}
std::deque<int>::iterator PmergeMe::boundByPartnerDeq(std::deque<int>& mainChain, std::deque<int>::iterator partner, int element){
    return std::lower_bound(mainChain.begin(), partner, element);
}

std::deque<size_t> PmergeMe::generateJacobsSeqDeq(size_t size){
    std::deque<size_t> jacobseq;

    size_t a = 0, b = 1;
    jacobseq.push_back(a);
    if (size > 0)
        jacobseq.push_back(b);
    while (jacobseq.back() < size){
        size_t next = b + 2 * a;
        if (next > size)
            break;
        jacobseq.push_back(next);
        a = b;
        b = next;
    }
    return jacobseq;
}
void PmergeMe::FordJohnsonSortDeq(std::deque<int>& arr){
    std::deque<int> vec = arr;
    size_t n = vec.size();
    size_t numberOfPairs = n / 2;
    bool hasBlackSheep = (vec.size() % 2 != 0);
    int blackSheep = -1;
    if (hasBlackSheep)
        blackSheep = vec.back();

    if(vec.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < numberOfPairs * 2; i += 2){
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    std::deque<int> largeElements;
    for (size_t i = 0; i < pairs.size(); ++i){
        largeElements.push_back(pairs[i].second);
    }

    FordJohnsonSortDeq(largeElements);
    std::deque<int> mainChain = largeElements;
    std::deque<std::pair<int, int> > sortedPairs;
    createSortedPairsDeq(pairs, mainChain, sortedPairs);
    if (!sortedPairs.empty()){
        int B0 = sortedPairs[0].first;
        int A0 = sortedPairs[0].second;
        std::deque<int>::iterator posA0 = std::lower_bound(mainChain.begin(), mainChain.end(), A0);
        std::deque<int>::iterator posB0 = boundByPartnerDeq(mainChain, posA0, B0);
        mainChain.insert(posB0, B0);
    }


    std::deque<size_t> jacobsSeq = generateJacobsSeqDeq(sortedPairs.size());

    std::deque<size_t> insertionOrder;
    for (size_t i = 1; i < jacobsSeq.size(); i++){
        for(size_t j = jacobsSeq[i]; j > jacobsSeq[i - 1]; j--){
            if (j < sortedPairs.size()){
                insertionOrder.push_back(j);
            }
        }
    }

    size_t last = jacobsSeq.empty() ? 0 : jacobsSeq.back();
    for (size_t j = sortedPairs.size() -1; j > last; j--){
        insertionOrder.push_back(j);
    }

    for (size_t i = 0; i < insertionOrder.size(); ++i){
        size_t idx = insertionOrder[i];
        int A = sortedPairs[idx].second;
        int B = sortedPairs[idx].first;
        std::deque<int>::iterator posA = std::lower_bound(mainChain.begin(), mainChain.end(), A);
        std::deque<int>::iterator posB = boundByPartnerDeq(mainChain, posA, B);
        mainChain.insert(posB, B);

    }

    if (hasBlackSheep){
        std::deque<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), blackSheep);
        mainChain.insert(posToInsert, blackSheep);
    }
    arr = mainChain;
}
