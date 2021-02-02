#ifndef game_hpp
#define game_hpp

#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
//#include "Inventory.hpp"

class Game
{
    public:
        Game();
        ~Game();
        bool & task3_status();
        bool task1_status();
        bool task2_status();
        void menu(sf::Font & font, int & menu_status, sf::RectangleShape & okno, sf::RectangleShape & game, sf::RectangleShape & rules, sf::RectangleShape & quit, sf::Text & title, sf::Text & txt1, sf::Text & txt2, sf::Text & txt3);
        void game_update(Inventory inv);
        void text_update(sf::View view, sf::RenderWindow& window);
        int & update_task_counter();
        bool end_game();
    private:
        sf::Font font;
        sf::Text text1;
        sf::Text text2;
        sf::Text text3;
        int check[3];
        bool task1;
        bool task2;
        int task2_counter;
        bool task3;
};

#endif