#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string> //is this needed
#include <iomanip>

class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_num;
        std::string darkest_secret;
    
    public:
        void set_contact();
        void display_contact();
        void display_contact_list(int index);
        bool isvalid_name(const std::string &name);
        bool isvalid_phone_num(const std::string &phone_num);
        bool isvalid_char(const std::string &nick_name);

};
#endif