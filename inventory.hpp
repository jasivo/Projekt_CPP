#ifndef inventory_hpp
#define inventory_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "items.hpp"

class Inventory
{
    public:
        Inventory();
        void Draw(sf::RenderWindow& window, Player player);
        void Update(float delta_time);
        // void ser(){
        //     items[0] = new Item(8);
        // }
    private:
        Item items[6];
        int amount[6];
};

#endif