#include "player.cpp"
#include "animation.cpp"
#include "items.cpp"
#include "terrain.cpp"
#include <math.h>

sf::Event event;
sf::RenderWindow window(sf::VideoMode(800, 600), "Miner's Quest", sf::Style::Close);
float delta_v = 0.05;
Player gracz(400,300,0.3);
Tree drzewo(200,200);
sf::Vector2f position;

float radius(sf::Vector2f v1, sf::Vector2f v2)
{
    float x = pow((v2.x-v1.x),2);
    float y = pow((v2.y-v1.y),2);
    float radius = sqrt(x+y);
    return radius;
}

int main()
{   

    sf::Texture texture;
    texture.loadFromFile("trawa.png");
    sf::Sprite sprite(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 4000, 4000));

    float deltaTime = 0;
    sf::Clock clock;

    sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(800.0f,600.0f));

    while(window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        gracz.Update(1);
        gracz.animation(gracz.get_texture(), gracz.get_face(), deltaTime, 0.2f);
        position = gracz.get_position();


        if((position.x-400>0) && (position.y-300>0) && (position.x+400<4000) && (position.y+300<4000))
            position = position;
        else if((position.x-400<=0) && (position.y-300<=0))
        {
            position.x = 400;
            position.y = 300;
        }
        else if((position.x-400<=0) && (position.y+300>=4000))
        {
            position.x = 400;
            position.y = 3700;
        }
        else if((position.x+400>=4000) && (position.y-300<=0))
        {
            position.x = 3600;
            position.y = 300;
        }
        else if((position.x+400>=4000) && (position.y+300>=4000))
        {
            position.x = 3600;
            position.y = 3700;
        }
        else if(position.x-400<=0)
            position.x = 400;
        else if(position.y-300<=0)
            position.y = 300;
        else if(position.x+400>=4000)
            position.x = 3600;
        else if(position.y+300>=4000)
            position.y = 3700;

        view.setCenter(position);

        if(radius(gracz.get_center(), drzewo.get_center()) <= 150)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                drzewo.update_logs(-0.0005f);
            
        }
             
        drzewo.update_logs(0.00001f);

        window.setView(view);
        window.draw(sprite);
        gracz.Draw(window);
        drzewo.update_shape();
        drzewo.Draw(window);
        window.display();
        std::cout << drzewo.get_logs() << std::endl;
    }

    return 0;
}
