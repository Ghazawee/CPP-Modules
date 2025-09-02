#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN{
    private:
        std::stack<int> container;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        void push(int value);
        void pop();
        int top() const;
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