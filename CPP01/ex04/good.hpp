#ifndef GOOD_HPP
#define GOOD_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string readfile(const std::string &filename);
void replace(std::string &content, const std::string &s1, const std::string &s2);
void writefile(const std::string &content, const std::string &filename);

#endif