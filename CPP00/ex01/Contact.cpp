#include "Contact.hpp"

Contact::Contact(){};

bool Contact::isvalid_name(const std::string &name){
   
    char c;
    int i = 0;
    while (name[i])
    {
        c = name[i];
        if (!std::isalpha(c))
            return false;
        i++;
    }
    return true;
}

bool Contact::isvalid_phone_num(const std::string& phone_num){
    char c;
    int i = 0;
    if (phone_num[0] == '+'){
        if (phone_num[1] == '\0')
            return false;
        i++;
    }
    while(phone_num[i]){
        c = phone_num[i];
        if(!std::isdigit(c))
            return false;
        i++;
    }
    return true;
}

bool Contact::isvalid_char(const std::string &nick_name){
    char c;
    int i = 0;
    while(nick_name[i]){
        c = nick_name[i];
        if (!std::isalpha(c) && !std::isdigit(c) && c != ' ')
            return false;
        i++;

    }
    return true;
}

bool Contact::ispace_only(const std::string &str){
    int i =0;
    while(str[i]){
        if(str[i] != ' '){
            return true;
        }
        i++;
    }
    return false;

}

void Contact::set_contact(){
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, first_name))
        {
            return ;
        }
    while(first_name.empty() || !isvalid_name(first_name)){
        std::cout << "Invalid entry. Enter first name: ";
        std::getline(std::cin, first_name);
        if (!std::cin)
            return;
    }
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, last_name))
        return ;
    while(last_name.empty() || !isvalid_name(last_name)){
        std::cout << "Invalid entry. Enter last name: ";
        if (!std::getline(std::cin, last_name))
            return ;
    }
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickname))
        return ;
    while(nickname.empty() ||!isvalid_char(nickname) || !ispace_only(nickname)){
        std::cout << "Invalid entry. Enter nickname: ";
        if (!std::getline(std::cin, nickname))
            return ;
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phone_num))
        return ;
    while(phone_num.empty() || !isvalid_phone_num(phone_num)){
        std::cout << "Invalid entry. Enter Phone number: ";
        if (!std::getline(std::cin, phone_num))
            return ;
    }
    std::cout << "Enter your darkest secret: ";
    if (!std::getline(std::cin, darkest_secret))
        return;
    while(darkest_secret.empty() || !isvalid_char(darkest_secret) || !ispace_only(darkest_secret)){
        std::cout << "Invalid entry. Enter your darkest secret: ";
        if (!std::getline(std::cin, darkest_secret))
            return;
    }
}

void Contact::display_contact(){
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_num << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

void Contact::display_contact_list(int index){
    std::cout << std::setw(10) << index << "|";
    std::string tmp = first_name;
    if (first_name.length() > 10)
        tmp = first_name.substr(0, 9) + '.';
    std::cout << std::setw(10) << tmp << "|";
    tmp = last_name;
    if (last_name.length() > 10)
        tmp = last_name.substr(0, 9) + '.';
    std::cout << std::setw(10) << tmp << "|";
    tmp = nickname;
    if (nickname.length() > 10)
        tmp = nickname.substr(0, 9) + '.';
    std::cout << std::setw(10) << tmp << "|";
    std::cout << std::endl;
}