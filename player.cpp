#include "player.hpp"

Player::Player(float x, float y, float v)
: xpos(x),ypos(y),velocity(v),height(80),width(50),strenght(0),health(40),defense(0)
{
    std::cout << "Utworzono gracza o pozycji " << x << " " << y << " i wymiarach " << height << " " << width << " i predkosci " << velocity << std::endl;
    Player::player_texture.loadFromFile("player.png");
    Player::player_shape.setSize(sf::Vector2f(50.0f,80.0f));
    Player::player_shape.setTexture(&player_texture);
    Player::get_texture_size(player_texture, texture_size);
    Player::player_shape.setTextureRect(sf::IntRect(texture_size.x*1, (texture_size.y*2)+20, texture_size.x, texture_size.y-20));
    Player::player_shape.setPosition(sf::Vector2f(xpos,ypos));
    Player::player_shape.setOrigin(Player::player_shape.getSize()/2.0f);
    Player::imageCount = sf::Vector2u(2,3);
    Player::face = 4;
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(player_shape);
}

sf::Texture & Player::get_texture()
{
    return player_texture;
}

int & Player::get_face()
{
    return face;
}

void Player::get_texture_size(sf::Texture &texture, sf::Vector2u &vector)
{
    vector = texture.getSize();
    vector.x /= 3;
    vector.y /= 4;
}

void Player::animation(sf::Texture &texture, int &face, float deltaTime, float switchTime)
{
    totalTime += deltaTime;

    if(totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if(currentImage.x > imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    switch(face)
    {
        case 0:
            Player::player_shape.setTextureRect(sf::IntRect(texture_size.x*currentImage.x, (texture_size.y*0)+20, texture_size.x, texture_size.y-20));
            break;
        case 1:
            Player::player_shape.setTextureRect(sf::IntRect(texture_size.x*currentImage.x, (texture_size.y*1)+20, texture_size.x, texture_size.y-20));
            break;
        case 2:
            Player::player_shape.setTextureRect(sf::IntRect(texture_size.x*currentImage.x, (texture_size.y*2)+20, texture_size.x, texture_size.y-20));
            break;
        case 3:
            Player::player_shape.setTextureRect(sf::IntRect(texture_size.x*currentImage.x, (texture_size.y*3)+20, texture_size.x, texture_size.y-20));
            break;
        case 4:
            Player::player_shape.setTextureRect(sf::IntRect(texture_size.x*1, (texture_size.y*2)+20, texture_size.x, texture_size.y-20));
            break;
    }
}

void Player::Update(float delta_time)
{
    if(ypos-(velocity*delta_time)>=0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            ypos -= velocity*delta_time;     
                face = 0;   
        }
    }
    if((ypos+height)+(velocity*delta_time)<=4000)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            ypos += velocity*delta_time;
                face = 2;         
        }
    }
    if(xpos-(velocity*delta_time)>=0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            xpos -= velocity*delta_time;
                face = 3;         
        }
    }
    if((xpos+width)+(velocity*delta_time)<=4000)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            xpos += velocity*delta_time;
                face = 1;         
        }
    }

    if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) &&  !(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&  !(sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
    {
        face = 4;
    }
    
    player_shape.setPosition(xpos,ypos);
}

sf::Vector2f Player::get_center()
{
    return sf::Vector2f(xpos+(width/2),ypos+(height/2));
}

int & Player::get_strenght()
{
    return strenght;
}

int & Player::get_defence()
{
    return defense;
}

int & Player::get_maxhealth()
{
    return max_health;
}

int & Player::get_health()
{
    return health;
}