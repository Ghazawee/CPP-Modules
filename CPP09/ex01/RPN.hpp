#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <algorithm>


class RPN{
    private:
        std::stack<long double> container;
        bool isInt(const std::string& str);
        void push(int value);
        void pop();
        long double top() const;
        bool isEmpty() const;
        size_t size() const;
        void add();
        void subtract();
        void multiply();
        void divide();
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        size_t getResultSize() const;
        long double getResult() const;
        void evaluate(const std::string& argument);

};

#endif