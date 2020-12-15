#ifndef items_hpp
#define items_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Item
{
public:
    Item(const int str, const int hea, const int def, const int heal);
    ~Item();
    void change_equip(bool state_to_make);
    bool is_equiped();
    //void add_statistic(Player* player);

private:
    const int add_strenght;
    const int add_health;
    const int add_defense;
    const int heal;
    int type;
    bool equiped;
};

#endif