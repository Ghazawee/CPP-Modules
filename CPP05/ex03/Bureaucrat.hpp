#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        const std::string& getName()const;
        int getGrade()const;
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();

        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();

        };
        void signForm(AForm& form) const;
        void executeForm(const AForm& form) const;

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);
#endif