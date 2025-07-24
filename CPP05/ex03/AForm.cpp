#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), isSigned(false), _signGrade(150), _executeGrade(150){}
AForm::AForm(const std::string& name, int signGrade, int executeGrade) : _name(name), isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}
AForm::~AForm() {}
AForm::AForm(const AForm& other) : _name(other._name), isSigned(other.isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}
AForm& AForm::operator=(const AForm& other) {
    if (this != &other){
        this->isSigned = other.isSigned;
        // _name, _signGrade, and _executeGrade are const, so they cannot be assigned
    }
    return *this;
}
const std::string& AForm::getName() const{
    return _name;
}
bool AForm::getIsSigned()const{
    return isSigned;
}
int AForm::getSignGrade()const{
    return _signGrade;
}
int AForm::getExecuteGrade()const{
    return _executeGrade;
}
void AForm::beSigned(const Bureaucrat& bur){
    if (bur.getGrade() > _signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char*  AForm::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char*  AForm::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}

const char*  AForm::FormNotSignedException::what() const throw(){
    return "Form not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form){
    out << "Name of the AForm: " << form.getName() << "\n";
    out << "Is the AForm signed? " << (form.getIsSigned() ? "YES" : "NO") <<"\n";
    out << "Sign Grade: " << form.getSignGrade() << "\n";
    out << "Execute Grade: " << form.getExecuteGrade() << "\n"; //\n looks weird might change to endl later
    return out;
}

