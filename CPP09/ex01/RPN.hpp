#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cfloat>

class RPN{
    private:
        std::stack<long double> container;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        void push(int value);
        void pop();
        long double top() const;
        bool isEmpty() const;
        size_t size() const;
        void add();
        void subtract();
        void multiply();
        void divide();
        //need function to evaluate expression from string and store result in stack
        void evaluate(const std::string& argument);
        bool isInt(const std::string& str);

};

#endif