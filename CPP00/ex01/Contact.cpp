#include "Contact.hpp"

bool Contact::isvalid_name(const std::string &name){
   
    //if name is "      Ahmed     " i return false or should i trim the string from the start and end??
    char c;
    int i = 0;
    while (name[i])
    {
        c = name[i];
        if (!std::isalpha(c))
            return false;
        i++;
        // std::alphanum
    }
    return true;
}

bool Contact::isvalid_phone_num(const std::string& phone_num){
    char c;
    int i = 0;
    if (phone_num[0] == '+')
        i++;
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
        if (!std::isalpha(c) && !std::isdigit(c))
            return false;
        i++;

    }
    return true;
}
//need to protect eof ctrl+d for cin and getline should i return or keep taking input until a good input is given
void Contact::set_contact(){
    std::cout << "Enter first name: ";
    // std::getline(std::cin, first_name);
    if (!std::getline(std::cin, first_name))
        {
            // if (std::cin.eof()){
            return ;
            // }
        }
    while(first_name.empty() || !isvalid_name(first_name)){
        std::cout << "Invalid entry. Enter first name: ";
        std::getline(std::cin, first_name);
        if (!std::cin) // or i can put the previous line in a if !std::getline(std::cin, first_name)// dont forget to add it for every cin getline
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
    //maybe only accept alphanum, cause unicode mess up the set.w
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickname))
        return ;
    while(nickname.empty() || !isvalid_char(nickname)){
        std::cout << "Invalid entry. Enter nickname: ";
        if (!std::getline(std::cin, nickname))
            return ;
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phone_num))
        return ;
    //maybe add a limit for how many numbers ?? 3-15 digits
    while(phone_num.empty() || !isvalid_phone_num(phone_num)){
        std::cout << "Invalid entry. Enter Phone number: ";
        if (!std::getline(std::cin, phone_num))
            return ;
    }
    std::cout << "Enter your darkest secret: ";
    if (!std::getline(std::cin, darkest_secret))
        return;
    while(darkest_secret.empty()){
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

    //can i use ternary i need to ask someone it makes life way easier
    // std::cout << std::setw(10) << index << "|";

    // std::cout << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|";
    // std::cout << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|";
    // std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|";
    // std::cout << std::endl;
}