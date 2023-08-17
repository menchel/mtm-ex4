#include "Card.h"
#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Warrior.h"
#include "Barfight.h"
Barfight::Barfight():Card("Barfight")
{

}

void Barfight::applyEncounter(Player& player) const
{
    try
    {
        dynamic_cast<Warrior&>(player);//if player is warrior he won't get damage
        printBarfightMessage(true);
    }
    catch(const std::exception& e)//bad cast
    {
        player.damage(DAMAGE_FIGHT);
        printBarfightMessage(false);
    }
    
}