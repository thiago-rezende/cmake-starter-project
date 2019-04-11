#include <iostream>
#include "Entity.h"

int main(int argc, char **argv)
{
    Engine::Entity *e = new Engine::Entity("Player", "This is the entity of a Player.");
    std::cout << "Hello from CMake!" << std::endl;
    e->print_data();
    delete (e);
    std::cin.get();
    return 0;
}
