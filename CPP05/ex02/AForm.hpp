#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool isSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        AForm();
        AForm(const std::string& name, int signGrade, int executeGrade);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();

        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();

        };
        class FormNotSignedException : public std::exception{
            public:
                const char* what() const throw();
        };
        const std::string& getName() const;
        bool getIsSigned()const;
        int getSignGrade()const;
        int getExecuteGrade()const;
        void beSigned(const Bureaucrat& bur);
        virtual void execute(Bureaucrat const& executor) const = 0;


};
std::ostream& operator<<(std::ostream& out, const AForm& form);
#endif