#include "Zombie.hpp"

int main(){
    
    Zombie stack("main_stack_zombie");
    stack.announce();

    randomChump("stack_zombie");

    Zombie* heap= newZombie("heap_zombie");
    heap->announce();
    delete heap;

    return (0);
}