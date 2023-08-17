#include "Witch.h"
#include "BattleCard.h"
#include "../utilities.h"


Witch::Witch():BattleCard("Witch",Witch::DEFAULT_FORCE,Witch::DEFAULT_LOOT,Witch::DEFAULT_DAMAGE)//need to change to the consts
{

}

void Witch::activateLoss(Player& player) const
{
    player.forceDownGrade();
}

