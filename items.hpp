#ifndef items_hpp
#define items_hpp

#include <iostream>
#include <SFML/Graphics.hpp>


class Item
{
    public:
        Item(int id);
        ~Item();
        void use(Player & player)
        {
            if(id==0)
                player.get_strenght() += add_strenght;
            if(id==1)
                player.get_maxhealth() += add_health;
            if(id==2)
                player.get_defence() += add_defense;
            if(id==3)
            {
                if(player.get_health() + heal > player.get_maxhealth())
                    player.get_health() = player.get_maxhealth();
                else
                    player.get_health() += heal;                
            }
        };
        void setItem(int ide);
        void drop();
        int get_id();
    private:
        int add_strenght;
        int add_health;
        int add_defense;
        int heal;
        std::string Name;
        std::string Description;
        // id -> 0 - sword, 1 - armor, 2 - shield, 3 - berries, 4 - logs, 5 - plank, 6 - iron, 7 - nail 
        int id;
        // type -> 0 - to equip, 1 - useable
        int type;
};

#endif