#include "Mtmchkin.h"
#include "Players/Player.h"
#include "Cards/Card.h"
#include "utilities.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include "Exception.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"

Mtmchkin::Mtmchkin(const std::string &fileName):m_deckOfCards(),m_playerInGame(),m_winners(),m_losers(),m_rounds(0)
{
    printStartGameMessage();
    std::ifstream deckFile;
    try//opening the file
    {
        deckFile.open(fileName);
        setCardDeck(deckFile);//setting the cards
        deckFile.close();
    }
    catch(const std::exception& e)
    {
        deckFile.close();
        throw;
    }    
    getPlayersFromUser();
}

void Mtmchkin::setCardDeck(std::ifstream& deckFile)
{
    int lineCounter=0;
    int cardCounter=0;
    std::string cardFromUser;
    if(!deckFile.good())
    {
        throw DeckFileNotFound();
    }
    while(deckFile.good())
    {
        lineCounter++;
        try//get line from user
        {
            std::getline(deckFile,cardFromUser);
        }
        catch(const std::exception& e)//need to change
        {
            throw;
        }
        try//see if line is indeed a card 
        {
            if(cardFromUser.size()==0)
            {
                break;
            }
            if(cardFromUser[cardFromUser.size()-1]=='\n' || cardFromUser[cardFromUser.size()-1]==CARRAGE_RETURN)
            {
                cardFromUser=cardFromUser.substr(0,cardFromUser.size()-1);
            }
            isValidCard(cardFromUser,lineCounter);
            cardCounter++;
        }
        catch(const std::exception& e)
        {
            throw;
        }
    }
    if(cardCounter<5)
    {
        throw DeckFileInvalidSize();
    }
}

void Mtmchkin::isValidCard(const std::string& name,int line)
{
    if(name=="Gremlin")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Gremlin()));
    }
    else if(name=="Witch")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Witch()));
    }
    else if(name=="Dragon")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Dragon()));
    }
    else if(name=="Merchant")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Merchant()));
    }
    else if(name=="Treasure")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Treasure()));
    }
    else if(name=="Barfight")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Barfight()));
    }
    else if(name=="Mana")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Mana()));
    }
    else if(name=="Well")
    {
        m_deckOfCards.push(std::unique_ptr<Card>(new Well()));
    }
    else 
    {
        throw DeckFileFormatError(line);
    }
}

void Mtmchkin::getPlayersFromUser()
{
    int numOfPlayers=getNumberOfPlayers();
    std::string inputLine;
    bool start=true;
    for(int i=0;i<numOfPlayers;i++)
    {
        printInsertPlayerMessage();
        while(true)
        {
            try
            {
                getline(std::cin,inputLine);
                if(inputLine.size()==0 && start)  
                {
                    start=false;
                    continue;
                } 
                start=false;
                if(setPlayer(inputLine))
                {
                    break;
                }
            }
            catch(const std::exception& e)
            {
                
            }
        }
        
    }
}
bool Mtmchkin::setPlayer(std::string& inputLine)
{
    try
    {
        //split into different words
        std::vector<std::string> stringParts=getWords(inputLine);
        if(stringParts.size()!=NUM_OF_WORDS)
        {
            printInvalidInput();
            return false;
        }
        //check name
        if(!checkName(stringParts[0]))//name is valid
        {
            printInvalidName();
            return false;
        }
        //check type
        if(!checkPlayerType(stringParts[0],stringParts[1]))
        {
            printInvalidClass();
            return false;
        }
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return false;
}
std::vector<std::string> Mtmchkin::getWords(std::string& input) const
{
    std::vector<std::string> strings;
    bool spaceWas=true;
    int length=input.size();
    if(length==0)
    {
        return strings;
    }
    int numOfCharacters=0;
    int start=0;
    for(int i=0;i<length;i++)
    {
        if((!spaceWas) && input[i]==' ')
        {
            if(numOfCharacters>0)
            {
                strings.push_back(input.substr(start,numOfCharacters));
            }
            start=i+1;
            numOfCharacters=0;
        }
        if(input[i]==' ')
        {
            spaceWas=true;
            start=i+1;
        }
        else
        {
            spaceWas=false;
            numOfCharacters++;
        }
    }
    if(numOfCharacters>=1)
    {
        strings.push_back(input.substr(start,numOfCharacters));
    }
    return strings;
}
bool Mtmchkin::checkPlayerType(std::string& name,std::string& type)
{
    /*
    if we reached here, the name is already valid
    */
   if(type=="Ninja")
   {
        m_playerInGame.push(std::shared_ptr<Player>(new Ninja(name)));
        return true;
   }
   else if(type=="Healer")
   {
        m_playerInGame.push(std::shared_ptr<Player>(new Healer(name)));
        return true;
   }
   else if(type=="Warrior")
   {
        m_playerInGame.push(std::shared_ptr<Player>(new Warrior(name)));
        return true;
   }
   return false;
}
bool Mtmchkin::checkName(std::string& name) const
{
    int size=name.size();
    for(int i=0;i<size;i++)
    {
        if ('A' <= name[i] && 'Z' >= name[i])
        {
            continue;
        }
        if ('a' <= name[i] && 'z' >= name[i])
        {
            continue;
        }
        return false;
    }
    return true;
}
int Mtmchkin::getNumberOfPlayers() const
{
    int size=0;
    while(size<2 || size>6)
    {
        printEnterTeamSizeMessage();
        try
        {
            std::cin >> size;
            if(size>=2 && size<=6)
            {
                break;
            }
        }
        catch(const std::exception& e)
        {
            throw;
        }
        size=0;
        printInvalidTeamSize();
    }
    return size;
}
void Mtmchkin::playRound()
{
    printRoundStartMessage(m_rounds+1);
    int queueLength=m_playerInGame.size();
    for(int i=0;i<queueLength;i++)
    {
        std::shared_ptr<Player> currentPlayer=m_playerInGame.front();
        m_playerInGame.pop();
        printTurnStartMessage(currentPlayer->getName());
        std::unique_ptr<Card> currentCard=std::move(m_deckOfCards.front());
        m_deckOfCards.pop();
        currentCard->applyEncounter(*currentPlayer);
        if(currentPlayer->isKnockedOut())
        {
            m_losers.push(currentPlayer);
        }
        else if(currentPlayer->getLevel()==MAX_LEVEL)
        {
            m_winners.push(currentPlayer);
        }
        else
        {
            m_playerInGame.push(currentPlayer);
        }
        //returning the cards
        m_deckOfCards.push(std::move(currentCard));
    }
    m_rounds++;
    if(isGameOver())
    {
        printGameEndMessage();
    }
    //printLeaderBoard();
}
void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking=1;
    printQueue(m_winners,ranking);
    printQueue(m_playerInGame,ranking);
    printStack(m_losers,ranking);
}
void Mtmchkin::printQueue(std::queue<std::shared_ptr<Player>> queue ,int& ranking) const
{
    while(!queue.empty())
    {
        printPlayerLeaderBoard(ranking,*(queue.front()));
        queue.pop();
        ranking++;
    }
}
void Mtmchkin::printStack(std::stack<std::shared_ptr<Player>> stack,int& ranking) const
{
    while(!stack.empty())
    {
        printPlayerLeaderBoard(ranking,*(stack.top()));
        stack.pop();
        ranking++;
    }
}
int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds;
}

bool Mtmchkin::isGameOver() const
{
    return m_playerInGame.empty();
}