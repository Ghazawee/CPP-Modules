#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Bureaucrat ===" << std::endl;
    
   
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
 
    try {
        Bureaucrat alice("Alice", 0); 
        std::cout << alice << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
  
    try {
        Bureaucrat charlie("Charlie", 151); 
        std::cout << charlie << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
   
    try {
        Bureaucrat diana("Diana", 2);
        std::cout << diana << std::endl;
        
        diana.incrementGrade();
        std::cout << "After increment: " << diana << std::endl;
        
        diana.incrementGrade();
        std::cout << "This shouldn't print" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    
    try {
        Bureaucrat eve("Eve", 149);
        std::cout << eve << std::endl;
        
        eve.decrementGrade(); 
        std::cout << "After decrement: " << eve << std::endl;
        
        eve.decrementGrade(); 
        std::cout << "This shouldn't print" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Temp", 100);
        assigned = original;
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}