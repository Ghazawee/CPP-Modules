#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Gaz");
    ClapTrap b("Bot");

    a.setAttackdamage(15);

    std::cout << "\n--- Basic Attack ---\n";
    a.attack("Bot");
    b.takeDamage(a.getAttackdamage());

    std::cout << "\n--- Gaz uses all energy ---\n";
    for (int i = 0; i < 10; ++i)
        a.attack("Bot");

    std::cout << "\n--- Gaz tries to attack with 0 EP ---\n";
    a.attack("Bot");

    std::cout << "\n--- Bot repairs ---\n";
    b.beRepaired(3);

    std::cout << "\n--- Bot takes fatal damage ---\n";
    b.takeDamage(15);

    std::cout << "\n--- Bot tries to act while dead ---\n";
    b.attack("Nobody");
    b.beRepaired(1);

    std::cout << "\n--- Copying Gaz to clone ---\n";
    ClapTrap clone(a);
    clone.attack("AnotherBot");

    std::cout << "\n--- Assigning clone to Bot ---\n";
    b = clone;
    b.attack("FinalTarget");

    return 0;
}