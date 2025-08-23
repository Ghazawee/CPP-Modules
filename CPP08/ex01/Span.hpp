#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>

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
};


#endif