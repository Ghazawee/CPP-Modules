#include "iter.hpp"

template<typename T>
void print(T& x) {
    std::cout << x << " ";
}

template<typename T>
void increment(T& x) {
    ++x;
}

int main() {
    int tab[] = {0, 1, 2, 3, 4};
    const int constTab[] = {5, 6, 7, 8, 9};
    std::cout << "Original: ";
    iter(tab, 5, print<int>);
    std::cout << std::endl;
    
    iter(tab, 5, increment<int>);
    
    std::cout << "After increment: ";
    iter(tab, 5, print<int>);
    std::cout << std::endl;

    std::cout << "Const array: ";
    iter(constTab, 5, print<const int>);
    std::cout << std::endl;


    std::string strArray[] = {"Life", "full", "of", "blessings"};
    iter(strArray, 4, print<std::string>);
    std::cout << std::endl;

    return 0;
}