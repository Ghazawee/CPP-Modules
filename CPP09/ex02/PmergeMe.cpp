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
    
    std::vector<int> vecCopy = vec;
    std::cout << "Vector before sorting: ";

    std::vector<int>::iterator itv;
    for (itv = vecCopy.begin(); itv != vecCopy.end(); ++itv){
        std::cout << *itv << " ";
    }
    std::cout << std::endl;
    //measure time
    clock_t vecStart = clock();
    FordJohnsonSortVec(vec);
    clock_t vecEnd = clock();
    double vecTime = double(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000; //in microseconds
    //end time
    std::cout << "Vector after sorting: ";
    for (itv = vec.begin(); itv != vec.end(); ++itv){
        std::cout << *itv << " ";
    }
    std::cout << std::endl;
    
    // clock_t deqStart = clock();
    // FordJohnsonSortDeq(deq);
    // clock_t deqEnd = clock();
    // double deqTime = double(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000; //in microseconds
    
    // std::deque<int>::iterator itq;
    // std::cout << "Deq after sorting: ";
    // for (itq = deq.begin(); itq != deq.end(); ++itq){
    //     std::cout << *itq << " ";
    // }
    // std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    // std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsSeqVec(size_t size){
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
    // 
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

    std::cout << "Pairs formed: ";
    for (size_t i = 0; i < pairs.size(); ++i){
        std::cout << " (" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    std::cout << std::endl;
    std::vector<int> largeElements;
    for (size_t i = 0; i < pairs.size(); ++i){
        largeElements.push_back(pairs[i].second);
    }
    std::cout << "Large elements extracted from pairs: ";
    for (size_t i = 0; i < largeElements.size(); ++i){
        std::cout << largeElements[i] << " ";
    }
    std::cout << std::endl;
    FordJohnsonSortVec(largeElements);
    std::vector<int> mainChain = largeElements;
    int smallElem = pairs[0].first;
    std::vector<int>::iterator smallElemIt = std::lower_bound(mainChain.begin(), mainChain.end(), smallElem);
    mainChain.insert(smallElemIt, smallElem);
    std::cout << "Main chain: ";
    for (size_t i = 0; i < mainChain.size(); ++i){
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "pair size: " << pairs.size() << std::endl;
    std::vector<size_t> jacobsSeq = generateJacobsSeqVec(pairs.size());
    std::cout << "Jacob's sequence: ";
    for (size_t i = 0; i < jacobsSeq.size(); ++i){
        std::cout << jacobsSeq[i] << " ";
    }
    std::cout << std::endl;

    std::vector<size_t> insertionOrder;
    for (size_t i = 1; i < jacobsSeq.size(); i++){
        for(size_t j = jacobsSeq[i]; j > jacobsSeq[i - 1]; j--){
            if (j < pairs.size()){
                insertionOrder.push_back(j);
                std::cout << "Insertion order updated with index: " << j << std::endl;
            }
        }
    }
 
    for (size_t i = 0; i < insertionOrder.size(); ++i){
        int element = pairs[insertionOrder[i]].first;
        std::cout << "Inserting element: " << element << std::endl;
        std::vector<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), element);
        mainChain.insert(posToInsert, element);

    }

    if (hasBlackSheep){
        std::vector<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), blackSheep);
        mainChain.insert(posToInsert, blackSheep);
    }
    arr = mainChain;
}

// void PmergeMe::FordJohnsonSortVec(std::vector<int>& arr){
//     std::sort(arr.begin(), arr.end());
// }

std::deque<size_t> PmergeMe::generateJacobsSeqDeq(size_t size){
    std::deque<size_t> jacobseq;

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

void PmergeMe::FordJohnsonSortDeq(std::deque<int>& arr){
    std::deque<int> deq = arr;
    size_t n = deq.size();
    size_t numberOfPairs = n / 2;
    bool hasBlackSheep = (deq.size() % 2 != 0);
    int blackSheep = -1;
    if (hasBlackSheep)
        blackSheep = deq.back();

    if(deq.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < numberOfPairs * 2; i += 2){
        if (deq[i] < deq[i + 1])
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
        else
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
    }

    std::deque<int> largeElements;
    for (size_t i = 0; i < pairs.size(); ++i){
        largeElements.push_back(pairs[i].second);
    }

    FordJohnsonSortDeq(largeElements);
    std::deque<int> mainChain = largeElements;
    int smallElem = pairs[0].first;
    std::deque<int>::iterator smallElemIt = std::lower_bound(mainChain.begin(), mainChain.end(), smallElem);
    mainChain.insert(smallElemIt, smallElem);

    std::deque<size_t> jacobsSeq = generateJacobsSeqDeq(pairs.size());

    std::deque<size_t> insertionOrder;
    for (size_t i = 1; i < jacobsSeq.size(); i++){
        for(size_t j = jacobsSeq[i]; j > jacobsSeq[i - 1]; j--){
            if (j < pairs.size())
                insertionOrder.push_back(j);
        }
    }

    for (size_t i = 0; i < insertionOrder.size(); ++i){
        int element = pairs[insertionOrder[i]].first;
        int left = 0;
        int right = mainChain.size();

        while(left < right){
            int mid = left + ((right - left) / 2);
            if (mainChain[mid] < element)
                left = mid + 1;
            else
                right = mid;
        }
        mainChain.insert(mainChain.begin() + left, element);
        // std::deque<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), element);
        // mainChain.insert(posToInsert, element);

    }

    if (hasBlackSheep){
        // std::deque<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), blackSheep);
        // mainChain.insert(posToInsert, blackSheep);
        int left = 0;
        int right = mainChain.size();

        while(left < right){
            int mid = left + ((right - left) / 2);
            if (mainChain[mid] < blackSheep)
                left = mid + 1;
            else
                right = mid;
        }
        mainChain.insert(mainChain.begin() + left, blackSheep);
    }
    arr = mainChain;
}


// ./PmergeMe 3 2 6 0 1 5 9 8 4 7 17 18 14 12

// ./PmergeMe 3 2 6 0 1 5 9 8 4 7 17 18 14 

// 3 2 6 0 1 5 9 8 4 7 17 18  

// 3 2 6 0 1 5 9 8 4 7 9 7 17 18  

// ./PmergeMe 3 2 6 0 1 5 9 8 4 7