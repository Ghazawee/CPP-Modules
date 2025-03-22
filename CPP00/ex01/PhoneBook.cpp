#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : total_contacts(0), current_index(0){};

void PhoneBook::add_contact(){
    contact[current_index].set_contact();
    current_index = (current_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
}

void PhoneBook::search_contact(){
    if (total_contacts == 0){
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
            << std::setw(10) << "First Name" << "|"
            << std::setw(10) << "Last Name" << "|"
            << std::setw(10) << "Nickname" << "|" << std::endl;

    int i = 0;
    while (i < total_contacts){
        contact[i].display_contact_list(i);
        i++;
    }
    std::cout << "Enter index of contact to view: ";
    int index;
    std::cin >> index;
    std::cin.ignore();
    if(!std::cin)
        return;
    if (index >= 0 && index < total_contacts){
        contact[index].display_contact();
    }
    else{
        std::cout << "Invalid index." << std::endl;
    }
}