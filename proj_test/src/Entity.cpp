#include "Entity.h"

namespace Engine
{
unsigned int Entity::s_id_count = 0;

Entity::Entity(std::string n_name, std::string n_info)
{
    s_id_count += 1;
    m_id = s_id_count;
    m_name = n_name;
    m_info = n_info;
}

Entity::~Entity()
{
    std::cout << get_id() << " " << get_name() << " deleted." << std::endl;
}

void Entity::print_data()
{
    std::cout << "Entity ID: " << this->get_id() << std::endl;
    std::cout << "Entity Name: " << this->get_name() << std::endl;
    std::cout << "Entity Info: " << this->get_info() << std::endl;
}
} // namespace Engine
