#ifndef terrain_hpp
#define terrain_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "inventory.hpp"

class Tree
{
public:
    Tree(int x, int y);
    ~Tree();
    void Draw(sf::RenderWindow& window);
    void get_texture_size(sf::Texture &texture, sf::Vector2u &vector);
    void update_shape(Inventory & inv);
    void update_logs(int i, Player & player);
    void setpos(int xpos, int ypos);
    float get_logs() {return logs;};
    sf::Vector2f get_center();

private:
    int xpos;
    int ypos;;
    int width;
    int height;
    int logs;
    sf::Vector2u texture_size;
    sf::Texture tree_texture;
    sf::RectangleShape tree_shape;
};

class Terrain
{
public:
    Terrain(int x, int y, int type);
    ~Terrain();
    void Draw(sf::RenderWindow& window);
    void setpos(int xpos, int ypos);
    void get_texture_size(sf::Texture &texture, sf::Vector2u &vector);
    void update_shape(Inventory & inv);
    void update_material(int i, Player & player);
    float get_material() {return material;};
    sf::Vector2f get_center();

private:
    // 0 -> ore, 1 -> berry
    int type;
    const int xpos;
    const int ypos;;
    int width;
    int height;
    int material;
    sf::Vector2u texture_size;
    sf::Texture terrain_texture;
    sf::RectangleShape terrain_shape;   
};

#endif