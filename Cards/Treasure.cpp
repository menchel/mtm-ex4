#include "Treasure.h"
#include "Card.h"
#include "../utilities.h"
#include "../Players/Player.h"
Treasure::Treasure():Card("Treasure")
{

}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(COINS);
    printTreasureMessage();
}