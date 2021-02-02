#include "items.hpp"

Item::Item(int id)
: id(id)
{
    Item::add_defense = 0;
    Item::add_health = 0;
    Item::add_strength = 0;
    Item::heal = 0;

    if((id==0) || (id==1) || (id==2))
        Item::type = 0;
    else
        Item::type = 1;

    switch(id)
    {
        case 0:
            Item::add_strength = 5;
            Item::Name = "Sword";
            Item::Description = "Icreases damage dealt";
            Item::item_texture.loadFromFile("images/sword.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 1:
            Item::add_health = 20;
            Item::Name = "Armor";
            Item::Description = "You can take more hits";
            Item::item_texture.loadFromFile("images/armor.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 2:
            Item::add_defense = 5;
            Item::Name = "Shield";
            Item::Description = "Reduces damage received";
            Item::item_texture.loadFromFile("images/shield.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 3:
            Item::heal = 10;
            Item::Name = "Berries";
            Item::Description = "It improves your condition";
            Item::item_texture.loadFromFile("images/berries.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 4:
            Item::Name = "Log";
            Item::Description = "Can be turned into planks";
            Item::item_texture.loadFromFile("images/log_eq.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 5:
            Item::Name = "Plank";
            Item::Description = "I can use it to build a boat";
            Item::item_texture.loadFromFile("images/plank.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 6:
            Item::Name = "Iron Ingot";
            Item::Description = "Can be turned into spikes";
            Item::item_texture.loadFromFile("images/ingot.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 7:
            Item::Name = "Spike";
            Item::Description = "I can use it to build a boat";
            Item::item_texture.loadFromFile("images/spike.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        case 8:
            Item::Name = "Boat";
            Item::Description = "Now I can escape from this island";
            Item::item_texture.loadFromFile("images/boat.png");
            Item::item_shape.setSize(sf::Vector2f(64.0f,64.0f));
            Item::item_shape.setTexture(&item_texture);
        break;
        default:
        break;
    }
}

void Item::draw_shape(sf::RenderWindow& window, sf::Vector2f pos)
{
    item_shape.setPosition(pos);
    window.draw(item_shape);
}

void Item::update_shape(sf::Vector2f wektor)
{
    item_shape.setPosition(wektor);
}

sf::RectangleShape & Item::get_item_shape()
{
    return item_shape;
}

Item::~Item()
{
    
}
