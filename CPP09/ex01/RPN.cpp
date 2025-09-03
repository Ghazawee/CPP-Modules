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
long double RPN::top() const{
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
    long double rhs = container.top();
    container.pop();
    long double lhs = container.top();
    container.pop();
    container.push(lhs + rhs);
}
void RPN::subtract(){
    if (container.size() < 2){
        throw std::runtime_error("Error: not enough values in the stack");
    }
    long double rhs = container.top();
    container.pop();
    long double lhs = container.top();
    container.pop();
    container.push(lhs - rhs);
}
void RPN::multiply(){
    if (container.size() < 2){
        throw std::runtime_error("Error: not enough values in the stack");
    }
    long double rhs = container.top();
    container.pop();
    long double lhs = container.top();
    container.pop();
    container.push(lhs * rhs);
}
void RPN::divide(){
    if (container.size() < 2){
        throw std::runtime_error("Error: not enough values in the stack");
    }
    long double rhs = container.top();
    container.pop();
    long double lhs = container.top();
    container.pop();
    if (rhs  == 0){
        throw std::runtime_error("Error: division by zero");
    }
    container.push(lhs / rhs);
}

bool RPN::isInt(const std::string& str){
    if (str.empty() || !std::isdigit(str[0]))
        return false;
    char* end;
    int value = std::strtol(str.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    (void) value;
    // if (value < INT_MIN || value > INT_MAX)
    //     return false;
    return true;
}

bool isDouble(const std::string& str){
    // if (str == "nan" || str == "inf"||str == "+inf" || str == "-inf")
    //     return true;
    if (str.empty())
        return false;
    char *end;
    double value = std::strtod(str.c_str(), &end);
    if (*end != '\0')
        return false;
    (void) value;
    // if (value < -DBL_MAX || value > DBL_MAX)
    //     return false;
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
                // if(isDouble(token)){
                    long double value;
                    std::stringstream ss(token);
                    ss >> value;
                    if (value < 0 || value > 9)
                        throw std::runtime_error("Error: invalid token " + token);
                    // if (value > INT_MAX)

                    push(value);
                }
                else{
                    throw std::runtime_error("Error: invalid token " + token);
                }
            }
        }
    }