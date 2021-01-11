#include "items.hpp"

Item::Item(int id=8)
: id(id)
{
    add_defense = 0;
    add_health = 0;
    add_strenght = 0;
    heal = 0;

    if((id==0) || (id==1) || (id==2))
        type = 0;
    else
        type = 1;

    switch(id)
    {
        case 0:
            add_strenght = 5;
            Name = "Sword";
            Description = "Icreases damage dealt";
        break;
        case 1:
            add_health = 20;
            Name = "Armor";
            Description = "You can take more hits";
        break;
        case 2:
            add_defense = 5;
            Name = "Shield";
            Description = "Reduces damage received";
        break;
        case 3:
            heal = 10;
            Name = "Berries";
            Description = "It improves your condition";
        break;
        case 4:
            Name = "Log";
            Description = "Can be turned into planks";
        break;
        case 5:
            Name = "Plank";
            Description = "I can use it to build a boat";
        break;
        case 6:
            Name = "Log";
            Description = "Can be turned into nails";
        break;
        case 7:
            Name = "Nail";
            Description = "I can use it to build a boat";
        break;
        case 8:
            Name = "Nothing";
            Description = "Free place in your inventory";
        default:
        break;
    }
}

int Item::get_id()
{
    return id;
}