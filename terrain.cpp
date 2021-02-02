#include "terrain.hpp"

Tree::Tree(int x, int y)
: xpos(x), ypos(y), width(89), height(100), logs(3000)
{
    Tree::tree_texture.loadFromFile("images/trees.png");
    Tree::tree_shape.setSize(sf::Vector2f(89.0f,100.0f));
    Tree::tree_shape.setTexture(&tree_texture);
    Tree::get_texture_size(tree_texture,texture_size);
    Tree::tree_shape.setTextureRect(sf::IntRect(texture_size.x*1, 0, texture_size.x, texture_size.y));
    Tree::tree_shape.setPosition(sf::Vector2f(xpos,ypos));
}

Tree::~Tree()
{

}

void Tree::setpos(int x,int y)
{
    tree_shape.setPosition(x,y);
}

void Tree::Draw(sf::RenderWindow& window)
{
    window.draw(tree_shape);
}

void Tree::get_texture_size(sf::Texture &texture, sf::Vector2u &vector)
{
    vector = texture.getSize();
    vector.x /= 2;
    vector.y /= 2;
}

void Tree::update_shape(Inventory & inv)
{
    if((logs <= 3000) && (logs > 2000))
        tree_shape.setTextureRect(sf::IntRect(texture_size.x*1, 0, texture_size.x, texture_size.y));
    else if((logs <= 2000) && (logs > 1000))
        tree_shape.setTextureRect(sf::IntRect(texture_size.x*0, 0, texture_size.x, texture_size.y));    
    else if((logs < 1000) && (logs > 0))
        tree_shape.setTextureRect(sf::IntRect(0, texture_size.y*1, texture_size.x, texture_size.y));
    else if(logs <= 0)
        tree_shape.setTextureRect(sf::IntRect(texture_size.x*1, (texture_size.y*1)+10, texture_size.x, texture_size.y-10));

    if((logs==2000) || (logs==1000) || (logs==0))
    {
        inv.update_amount(1,1);
        logs--;
    }

}

sf::Vector2f Tree::get_center()
{
    return sf::Vector2f(xpos+(width/2),ypos+(height/2));
}

void Tree::update_logs(int i, Player & player)
{
    if(logs > 0)
    {
        logs -= i;
        //player.get_state().setPosition(player.get_position()-sf::Vector2f(20.0f,77.0f));
        player.get_state().setString("Cutting...");
    }
    else if(logs<=0)
    {
        player.get_state().setString("");
    }
}

Terrain::Terrain(int x, int y, int type)
: xpos(x), ypos(y), width(64), height(64), material(3000), type(type)
{
    if(type==0)
    {
        Terrain::terrain_texture.loadFromFile("images/iron_ore.png");
        Terrain::terrain_shape.setSize(sf::Vector2f(64.0f,64.0f));
        Terrain::terrain_shape.setTexture(&terrain_texture);
        Terrain::get_texture_size(terrain_texture,texture_size);
        Terrain::terrain_shape.setTextureRect(sf::IntRect(0, 0, 64, 64));
        Terrain::terrain_shape.setPosition(sf::Vector2f(xpos,ypos));
    }
    else if(type==1)
    {
        Terrain::terrain_texture.loadFromFile("images/berry.png");
        Terrain::terrain_shape.setSize(sf::Vector2f(64.0f,64.0f));
        Terrain::terrain_shape.setTexture(&terrain_texture);
        Terrain::get_texture_size(terrain_texture,texture_size);
        Terrain::terrain_shape.setTextureRect(sf::IntRect(0, 0, 64, 64));
        Terrain::terrain_shape.setPosition(sf::Vector2f(xpos,ypos));
    }
}

Terrain::~Terrain()
{

}

void Terrain::Draw(sf::RenderWindow& window)
{
    window.draw(terrain_shape);
}

void Terrain::get_texture_size(sf::Texture &texture, sf::Vector2u &vector)
{
    vector = texture.getSize();
    vector.x /= 2;
}

void Terrain::update_shape(Inventory & inv)
{
    if(material>0)
        terrain_shape.setTextureRect(sf::IntRect(0, 0, 64, 64));
    else if(material <= 0)
        terrain_shape.setTextureRect(sf::IntRect(texture_size.x, 0, 64, 64));

    if((material==2000) || (material==1000) || (material==0))
    {
        if(type==0)
            inv.update_amount(3,1);
        else if(type==1)
            inv.update_amount(0,1);
        material--;
    }

}

sf::Vector2f Terrain::get_center()
{
    return sf::Vector2f(xpos+(width/2),ypos+(height/2));
}

void Terrain::update_material(int i, Player & player)
{
    if(material > 0)
    {
        material -= i;
        //player.get_state().setPosition(player.get_position()-sf::Vector2f(20.0f,77.0f));
        if(type==0)
            player.get_state().setString("Mining...");
        else if(type==1)
            player.get_state().setString("Gathering...");
    }
    else if(material<=0)
    {
        player.get_state().setString("");
    }
}