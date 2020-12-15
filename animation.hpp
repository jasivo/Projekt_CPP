#ifndef animation_hpp
#define animation_hpp

#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        ~Animation();

        void Update(int row, float deltaTime, int face);
        
        sf::IntRect uvRect;

    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
};

#endif