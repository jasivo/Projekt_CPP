#ifndef items_hpp
#define items_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Item
{
    public:
        Item(int id);
        ~Item();

        sf::RectangleShape & get_item_shape();
        void update_shape(sf::Vector2f wektor);
        void draw_shape(sf::RenderWindow& window, sf::Vector2f pos);
    private:
        int add_strength;
        int add_health;
        int add_defense;
        int heal;
        std::string Name;
        std::string Description;
        // id -> 0 - sword, 1 - armor, 2 - shield, 3 - berries, 4 - logs, 5 - plank, 6 - iron, 7 - nail, 8 - boat
        int id;
        // type -> 0 - to equip, 1 - useable
        int type;
        sf::Texture item_texture;
        sf::RectangleShape item_shape;
        sf::Vector2u item_size;
};

#endif