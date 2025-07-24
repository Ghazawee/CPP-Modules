#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
//add more tests later
int main() {
    

    try{
        Intern intern;
        Bureaucrat bureaucrat("OG", 1); // Highest grade
        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        AForm* form2 = intern.makeForm("shrubbery creation", "garden");
        AForm* form3 = intern.makeForm("invalid form", "target");
        if (form1) {
            std::cout << *form1 << std::endl;
            bureaucrat.signForm(*form1);
            bureaucrat.executeForm(*form1);
        }
        if (form2) std::cout << *form2 << std::endl;
        if (form3) std::cout << *form3 << std::endl;
        delete form1;
        delete form2;
    }catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // form3 is nullptr, safe to not delete

    
    return 0;
}