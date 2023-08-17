#include "Card.h"
#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Healer.h"
#include "Mana.h"
Mana::Mana():Card("Mana")
{

}

void Mana::applyEncounter(Player& player) const
{
    try
    {
        dynamic_cast<Healer&>(player);//if player is a healer he can use the Mana
        player.heal(HEAL_POINTS);
        printManaMessage(true);
    }
    catch(const std::exception& e)//bad cast
    {
        printManaMessage(false);
    }
    
}