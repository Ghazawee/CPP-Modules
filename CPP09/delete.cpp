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

FordJohnsonSortdeq(largeElements);
std::deque<int> mainChain = largeElements;
int smallElem = pairs[0].first;
std::deque<int>::iterator smallElemIt = std::lower_bound(mainChain.begin(), mainChain.end(), smallElem);
mainChain.insert(smallElemIt, smallElem);

std::deque<size_t> jacobsSeq = generateJacobsSeq(pairs.size());

std::deque<size_t> insertionOrder;
for (size_t i = 1; i < jacobsSeq.size(); i++){
    for(size_t j = jacobsSeq[i]; j > jacobsSeq[i - 1]; j--){
        if (j < pairs.size())
            insertionOrder.push_back(j);
    }
}

for (size_t i = 0; i < insertionOrder.size(); ++i){
    int element = pairs[insertionOrder[i]].first;

    std::deque<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), element);
    mainChain.insert(posToInsert, element);

}

if (hasBlackSheep){
    std::deque<int>::iterator posToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), blackSheep);
    mainChain.insert(posToInsert, blackSheep);
}
arr = mainChain;



std::deque<size_t> PmergeMe::generateJacobsSeq(size_t size){
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