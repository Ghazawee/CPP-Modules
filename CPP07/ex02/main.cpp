#include "Array.hpp"

int main() {
    std::cout << "=== Testing default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    std::cout << "\n=== Testing constructor with size ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    // Test default initialization
    std::cout << "Default values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Testing element assignment ===" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    
    std::cout << "After assignment: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Copy array: ";
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Testing deep copy (modifying original) ===" << std::endl;
    intArray[0] = 999;
    std::cout << "Original[0]: " << intArray[0] << std::endl;
    std::cout << "Copy[0]: " << copyArray[0] << std::endl;

    std::cout << "\n=== Testing assignment operator ===" << std::endl;
    Array<int> assignArray;
    assignArray = intArray;
    std::cout << "Assigned array size: " << assignArray.size() << std::endl;
    std::cout << "Assigned array[0]: " << assignArray[0] << std::endl;

    std::cout << "\n=== Testing with different type (string) ===" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "42";
    
    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }
    // const Array<int> constIntArray(intArray);
    // constIntArray[0] = 42;  // const shouldnt be able to modify
    // std::cout << "constIntArray[0]: " << constIntArray[0] << std::endl;
    std::cout << "\n=== Testing out of bounds exception ===" << std::endl;
    try {
        std::cout << "Trying to access index 10..." << std::endl;
        std::cout << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to access empty array..." << std::endl;
        std::cout << empty[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}