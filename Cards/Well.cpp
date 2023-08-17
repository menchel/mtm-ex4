#include "Card.h"
#include "../utilities.h"
#include "../Players/Ninja.h"
#include "../Players/Player.h"
#include "Well.h"
Well::Well():Card("Well")
{

}

void Well::applyEncounter(Player& player) const
{
    try
    {
        dynamic_cast<Ninja&>(player);//if a player is a Ninja, he won't be harmed
        printWellMessage(true);
    }
    catch(const std::exception& e)//bad cast
    {
        player.damage(WELL_DAMAGE);
        printWellMessage(false);
    }
    
}