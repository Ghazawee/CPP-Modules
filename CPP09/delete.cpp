void PmergeMe::createSortedPairsVec(const std::deque<std::pair<int, int> >& pairs,const std::deque<int>& mainChain, std::deque<std::pair<int,int> >& sortedPairs){
    
    std::deque<char> used(pairs.size(), 0);
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
std::deque<int>::iterator PmergeMe::boundByPartner(std::deque<int>& mainChain, std::deque<int>::iterator partner, int element){
return std::lower_bound(mainChain.begin(), partner, element);
}

std::deque<size_t> PmergeMe::generateJacobsSeqVec(size_t size){
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
void PmergeMe::FordJohnsonSortVec(std::deque<int>& arr){
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

FordJohnsonSortVec(largeElements);
std::deque<int> mainChain = largeElements;
std::deque<std::pair<int, int> > sortedPairs;
createSortedPairsVec(pairs, mainChain, sortedPairs);
if (!sortedPairs.empty()){
    int B0 = sortedPairs[0].first;
    int A0 = sortedPairs[0].second;
    std::deque<int>::iterator posA0 = std::lower_bound(mainChain.begin(), mainChain.end(), A0);
    std::deque<int>::iterator posB0 = boundByPartner(mainChain, posA0, B0);
    mainChain.insert(posB0, B0);
}
// int smallElem = pairs[0].first;
// std::deque<int>::iterator smallElemIt = std::lower_bound(mainChain.begin(), mainChain.end(), smallElem);
// mainChain.insert(smallElemIt, smallElem);


std::cout << "pair size: " << pairs.size() << std::endl;
std::deque<size_t> jacobsSeq = generateJacobsSeqVec(sortedPairs.size());
std::cout << "Jacob's sequence: ";
for (size_t i = 0; i < jacobsSeq.size(); ++i){
    std::cout << jacobsSeq[i] << " ";
}
std::cout << std::endl;

std::deque<size_t> insertionOrder;
for (size_t i = 1; i < jacobsSeq.size(); i++){
    for(size_t j = jacobsSeq[i]; j > jacobsSeq[i - 1]; j--){
        if (j < sortedPairs.size()){
            insertionOrder.push_back(j);
            std::cout << "Insertion order updated with index: " << j << std::endl;
        }
    }
}

size_t last = jacobsSeq.empty() ? 0 : jacobsSeq.back();
for (size_t j = sortedPairs.size() -1; j > last; j--){
    insertionOrder.push_back(j);
    std::cout << "Insertion order updated with index: " << j << std::endl;
}

for (size_t i = 0; i < insertionOrder.size(); ++i){
    size_t idx = insertionOrder[i];
    int A = sortedPairs[idx].second;
    int B = sortedPairs[idx].first;
    std::deque<int>::iterator posA = std::lower_bound(mainChain.begin(), mainChain.end(), A);
    std::deque<int>::iterator posB = boundByPartner(mainChain, posA, B);
    mainChain.insert(posB, B);
    // int element = pairs[insertionOrder[i]].first;
    // std::cout << "Inserting element: " << element << std::endl;
    // std::deque<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), element);
    // mainChain.insert(posToInsert, element);

}

if (hasBlackSheep){
    std::deque<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), blackSheep);
    mainChain.insert(posToInsert, blackSheep);
}
arr = mainChain;
}