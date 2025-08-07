#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other){
        this->_grade = other._grade;
    }
    return *this;
}
const std::string& Bureaucrat::getName()const{
    return _name;
}
int Bureaucrat::getGrade()const{
    return _grade;
}
void Bureaucrat::incrementGrade(){
    if(_grade <= 1){
        throw GradeTooHighException();
    }
    _grade--;
}
void Bureaucrat::decrementGrade(){
        if(_grade >= 150){
        throw GradeTooLowException();
    }
    _grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur){
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
    return out;
}

const char*  Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char*  Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}