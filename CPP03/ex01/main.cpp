#include "ScavTrap.hpp"

int main() {
    std::cout << "\n-- Creating gaz the ScavTrap --" << std::endl;
    ScavTrap gaz("gaz");
    ScavTrap def;

    std::cout << "\n-- Attacking a target --" << std::endl;
    gaz.attack("TargetBot");

    std::cout << "\n-- Entering Gate Keeper Mode --" << std::endl;
    gaz.guardGate();

    std::cout << "\n-- Copying ScavTrap --" << std::endl;
    ScavTrap clone(gaz);
    clone.attack("CloneTarget");

    std::cout << "\n-- Assignment Operator --" << std::endl;
    ScavTrap assigned;
    assigned = gaz;
    assigned.guardGate();

    std::cout << "\n-- Draining Energy --" << std::endl;
    for (int i = 0; i < 51; ++i)
        gaz.attack("EnergyDrainBot");

    std::cout << "\n-- End of Test --" << std::endl;
    return 0;
}