#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
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
        void setGrade(int grade); // maybe remove this later, not needed for now
        void signForm(Form& form) const;

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);
#endif