#ifndef enemy_hpp
#define enemy_hpp

#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Enemy
{
    public:
        Enemy(float x, float y, float v);
        void Draw(sf::RenderWindow& window);
        void Update(float delta_time, Player & player);
        void get_texture_size(sf::Texture &texture, sf::Vector2u &vector);
        sf::Texture & get_texture();
        void animation(sf::Texture &texture, int &face);
        int & get_face();
        sf::Vector2f get_position(){return enemy_shape.getPosition();};
        sf::Vector2f get_center();
        int & get_health();
        int & settimer();
        time_t & t_a();
        time_t & t_d();

    private:
        float xpos;
        float ypos;
        const float height;
        const float width;
        time_t time_attack;
        time_t time_def;
        float velocity_x;
        float velocity_y;
        int face;
        int timer;
        sf::Texture enemy_texture;
        sf::RectangleShape enemy_shape;
        sf::Vector2u texture_size;
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
        int damage;
        int health;
};

#endif