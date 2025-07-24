#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Bureaucrat ===" << std::endl;
    
    // Test 1: Normal creation
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Grade too high
    try {
        Bureaucrat alice("Alice", 0); // Should throw
        std::cout << alice << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 3: Grade too low
    try {
        Bureaucrat charlie("Charlie", 151); // Should throw
        std::cout << charlie << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 4: Increment/Decrement
    try {
        Bureaucrat diana("Diana", 2);
        std::cout << diana << std::endl;
        
        diana.incrementGrade(); // Should work (grade becomes 1)
        std::cout << "After increment: " << diana << std::endl;
        
        diana.incrementGrade(); // Should throw (can't go below 1)
        std::cout << "This shouldn't print" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 5: Decrement at boundary
    try {
        Bureaucrat eve("Eve", 149);
        std::cout << eve << std::endl;
        
        eve.decrementGrade(); // Should work (grade becomes 150)
        std::cout << "After decrement: " << eve << std::endl;
        
        eve.decrementGrade(); // Should throw (can't go above 150)
        std::cout << "This shouldn't print" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 6: Copy constructor and assignment
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Temp", 100);
        assigned = original;
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}