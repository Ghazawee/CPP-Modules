#include "PhoneBook.hpp"

int main(){
    // (void)av;
    // if (ac > 1){
    //     std::cout << "Usage: ./phonebook" << std::endl;
    //     return 1;
    // }
    PhoneBook phonebook;
    std::string command;
    while(true){
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) // protect against eof prevent infinite loop
        {
            std::cout << std::endl;
            break;
        }
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
        if (std::cin.eof()){
            std::cout << std::endl;
            break;
        }
    }
    return (0);
}