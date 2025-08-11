#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array{
    private:
        T* _elements;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
        class OutOfBounds : public std::exception{
            public:
                const char* what() const throw() {
                    return "Index is out of bounds";
                }
        };
};

#include "Array.tpp"

#endif