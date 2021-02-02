#ifndef inventory_hpp
#define inventory_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "items.hpp"
#include <vector>
#include "player.hpp"

class Inventory
{
    public:
        Inventory();
        ~Inventory();
        void Draw(sf::RenderWindow& window, Player player,sf::View view);
        void Draw_EQ(sf::RenderWindow& window, Player player,sf::View view);
        //POSITION 0 - berries, 1 - logs, 2 - plank, 3 - iron, 4 - nail, 5 - boat 
        int & amount_status(int position)
        {return amount[position];}
        void update_amount(int pos, int i);
        void item_use(int id, Player & player);
    private:
        int amount[6];
        sf::RectangleShape shape_big;
        sf::RectangleShape shape_small;
        sf::RectangleShape shape_big_EQ;
        sf::RectangleShape shape_small_EQ;
        time_t refresh_time;
};

#endif