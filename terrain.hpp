#ifndef terrain_hpp
#define terrain_hpp

#include <iostream>
#include <SFML/Graphics.hpp>

class Tree
{
public:
    Tree(const int x, const int y);
    ~Tree();
    void Draw(sf::RenderWindow& window);
    void get_texture_size(sf::Texture &texture, sf::Vector2u &vector);
    void update_shape();
    void update_logs(int i);
    float get_logs() {return logs;};
    sf::Vector2f get_center();

private:
    const int xpos;
    const int ypos;;
    int width;
    int height;
    int logs;
    sf::Vector2u texture_size;
    sf::Texture tree_texture;
    sf::RectangleShape tree_shape;
};

#endif