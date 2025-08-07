#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "===================================================" << std::endl;
    std::cout << "=== Testing Form ===" << std::endl;
    std::cout << "===================================================" << std::endl;

    std::cout << "=== Part I : Creation of Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;
    try {
        Form formA("FormA", 50, 25);
        std::cout << "Form Created: " << std::endl;
        std::cout << formA << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    try {
        Form formB("FormB", 0, 25); 
    } catch (const std::exception& e) {
        std::cerr << "Error creating FormB: " << e.what() << std::endl;
    }
    

    try {
        Form formC("FormC", 50, 151); 
    } catch (const std::exception& e) {
        std::cerr << "Error creating FormC: " << e.what() << std::endl;
    }
    std::cout << "===================================================" << std::endl;
    std::cout << "=== End of Part I : Creation of Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;

 
    std::cout << "=== Part II : Bureaucrat Signing Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;
    try {
        Form form("Important Form", 30, 10);
        Bureaucrat alice("Alice", 25); 
        Bureaucrat bob("Bob", 50);     
        
        std::cout << "Form before signing: " << std::endl;
        std::cout << form << std::endl;
        std::cout << "Bureaucrats: " << alice << " and " << bob << std::endl;
        
    
        bob.signForm(form);
        
    
        alice.signForm(form);
        std::cout << "Form after signing: " << form << std::endl;
        
        alice.signForm(form);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "===================================================" << std::endl;
    std::cout << "=== End of Part II : Bureaucrat Signing Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;

    return 0;
}