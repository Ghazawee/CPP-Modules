#include "FragTrap.hpp"

int main() {
    std::cout << "\n-- Creating fraggy --\n";
    FragTrap fraggy("fraggy");

    std::cout << "\n-- Testing attack --\n";
    fraggy.attack("EvilBot");

    std::cout << "\n-- Testing high five --\n";
    fraggy.highFivesGuys();

    std::cout << "\n-- Copying fraggy --\n";
    FragTrap copy(fraggy);
    copy.attack("CloneBot");

    std::cout << "\n-- Assigning fraggy --\n";
    FragTrap assigned;
    assigned = fraggy;
    assigned.highFivesGuys();

    std::cout << "\n-- Energy drain --\n";
    for (int i = 0; i < 101; ++i)
        fraggy.attack("DrainBot");
    fraggy.takeDamage(50);
    fraggy.takeDamage(50);
    fraggy.takeDamage(50);
    std::cout << "\n-- End of test --\n";
    return 0;
}