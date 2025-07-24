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
    //shouldnt use if else, use switch case instead

    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int g = 0;
    while(g < 3){
        if (forms[g] == formName){
            break;
        }
        g++;
    }
    try{
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
                throw UnknownFormException();
        }
    }catch (const UnknownFormException& e){
        std::cerr <<"Intern couldnt make form because: " <<e.what() << std::endl;
        return NULL;
    }
}
const char* Intern::UnknownFormException::what() const throw(){
    return "Unknown form type!";
}