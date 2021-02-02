#include "inventory.hpp"

Inventory::Inventory()
{
    for(int i=0;i<=5;i++)
    {
        amount[i]=0;
    }
    shape_big.setFillColor(sf::Color::Black);
    shape_big.setSize(sf::Vector2f(691.0f,66.f));
    shape_small.setFillColor(sf::Color::Blue);
    shape_small.setSize(sf::Vector2f(64.0f,64.f));
    shape_big_EQ.setFillColor(sf::Color::Black);
    shape_big_EQ.setSize(sf::Vector2f(66.0f,196.f));
    shape_small_EQ.setFillColor(sf::Color::Blue);
    shape_small_EQ.setSize(sf::Vector2f(64.0f,64.f));
    refresh_time = time(NULL);
}

void Inventory::Draw(sf::RenderWindow& window, Player player, sf::View view)
{
    sf::Vector2f pozycja = view.getCenter();
    sf::Vector2f big_shape_pos = pozycja+sf::Vector2f(9,-300);
    shape_big.setPosition(big_shape_pos);
    window.draw(shape_big);
    for(int i=0;i<=5;i++)
    {
        shape_small.setPosition(big_shape_pos+sf::Vector2f(((i*64)+((i+1)*1)),1));
        window.draw(shape_small);
    }
}

void Inventory::Draw_EQ(sf::RenderWindow& window, Player player, sf::View view)
{
    sf::Vector2f pozycja = view.getCenter();
    sf::Vector2f big_shape_pos = pozycja-sf::Vector2f(400,300);
    shape_big_EQ.setPosition(big_shape_pos);
    window.draw(shape_big_EQ);
    for(int i=0;i<=2;i++)
    {
        shape_small_EQ.setPosition(big_shape_pos+sf::Vector2f(1,(i*64)+((i+1)*1)));
        window.draw(shape_small_EQ);
    }
}

void Inventory::update_amount(int pos, int i)
{
    amount[pos] += i;
}

//POSITION 0 - berries, 1 - logs, 2 - plank, 3 - iron, 4 - nail, 5 - boat

void Inventory::item_use(int id, Player & player)
{
    if(time(NULL)-refresh_time>=1)
    {
        switch(id)
        {
            case 3:
                if(player.get_health() > 0)
                {
                    if(amount_status(0) > 0)
                    {
                        if(player.get_health() < player.get_maxhealth())
                        {
                            if(player.get_health() + 10 >= player.get_maxhealth())
                            {
                                player.get_health() = player.get_maxhealth();
                            }
                            else
                            {
                                player.get_health() += 10;
                            }
                            
                        }
                        update_amount(0,-1);
                    }
                }
            break;
            case 4:
                if(amount_status(1) > 0)
                {
                    update_amount(2,1);
                    update_amount(1,-1);
                }
            break;
            case 5:
                if((amount_status(2) >= 5) && (amount_status(4) >= 3))
                {
                    update_amount(2,-5);
                    update_amount(4,-3); 
                    update_amount(5,1);   
                }
            break;
            case 6:
                if(amount_status(3) > 0)
                {
                    update_amount(4,1);
                    update_amount(3,-1);
                }
            break;
            case 7:
                if((amount_status(2) >= 5) && (amount_status(4) >= 3))
                {
                    update_amount(2,-5);
                    update_amount(4,-3); 
                    update_amount(5,1);   
                }
            break;
            default:
            break;
        }
        refresh_time = time(NULL);
    }
}

Inventory::~Inventory()
{

}
