#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool isSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        Form();
        Form(const std::string& name, int signGrade, int executeGrade);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();

        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();

        };
        const std::string& getName() const;
        bool getIsSigned()const;
        int getSignGrade()const;
        int getExecuteGrade()const;
        void beSigned(const Bureaucrat& bur);


};
std::ostream& operator<<(std::ostream& out, const Form& form);
#endif