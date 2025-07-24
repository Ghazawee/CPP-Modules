#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    
    // srand(time(0));
    std::cout << "=== Testing Concrete Forms ===" << std::endl;
    
    try {
        // Create bureaucrats with different grades
        Bureaucrat lowGrade("Bob", 150);
        Bureaucrat midGrade("Alice", 45);
        Bureaucrat highGrade("Boss", 1);
        
        std::cout << lowGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << highGrade << std::endl;
        std::cout << std::endl;
        
        // Test ShrubberyCreationForm (sign: 145, exec: 137)
        std::cout << "=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrubbery("garden");
        std::cout << shrubbery << std::endl;
        
        midGrade.signForm(shrubbery);
        midGrade.executeForm(shrubbery);
        std::cout << std::endl;
        
        // Test RobotomyRequestForm (sign: 72, exec: 45)
        std::cout << "=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        midGrade.signForm(robotomy);
        midGrade.executeForm(robotomy);
        
        // Try multiple times to see randomness
        std::cout << "Multiple robotomy attempts:" << std::endl;
        for (int i = 0; i < 5; i++) {
            midGrade.executeForm(robotomy);
        }
        std::cout << std::endl;
        
        // Test PresidentialPardonForm (sign: 25, exec: 5)
        std::cout << "=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        // Low grade can't sign
        lowGrade.signForm(pardon);
        
        // Mid grade can sign but can't execute
        midGrade.signForm(pardon);
        midGrade.executeForm(pardon);
        
        // High grade can do everything
        highGrade.signForm(pardon);
        highGrade.executeForm(pardon);
        std::cout << std::endl;
        
        // Test execution without signing
        std::cout << "=== Testing Unsigned Form Execution ===" << std::endl;
        ShrubberyCreationForm unsigned_form("test");
        highGrade.executeForm(unsigned_form);
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    return 0;
}