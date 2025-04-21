#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
    private:
       Contact contact[8];
       int total_contacts;
       int current_index;
    public:
        PhoneBook();
        void add_contact();
        void search_contact();
};


#endif