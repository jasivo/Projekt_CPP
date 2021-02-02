#include "game.hpp"

Game::Game()
: task1(false),task2(false),task3(false)
{
    font.loadFromFile("Winter.ttf");
    text1.setFont(font);
    text1.setString("Build a boat");
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::Red);
    text1.setOutlineColor(sf::Color::Black);
    text1.setOutlineThickness(1);
    text1.setStyle(sf::Text::Bold);
    text2.setFont(font);
    text2.setString("Kill monsters (0/16)");
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Red);
    text2.setOutlineColor(sf::Color::Black);
    text2.setOutlineThickness(1);
    text2.setStyle(sf::Text::Bold);
    text3.setFont(font);
    text3.setString("Find a companion");
    text3.setCharacterSize(24);
    text3.setFillColor(sf::Color::Red);
    text3.setOutlineColor(sf::Color::Black);
    text3.setOutlineThickness(1);
    text3.setStyle(sf::Text::Bold);
    check[0] = 0;
    check[1] = 0;
    check[2] = 0;
}

bool Game::end_game()
{
    if((task1 == true)&&(task2 == true)&&(task3 == true))
        return true;
    else
        return false;
}

void Game::text_update(sf::View view, sf::RenderWindow& window)
{
    sf::Vector2f wektor = view.getCenter()+sf::Vector2f(9,-300);
    text1.setPosition(wektor+sf::Vector2f(150,68));
    std::string temp = std::to_string(update_task_counter());
    text2.setString("Kill monsters (" + temp + "/16)");
    text2.setPosition(wektor+sf::Vector2f(150,98));
    text3.setPosition(wektor+sf::Vector2f(150,128));
    if((task1 == true) && (check[0] == 0))
    {
        text1.setFillColor(sf::Color::Green);
        check[0] = 1;
    }
    if((task2 == true) && (check[1] == 0))
    {
        text2.setFillColor(sf::Color::Green);
        check[1] = 1;
    }
    if((task3 == true) && (check[2] == 0))
    {
        text3.setFillColor(sf::Color::Green);
        check[2] = 1;
    }
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
}

bool & Game::task3_status()
{
    return task3;
}

bool Game::task1_status()
{
    return task1;
}

bool Game::task2_status()
{
    return task2;
}

int & Game::update_task_counter()
{
    return task2_counter;
}

void Game::game_update(Inventory inv)
{
    if((inv.amount_status(5) > 0) && (task1 == false))
        task1 = true;
    if((task2_counter >= 16) && (task2 == false))
        task2 = true;
}

void Game::menu(sf::Font & font, int & menu_status, sf::RectangleShape & okno, sf::RectangleShape & game, sf::RectangleShape & rules, sf::RectangleShape & quit, sf::Text & title, sf::Text & txt1, sf::Text & txt2, sf::Text & txt3)
{
    if(menu_status == 0)
    {
        okno.setSize(sf::Vector2f(800.0f,600.0f));
        okno.setFillColor(sf::Color::White);
        game.setSize(sf::Vector2f(400.0f,100.0f));
        rules.setSize(sf::Vector2f(400.0f,100.0f));
        quit.setSize(sf::Vector2f(400.0f,100.0f));
        game.setFillColor(sf::Color::Black);
        rules.setFillColor(sf::Color::Black);
        quit.setFillColor(sf::Color::Black);
        game.setPosition(sf::Vector2f(200.0f,200.0f));
        rules.setPosition(sf::Vector2f(200.0f,325.0f));
        quit.setPosition(sf::Vector2f(200.0f,450.0f));
        txt1.setFont(font);
        txt2.setFont(font);
        txt3.setFont(font);
        title.setFont(font);
        txt1.setFillColor(sf::Color::White);
        txt2.setFillColor(sf::Color::White);
        txt3.setFillColor(sf::Color::White);
        title.setFillColor(sf::Color::Black);
        txt1.setPosition(sf::Vector2f(350.0f,225.0f));
        txt2.setPosition(sf::Vector2f(375.0f,350.0f));
        txt3.setPosition(sf::Vector2f(385.0f,475.0f));
        title.setPosition(sf::Vector2f(300.0f,50.0f));
        title.setCharacterSize(50);
        txt1.setString("New Game");
        txt2.setString("Rules");
        txt3.setString("Quit");
        title.setString("SURVIVORS");

        menu_status = 1;
    }
}

Game::~Game()
{

}