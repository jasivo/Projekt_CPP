#include "terrain.hpp"

Tree::Tree(const int x, const int y)
: xpos(x), ypos(y), width(89), height(100), logs(3000)
{
    Tree::tree_texture.loadFromFile("trees.png");
    Tree::tree_shape.setSize(sf::Vector2f(89.0f,100.0f));
    Tree::tree_shape.setTexture(&tree_texture);
    Tree::get_texture_size(tree_texture,texture_size);
    Tree::tree_shape.setTextureRect(sf::IntRect(texture_size.x*1, 0, texture_size.x, texture_size.y));
    Tree::tree_shape.setPosition(sf::Vector2f(xpos,ypos));
}

Tree::~Tree()
{

}

void Tree::Draw(sf::RenderWindow& window)
{
    window.draw(tree_shape);
}

void Tree::get_texture_size(sf::Texture &texture, sf::Vector2u &vector)
{
    vector = texture.getSize();
    vector.x /= 2;
    vector.y /= 2;
}

void Tree::update_shape()
{
    if((logs <= 3000) && (logs > 2000))
        tree_shape.setTextureRect(sf::IntRect(texture_size.x*1, 0, texture_size.x, texture_size.y));
    else if((logs <= 2000) && (logs > 1000))
        tree_shape.setTextureRect(sf::IntRect(texture_size.x*0, 0, texture_size.x, texture_size.y));    
    else if((logs < 1000) && (logs > 0))
        tree_shape.setTextureRect(sf::IntRect(0, texture_size.y*1, texture_size.x, texture_size.y));
    else if(logs <= 0)
        tree_shape.setTextureRect(sf::IntRect(texture_size.x*1, (texture_size.y*1)+10, texture_size.x, texture_size.y-10));
}

sf::Vector2f Tree::get_center()
{
    return sf::Vector2f(xpos+(width/2),ypos+(height/2));
}

void Tree::update_logs(int i)
{
    if(logs > 0)
        logs -= i;
}