#include "Span.hpp"

int main()
{
    {
        std::cout << "\n============Test: Subject Main============\n" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "\n============Test: Large Span============\n" << std::endl;
        Span sp = Span(100000);
        std::vector<int> vec;
        srand(time(NULL));
        for(int i = 0; i < 100000; i++){
            vec.push_back(rand());
        }
        sp.addNumbers(vec.begin(), vec.end());
        std::cout << "Span from vector container" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "\n============Test: Not Enough space in Span============\n" << std::endl;
        Span sp = Span(10000);
        std::vector<int> vec;
        srand(time(NULL));
        for(int i = 0; i < 100000; i++){
            vec.push_back(rand());
        }
        try{
            sp.addNumbers(vec.begin(), vec.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e){
            std::cerr<< "Error: " << e.what() << std::endl;
        }
    }
    std::cout << "\n============END OF TESTS============\n" << std::endl;
    return (0);
}