#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45), _target("Default"){}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) , _target(other._target){}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other){
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const& executor) const{
    static bool seed = false;
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    std::cout << "some drilling noises..." << std::endl;
    if (!seed){
        srand(time(0));
        seed = true;
    }
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << _target << "!" << std::endl;
    }
}