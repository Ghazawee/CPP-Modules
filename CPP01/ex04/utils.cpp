#include "good.hpp"

std::string readfile(const std::string &filename){
    std::ifstream inputfile(filename.c_str()); // c_str() converts std::string to const char * cause ifstream constructor takes const char * not string type
    if (!inputfile){
        std::cout << "Error: could not open file" << std::endl;
        // return "";
        exit(1);
    }
    std::string content;
    std::string line;
    while (std::getline(inputfile, line)){
        content += line + "\n"; // since getline removes the newline character, we add it back
    }
    inputfile.close();
    return content;
}

void replace(std::string &content, const std::string &s1, const std::string &s2){

    size_t pos = 0;
    while((pos = content.find(s1, pos)) != std::string::npos){
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

void writefile(const std::string &content, const std::string &filename){

    std::ofstream outputfile((filename + ".replace").c_str());
    if (!outputfile){
        std::cout << "Error: could not create file" << std::endl;
        exit(1);
    }
    outputfile << content;
    outputfile.close();
}