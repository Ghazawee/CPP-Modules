#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "===================================================" << std::endl;
    std::cout << "=== Testing Form ===" << std::endl;
    std::cout << "===================================================" << std::endl;

    // Test 1: Create valid form
    std::cout << "=== Part I : Creation of Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;
    try {
        Form formA("FormA", 50, 25);
        std::cout << "Form Created: " << std::endl;
        std::cout << formA << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Invalid sign grade (too high)
    try {
        Form formB("FormB", 0, 25);  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Error creating FormB: " << e.what() << std::endl;
    }
    
    // Test 3: Invalid execute grade (too low)
    try {
        Form formC("FormC", 50, 151);  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Error creating FormC: " << e.what() << std::endl;
    }
    std::cout << "===================================================" << std::endl;
    std::cout << "=== End of Part I : Creation of Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;

    // Test 4: Bureaucrat signing form
    std::cout << "=== Part II : Bureaucrat Signing Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;
    try {
        Form form("Important Form", 30, 10);
        Bureaucrat alice("Alice", 25);  // High enough to sign
        Bureaucrat bob("Bob", 50);      // Too low to sign
        
        std::cout << "Form before signing: " << std::endl;
        std::cout << form << std::endl;
        std::cout << "Bureaucrats: " << alice << " and " << bob << std::endl;
        
        // Bob tries to sign (should fail)
        bob.signForm(form);
        
        // Alice signs (should work)
        alice.signForm(form);
        std::cout << "Form after signing: " << form << std::endl;
        
        // Try to sign again (should still work)
        alice.signForm(form);
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "===================================================" << std::endl;
    std::cout << "=== End of Part II : Bureaucrat Signing Forms ===" << std::endl;
    std::cout << "===================================================" << std::endl;

    return 0;
}