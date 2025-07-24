#include "Form.hpp"

Form::Form() : _name("Default Form"), isSigned(false), _signGrade(150), _executeGrade(150){}
Form::Form(const std::string& name, int signGrade, int executeGrade) : _name(name), isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}
Form::~Form() {}
Form::Form(const Form& other) : _name(other._name), isSigned(other.isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}
Form& Form::operator=(const Form& other) {
    if (this != &other){
        this->isSigned = other.isSigned;
        // _name, _signGrade, and _executeGrade are const, so they cannot be assigned
    }
    return *this;
}
const std::string& Form::getName() const{
    return _name;
}
bool Form::getIsSigned()const{
    return isSigned;
}
int Form::getSignGrade()const{
    return _signGrade;
}
int Form::getExecuteGrade()const{
    return _executeGrade;
}
void Form::beSigned(const Bureaucrat& bur){
    if (bur.getGrade() > _signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char*  Form::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char*  Form::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form){
    out << "Name of the Form: " << form.getName() << "\n";
    out << "Is the Form signed? " << (form.getIsSigned() ? "YES" : "NO") <<"\n";
    out << "Sign Grade: " << form.getSignGrade() << "\n";
    out << "Execute Grade: " << form.getExecuteGrade() << "\n"; //\n looks weird might change to endl later
    return out;
}

