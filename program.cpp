#include <ctime>
#include "player.cpp"
#include "animation.cpp"
#include "items.cpp"
#include "terrain.cpp"
#include "enemy.cpp"
#include <math.h>
#include "game.cpp"
#include "inventory.cpp"

sf::RectangleShape okno;
sf::RectangleShape new_game;
sf::RectangleShape rules;
sf::RectangleShape quit;
std::vector<Item*> items;
std::vector<Item*> items_EQ;
sf::Event event;
sf::RenderWindow window(sf::VideoMode(800, 600), "Survivors", sf::Style::Close);
float delta_v = 0.05;
Game menu;
sf::Font font;
Player gracz(150,150,0.3);
Player mate(3800,3800,0);
sf::Vector2f position;
std::vector<sf::Text> amount_texts;
std::vector<Tree*> drzewa;
std::vector<Terrain*> teren;
std::vector<Enemy*> wrogowie;
Inventory inventory;
//STATUS 0 -> game, 1 -> menu, 2 -> game over, 3 -> the end 
int status = 1;
int menu_status = 0;
int end_game_text = 0;

float radius(sf::Vector2f v1, sf::Vector2f v2)
{
    float x = pow((v2.x-v1.x),2);
    float y = pow((v2.y-v1.y),2);
    float radius = sqrt(x+y);
    return radius;
}

int main()
{   
    for(int i=0;i<=2;i++)
    {
        items_EQ.push_back(new Item(i));
    }
    for(int i=3;i<=8;i++)
    {
        items.push_back(new Item(i));
    }

    srand(time(NULL));
    font.loadFromFile("Winter.ttf");
    sf::Text title;
    sf::Text text1;

    for(int i=0;i<=5;i++)
    {
        amount_texts.push_back(text1);
        amount_texts[i].setFont(font);
        amount_texts[i].setFillColor(sf::Color::Black);
        amount_texts[i].setCharacterSize(25);
        amount_texts[i].setStyle(sf::Text::Bold);
    }

    for(int i=0;i<=9;i++)
    {
        if(i%2==0)
        {  
            drzewa.push_back(new Tree(200+(i*300),200));
            drzewa.push_back(new Tree(200+(i*265),1200));
            teren.push_back(new Terrain(50+(i*344),700,0));;
            teren.push_back(new Terrain(50+(i*211),3200,1));
            teren.push_back(new Terrain(50+(i*264),1500,1));
            teren.push_back(new Terrain(50+(i*382),2100,0));
            wrogowie.push_back(new Enemy(i*100,100+(i*355),0.1));
            wrogowie.push_back(new Enemy(i*200,200+(i*299),0.1));
        }
        else
        {
            drzewa.push_back(new Tree((i+1)*400,2300));
            drzewa.push_back(new Tree((i+1)*322,3600));
            teren.push_back(new Terrain(33+(i*222),400,0));;
            teren.push_back(new Terrain(44+(i*365),1900,1));
            teren.push_back(new Terrain(22+(i*278),2700,1));
            teren.push_back(new Terrain(77+(i*322),3800,0));
            wrogowie.push_back(new Enemy(i*300,100+(i*377),0.1));
            wrogowie.push_back(new Enemy(i*400,100+(i*399),0.1));
        }
    }

    sf::Text text2;
    sf::Text text3;
    sf::Texture texture;
    sf::Texture testtexture;
    texture.loadFromFile("images/trawa.png");
    sf::Sprite sprite(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 4000, 4000));

    float deltaTime = 0;
    sf::Clock clock;

    sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(800.0f,600.0f));

    while(window.isOpen())
    {
        
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
        if(status==0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                inventory.item_use(3,gracz);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                inventory.item_use(4,gracz);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                inventory.item_use(5,gracz);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                inventory.item_use(6,gracz);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                inventory.item_use(7,gracz);
            }

                deltaTime = clock.restart().asSeconds();



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

                for(int i=0;i<=19;i++)
                {
                    if(radius(gracz.get_center(), drzewa[i]->get_center()) <= 60)
                    {
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                            drzewa[i]->update_logs(1,gracz);   
                        // std::cout << "G " << gracz.get_center().x << gracz.get_center().y << std::endl;   
                        // std::cout << "D " << drzewa[i]->get_center().x << drzewa[i]->get_center().y << std::endl;       
                        // std::cout << radius(gracz.get_center(), drzewa[i]->get_center()) << std::endl;                
                    }
                }

                for(int i=0;i<=39;i++)
                {
                    if(radius(gracz.get_center(), teren[i]->get_center()) <= 40)
                    {
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                            teren[i]->update_material(1,gracz);                   
                    }
                }

                if((radius(gracz.get_center(), mate.get_center()) <= 200) && (menu.task3_status() == false))
                {
                    menu.task3_status() = true;
                }
                   

                window.setView(view);
                window.draw(sprite);

                for(int i=0;i<=19;i++)
                {
                    wrogowie[i]->Update(1,gracz,menu.update_task_counter());
                    wrogowie[i]->animation(wrogowie[i]->get_texture(), wrogowie[i]->get_face());
                    if(wrogowie[i]->get_health()<=0)
                        wrogowie[i]->Draw(window);
                    if(wrogowie[i]->get_health()>0)
                        wrogowie[i]->Draw(window);
                }

                mate.Draw(window);
                gracz.Draw(window);
                
                for(int i=0;i<=19;i++)
                {
                    drzewa[i]->update_shape(inventory);
                    drzewa[i]->Draw(window);
                }
                
                for(int i=0;i<=39;i++)
                {
                    teren[i]->update_shape(inventory);
                    teren[i]->Draw(window);
                }
                
                window.draw(gracz.get_state());
                gracz.Update_hp_info();
                window.draw(gracz.get_hp_info());
                
                for(int i=0;i<=19;i++)
                {
                    wrogowie[i]->Update_hp_info();
                    window.draw(wrogowie[i]->get_hp_info());
                }

                menu.game_update(inventory);
                menu.text_update(view,window);
                
                inventory.Draw(window,gracz,view);
                inventory.Draw_EQ(window,gracz,view);

                for(int i=0;i<=5;i++)
                {
                    if(inventory.amount_status(i)>0)
                    {
                        items[i]->draw_shape(window,(view.getCenter()+sf::Vector2f(9,-300)) + sf::Vector2f(((i*64)+((i+1)*1)),1));
                        amount_texts[i].setString(std::to_string(inventory.amount_status(i)));
                        amount_texts[i].setPosition((view.getCenter()+sf::Vector2f(9,-300))+sf::Vector2f(47+(i*65),37));
                        window.draw(amount_texts[i]);
                    }
                }

                if(gracz.item(0)==true)
                {
                    items_EQ[0]->draw_shape(window,(view.getCenter()-sf::Vector2f(400,300))+sf::Vector2f(1,1));
                }
                if(gracz.item(1)==true)
                {
                    items_EQ[1]->draw_shape(window,(view.getCenter()-sf::Vector2f(400,300))+sf::Vector2f(1,(1*64)+1));
                }
                if(gracz.item(2)==true)
                {
                    items_EQ[2]->draw_shape(window,(view.getCenter()-sf::Vector2f(400,300))+sf::Vector2f(1,(2*64)+1));
                }
                
                // if(menu.end_game())
                //     status = 3;

                if(menu.end_game())
                    status = 3;
                
                if(gracz.get_health() <= 0)
                    status = 2;

                window.display();

        }
                //window.clear();
        else if(status == 1)
        {
            if(menu_status == 0)
            {
                menu.menu(font, menu_status, okno, new_game, rules, quit, title, text1, text2 ,text3);
            }
            window.draw(okno);
            window.draw(new_game);
            window.draw(rules);
            window.draw(quit);
            window.draw(title);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.display();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
                status = 0;
        }

        else if(status == 2)
        {
            if(end_game_text == 0)
            {
                sf::Vector2f box_position = view.getCenter();
                box_position -= sf::Vector2f(400,300);
                okno.setPosition(box_position);
                text1.setFillColor(sf::Color::Black);
                text2.setFillColor(sf::Color::Black);
                text1.setCharacterSize(30);
                text2.setCharacterSize(30);
                text1.setString("Game Over");
                text1.setPosition(box_position+sf::Vector2f(350.0f,225.0f));
                text2.setPosition(box_position+sf::Vector2f(360.0f,300.0f));
                text2.setString("You died");
                end_game_text += 1;
            }
            window.draw(okno);
            window.draw(text1);
            window.draw(text2);
            window.display();
        }

        else if(status == 3)
        {
            
            if(end_game_text == 0)
            {
                sf::Vector2f box_position = view.getCenter();
                box_position -= sf::Vector2f(400,300);
                okno.setPosition(box_position);
                text1.setFillColor(sf::Color::Black);
                text2.setFillColor(sf::Color::Black);
                text1.setCharacterSize(30);
                text2.setCharacterSize(30);
                text1.setString("End Game");
                text1.setPosition(box_position+sf::Vector2f(350.0f,225.0f));
                text2.setPosition(box_position+sf::Vector2f(270.0f,320.0f));
                text2.setString("You escaped from the island");
                end_game_text += 1;
            }
            window.draw(okno);
            window.draw(text1);
            window.draw(text2);
            window.display();
        }    
    }
    
    return 0;
}
