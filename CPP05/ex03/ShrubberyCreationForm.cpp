#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), _target("Default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) , _target(other._target){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other){
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
    if(!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open file for writing");
    file << "         _-_-_\n";
    file << "      /~~   ~~\\\n";
    file << "   /~~         ~~\\\n";
    file << "  /~~           ~~\\\n";
    file << " /~~             ~~\\\n";
    file << " /~~             ~~\\\n";
    file << "  /~~           ~~\\\n";
    file << "   \\~~         ~~/\n";
    file << "      \\__-__/\n";
    file << "         | |\n";
    file << "         | |\n";
    file << "         | |\n";
    file << "         | |\n";
    file << "         | |\n";
    file << "         | |\n";
    file << "         | |\n";
    file << "         | |\n" ;
    file << "--------------------------\n";
    file << "You are like a tree, you grow and change with time";
    file << "and you provide shade and beauty to those around you.\n";
    file << "But even the mightiest tree can be cut down, so cherish your roots and branches.\n";
    file << "So remember, like a tree, you are strong and resilient.\n";
    file << "You can weather any storm and stand tall in the face of adversity.\n";
    file << "But also like a tree, you need to be nurtured and cared for.\n";
    file << "So take care of yourself and those around you, and you will continue to grow and thrive.\n";
    file << "--------------------------\n";
    file.close();
    std::cout << "Shrubbery created at " << _target << "_shrubbery" << std::endl;

}  