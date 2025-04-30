#include "good.hpp"

std::string readfile(const std::string &filename){
    std::ifstream inputfile(filename.c_str());
    if (!inputfile){
        return "";
    }
    std::string content;
    std::string line;
    while (std::getline(inputfile, line)){
        content += line + "\n";
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

int writefile(const std::string &content, const std::string &filename){

    std::ofstream outputfile((filename + ".replace").c_str());
    if (!outputfile){
        std::cout << "Error: could not create out file" << std::endl;
        return 1;
    }
    outputfile << content;
    outputfile.close();
    return 0;
}