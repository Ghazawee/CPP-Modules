#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), _target("Default") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}
PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) , _target(other._target){}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other){
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const& executor) const{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}