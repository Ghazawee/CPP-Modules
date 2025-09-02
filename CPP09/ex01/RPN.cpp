#include "RPN.hpp"


RPN::RPN(){}
RPN::~RPN(){};
RPN::RPN(const RPN& other) : container(other.container){}
RPN& RPN::operator=(const RPN& other){
    if (this != &other){
        container = other.container;
    }
    return *this;
}

void RPN::push(int value){
    container.push(value);
}
void RPN::pop(){
    container.pop();
}
int RPN::top() const{
    return container.top();
}
bool RPN::isEmpty() const{
    return container.empty();
}
size_t RPN::size() const{
    return container.size();
}
void RPN::add(){
    if (container.size() < 2){
        throw std::runtime_error("Error: not enough values in the stack");
    }
    int a = container.top();
    container.pop();
    int b = container.top();
    container.pop();
    container.push(a + b);
}
void RPN::subtract(){
    if (container.size() < 2){
        throw std::runtime_error("Error: not enough values in the stack");
    }
    int a = container.top();
    container.pop();
    int b = container.top();
    container.pop();
    //should it be 
    container.push(b - a);
}
void RPN::multiply(){
    if (container.size() < 2){
        throw std::runtime_error("Error: not enough values in the stack");
    }
    int a = container.top();
    container.pop();
    int b = container.top();
    container.pop();
    container.push(a * b);
}
void RPN::divide(){
    if (container.size() < 2){
        throw std::runtime_error("Error: not enough values in the stack");
    }
    int a = container.top();
    container.pop();
    int b = container.top();
    container.pop();
    container.push(b / a);
}

bool RPN::isInt(const std::string& str){
    if (str.empty() || (str[0] != '-' && str[0] != '+' && !std::isdigit(str[0])))
        return false;
    char* end;
    long value = std::strtol(str.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    if (value < INT_MIN || value > INT_MAX)
        return false;
    return true;
}

void RPN::evaluate(const std::string& argument){
    std::istringstream iss(argument);
    std::string token;
    while (iss >> token){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            // try{
                if (token == "+")
                    add();
                else if (token == "-")
                    subtract();
                else if (token == "*")
                    multiply();
                else if (token == "/")
                    divide();
            // }catch(const std::exception& e){}
            }
            else{
                if (isInt(token)){ // or it can be else if (isInt(token)) else throw
                    int value;
                    std::stringstream ss(token);
                    ss >> value;
                    push(value);
                    std::cout << container.top() << std::endl;
                }
                else{
                    throw std::runtime_error("Error: invalid token " + token);
                }
            }
        }
    }