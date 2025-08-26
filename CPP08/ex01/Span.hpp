#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>
#include <stdexcept>

class Span{
    private:
        unsigned int _size;
        std::vector<int> _arr;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        template<typename Iter>
        void addNumbers(Iter begin, Iter end){
            if (_arr.size() + std::distance(begin, end) > _size)
                throw std::runtime_error("Not enough space in container");
            _arr.insert(_arr.end(), begin, end);
        }
};


#endif