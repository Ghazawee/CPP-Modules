#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void) other;
    return *this;
}

bool isChar(const std::string& str){
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool isInt(const std::string& str){
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
bool isFloat(const std::string& str){
    if (str == "nanf" || str == "inff" ||str == "+inff" || str == "-inff")
        return true;
    if (str.empty() || str[str.length() - 1] != 'f')
        return false;
    std::string trim = str.substr(0, str.length() -1);
    char* end;
    float value = std::strtof(trim.c_str(), &end);
    if (*end != '\0')
        return false;
    if (value < -FLT_MAX || value > FLT_MAX)
        return false;
    return true;
}
bool isDouble(const std::string& str){
    if (str == "nan" || str == "inf"||str == "+inf" || str == "-inf")
        return true;
    if (str.empty())
        return false;
    char *end;
    double value = std::strtod(str.c_str(), &end);
    if (*end != '\0')
        return false;
    if (value < -DBL_MAX || value > DBL_MAX)
        return false;
    return true;
}

void printChar(char c){
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void printInt(int value){
    std::cout << "int: " << value << std::endl;
}

void printFloat(float value){
    // std::cout << std::fixed << std::setprecision(1);
    //infinity and NaN handling
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    // else if (value == -std::numeric_limits<float>::infinity())
    //     std::cout << "float: -inff" << std::endl;
    else{
        std::cout << "float: " << value ;
        if (value == static_cast<int>(value))
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
}

void printDouble(double value){
    // std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    // else if (value == std::numeric_limits<double>::infinity())
    //     std::cout << "double: +inf" << std::endl;
    // else if (value == -std::numeric_limits<double>::infinity())
    //     std::cout << "double: -inf" << std::endl;
    else{
        std::cout << "double: " << value ;
        if (value == static_cast<int>(value))
            std::cout << ".0" << std::endl;
        else
            std::cout << std::endl;
    }
}

void printImposible(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void convertfromchar(char c){
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void convertfromint(int n){
    if (n >= 0 && n <= 127){
        if (isprint(n))
            printChar(static_cast<char>(n));
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    printInt(n);
    printFloat(static_cast<float>(n));
    printDouble(static_cast<double>(n));
}

void convertfromfloat(float f){
    if (f >= 0 && f <= 127){
        if (isprint(static_cast<int>(f)))
            printChar(static_cast<char>(f));
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    if (std::isnan(f) || std::isinf(f) || f < INT_MIN || f > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
    } else {
        printInt(static_cast<int>(f));
    }
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void convertfromdouble(double d){
    if (d >= 0 && d <= 127){
        if (isprint(static_cast<int>(d)))
            printChar(static_cast<char>(d));
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    if (std::isnan(d) || std::isinf(d) ||d < INT_MIN || d > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
    } else {
        printInt(static_cast<int>(d));
    }
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::convert(const std::string& literal){
    if (isChar(literal))
        convertfromchar(literal[0]);
    else if (isInt(literal)){
        int n = strtol(literal.c_str(), 0, 10);
        convertfromint(n);
    }
    else if (isFloat(literal)){
        convertfromfloat(std::strtof(literal.c_str(), 0));
    }
    else if (isDouble(literal))
        convertfromdouble(std::strtod(literal.c_str(), 0));
    else
        printImposible();
}


