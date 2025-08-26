#include "Span.hpp"

Span::Span() : _size(0){}
Span::Span(unsigned int N) : _size(N) {}
Span::Span(const Span& other) : _size(other._size), _arr(other._arr) {}
Span& Span::operator=(const Span& other){
    if (this != &other){
        _size = other._size;
        _arr = other._arr;
    }
    return *this;
}
Span::~Span(){}
void Span::addNumber(int number){
    if (_arr.size() >= _size)
        throw std::runtime_error("Container is full");
    _arr.push_back(number);
}
int Span::shortestSpan(){
    if (!(_arr.size() >= 2))
        throw std::runtime_error("Minimun of 2 elements must be present");
    std::sort(_arr.begin(), _arr.end());
    int mini_span = _arr[1] - _arr[0];
    unsigned int j = 1;
    while(j < _arr.size() - 1)
    {
        int dis = _arr[j + 1] - _arr[j];
        if(dis < mini_span){
            mini_span = dis;
        }
        j++;
    }
    return mini_span;
}
int Span::longestSpan(){
    if (!(_arr.size() >= 2))
        throw std::runtime_error("Minimun of 2 elements must be present");
    std::sort(_arr.begin(), _arr.end());
    // int long_span = _arr[_arr.size() -1] - _arr[0];
    int long_span = *std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr.begin(), _arr.end());
    return long_span;
}