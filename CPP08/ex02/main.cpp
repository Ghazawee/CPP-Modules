#include "MutantStack.hpp"
int main()
{
    {
        std::cout << "\n============Test: Subject Main============\n" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        const MutantStack<int> constmstack(mstack);
        MutantStack<int>::const_iterator it = constmstack.begin();
        MutantStack<int>::const_iterator ite = constmstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    {
        std::cout << "\n============Test: Compare with list container============\n" << std::endl;

        std::list<int> mstack;
        mstack.push_back(5);

        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
        std::cout << "\n============END OF TESTS============\n" << std::endl;

return 0;
}
