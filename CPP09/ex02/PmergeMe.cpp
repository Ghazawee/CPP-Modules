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
        throw std::runtime_error("Usage: ./PmergeMe <positive integers>\n Example: ./PmergeMe 3 5 9 7 1");
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
    
    FordJohnsonSortVec(vec);
}

std::vector<size_t> PmergeMe::generateJacobsSeq(size_t size){
    std::vector<size_t> jacobseq;

    size_t a = 0, b = 1;
    jacobseq.push_back(a);
    if (size > 0)
        jacobseq.push_back(b);
    while (jacobseq.back() < size){
        size_t next = b + 2 * a;
        if (next >= size)
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
    // bool hasBlackSheep = (vec.size() % 2 != 0);
    // int blackSheep = -1;
    // if (hasBlackSheep)
    //     blackSheep = vec.back();

    if(vec.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < numberOfPairs * 2; i += 2){
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
    std::cout << "Pairs formed: ";
    for (size_t i = 0; i < pairs.size(); ++i){
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    std::cout << std::endl;

    std::vector<int> largeElements;
    for (size_t i = 0; i < pairs.size(); ++i){
        largeElements.push_back(pairs[i].second);
    }
    std::cout << "largeElement formed: ";
    std::cout << "{ ";
    for (size_t i = 0; i < largeElements.size(); ++i){
        std::cout <<largeElements[i] << ", ";
    }
    std::cout << "}"<<std::endl;

    FordJohnsonSortVec(largeElements);
    std::vector<int> mainChain;
    mainChain.push_back(pairs[0].first);
    for (size_t i = 0; i < largeElements.size(); ++i){
        mainChain.push_back(largeElements[i]);
    }
    std::cout << "mainChain formed: ";
    std::cout << "{ ";
    for (size_t i = 0; i < mainChain.size(); ++i){
        std::cout <<mainChain[i] << ", ";
    }
    std::cout << "}"<<std::endl;

    std::vector<size_t> jacobsSeq = generateJacobsSeq(pairs.size());
    std::cout << "Jacob's sequence: ";
    for (size_t i = 0; i < jacobsSeq.size(); ++i){
        std::cout << jacobsSeq[i] << " ";
    }
    std::cout << std::endl;
    std::vector<size_t> insertionOrder;
    for (size_t i = 1; i < jacobsSeq.size(); i++){
        for(size_t j = jacobsSeq[i]; j > jacobsSeq[i - 1]; j--){
            if (j < pairs.size())
                insertionOrder.push_back(j);
        }
    }
    std::cout << "Insertion order: ";
    for (size_t i = 0; i < insertionOrder.size(); ++i){
        std::cout << insertionOrder[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < insertionOrder.size(); ++i)
}
void PmergeMe::FordJohnsonSortDeq(std::deque<int>& arr){(void)arr;}