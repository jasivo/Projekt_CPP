#include "items.hpp"

Item::Item(const int str, const int hea, const int def, const int heal)
: add_strenght(str), add_health(hea), add_defense(def), heal(heal), equiped(false)
{
}

void Item::change_equip(bool state_to_make)
{
    equiped = state_to_make;
}

bool Item::is_equiped()
{
    return equiped;
}

