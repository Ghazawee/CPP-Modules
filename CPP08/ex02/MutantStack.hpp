#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack() : std::stack<T>(){}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            if (*this != other){
                std::stack<T>::operator=(other);
            }
            return *this;
        }
        ~MutantStack(){}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin(){ return this->c.begin();}
        iterator end(){ return this->c.end();}
        const_iterator cbegin() const{ return this->c.begin();}
        const_iterator cend()const{ return this->c.end();}
        reverse_iterator rbegin(){ return this->c.rbegin();}
        reverse_iterator rend(){ return this->c.rend();}
        const_reverse_iterator crbegin(){ return this->c.rbegin();}
        const_reverse_iterator crend(){ return this->c.rend();}
};
#endif