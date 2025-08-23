#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <exception>


template<typename T>
typename T::iterator easyfind(T array, int element){
    typename T::iterator it= std::find(array.begin(), array.end(), element);
    if (it == array.end())
        throw std::runtime_error("Element not found in the container");
    return it;
}

#endif