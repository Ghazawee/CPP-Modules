#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& array, int element){
    typename T::iterator it= std::find(array.begin(), array.end(), element);
    if (it == array.end())
        throw std::runtime_error("Element not found in the container");
    return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& array, int element){
    typename T::const_iterator it= std::find(array.begin(), array.end(), element);
    if (it == array.end())
        throw std::runtime_error("Element not found in the container");
    return it;
}

#endif