#include <easyfind.hpp>

int main(){
    {
        std::cout << "\n============Vector Container============\n" << std::endl;
        std::vector<int> vec;
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(20);
        vec.push_back(31);

        try{

            std::vector<int>::iterator ite =easyfind(vec, 5);
            std::cout <<"Found "<< *ite << std::endl;
        }catch(const std::exception&e){
            std::cerr<< "Error: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n============List Container============\n" << std::endl;
        std::list<int> lis;
        lis.push_back(14);
        lis.push_back(26);
        lis.push_back(15);
        lis.push_back(23);

        try{
            std::list<int>::iterator it = easyfind(lis, 23);
            std::cout << "Found " << *it << std::endl;
        }catch (const std::exception& e){
            std::cerr<< "Error: " << e.what() << std::endl;

        }
    }
    std::cout << "\n============END OF TESTS============\n" << std::endl;
} 