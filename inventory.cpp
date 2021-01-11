#include "inventory.hpp"

Inventory::Inventory()
{
    for(int i=0;i<6;i++)
    {
        items[i];
        amount[i] = 0;
    }
}

void Inventory::Draw(sf::RenderWindow& window, Player player)
{
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Black);
    shape.setSize(sf::Vector2f(800.0f,600.f));
    sf::Vector2f pozycja = player.get_position();
    pozycja -= sf::Vector2f(400,300);
    shape.setPosition(pozycja);
    window.draw(shape);
}
