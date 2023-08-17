#include <string>
#include <iostream>
#include "Mtmchkin.h"
#include "Exception.h"

int main(){
    try
    {
        Mtmchkin mtmchkinGame("deck.txt");
        while (!mtmchkinGame.isGameOver())
        {
            mtmchkinGame.playRound();
            mtmchkinGame.printLeaderBoard();
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
