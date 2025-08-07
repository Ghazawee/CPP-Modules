#include "Intern.hpp"

Intern::Intern(){

}
Intern::~Intern(){

}
Intern::Intern(const Intern& other){
    (void)other;
}
Intern& Intern::operator=(const Intern& other){
    (void)other;
    return *this;
}
AForm* Intern::makeForm(const std::string& formName, const std::string& target){

    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int g = 0;
    while(g < 3){
        if (forms[g] == formName){
            break;
        }
        g++;
    }
        switch(g){
            case 0:
                std::cout << "Intern creates " << formName << std::endl;
                return new ShrubberyCreationForm(target);
            case 1:
                std::cout << "Intern creates " << formName << std::endl;
                return new RobotomyRequestForm(target);
            case 2:
                std::cout << "Intern creates " << formName << std::endl;
                return new PresidentialPardonForm(target);
            default:
                std::cerr <<"Intern couldnt create form ";
                throw UnknownFormException();
        }
}
const char* Intern::UnknownFormException::what() const throw(){
    return "Unknown form type!";
}