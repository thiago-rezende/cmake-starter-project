#pragma once
#include <iostream>
#include <string>

namespace Engine
{
    class Entity
    {
    public:
        Entity(std::string n_name, std::string n_info);
        ~Entity();
        inline unsigned int get_id() { return m_id; }
        inline std::string get_name() { return m_name; }
        inline std::string get_info() { return m_info; }
        void print_data();

    public:
        static unsigned int s_id_count;

    private:
        unsigned int m_id;
        std::string m_name;
        std::string m_info;
    };
} // Engine