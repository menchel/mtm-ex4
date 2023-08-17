#include "Merchant.h"
#include "../Players/Player.h"
#include "Card.h"
#include "../utilities.h"
#include <ostream>
#include <iostream>
Merchant::Merchant():Card("Merchant")
{

}

void Merchant::applyEncounter(Player& player) const
{
    std::string inputFromUser;
    int choise;
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    while(true)
    {
        try
        {
            std::getline(std::cin,inputFromUser);//get user input
            choise=std::stoi(inputFromUser);
            if(buyProduct(std::cout,player,choise))//trying to buy
            {
                return;
            }
            else
            {
                printInvalidInput();
            }
        }
        catch(const std::exception& e)
        {
            printInvalidInput();
        }
    }
}

bool Merchant::buyProduct(std::ostream& os,Player& player,int type) const
{
    switch(type)
    {
        case(BUY_NOTHING):
        {
            printMerchantSummary(os,player.getName(),BUY_NOTHING,0);
        } break;
        case(BUY_HEALTH):
        {
            tryToBuy(os,player,BUY_HEALTH,HEALTH_PRICE);
        } break;
        case(BUY_FORCE):
        {
            tryToBuy(os,player,BUY_FORCE,FORCE_PRICE);
        } break;
        default:
        {
            return false;
        }
    }
    return true;
}
void Merchant::tryToBuy(std::ostream& os,Player& player,int type,int cost) const
{
    if(player.pay(cost))
    {
        if(type==BUY_HEALTH)
        {
            player.heal(1);
        }
        else
        {
            player.buff(1);
        }
        printMerchantSummary(os,player.getName(),type,cost);
    }
    else
    {
        printMerchantInsufficientCoins(os);
        printMerchantSummary(os,player.getName(),type,0);
    }
}