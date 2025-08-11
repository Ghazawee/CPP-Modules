#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <cfloat>

class ScalarConverter{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(const std::string& literal);
};

#endif