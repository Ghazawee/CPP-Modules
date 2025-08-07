#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    
    try{
        Intern intern;
        Bureaucrat bureaucrat("OG", 1); 
        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        if (form1) {
            std::cout << *form1 << std::endl;
            bureaucrat.signForm(*form1);
            bureaucrat.executeForm(*form1);
        }
        delete form1;
        AForm* form2 = intern.makeForm("shrubbery creation", "garden");
        if (form2) std::cout << *form2 << std::endl;
        delete form2;
        AForm* form3 = intern.makeForm("invalid form", "target");
        if (form3) std::cout << *form3 << std::endl;
    }catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}