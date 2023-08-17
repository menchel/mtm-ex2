#include "Mtmchkin.h"
#include "utilities.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
m_nextCardIndex(0),m_numOfCards(numOfCards),m_player(playerName),m_status(GameStatus::MidGame),m_cardsArray(new Card[m_numOfCards])
{
    for(int i=0;i<m_numOfCards;i++)
    {
        m_cardsArray[i]=cardsArray[i];
    }
}
Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}
Mtmchkin::Mtmchkin(const Mtmchkin& other):
m_nextCardIndex(other.m_nextCardIndex),m_numOfCards(other.m_numOfCards),m_player(other.m_player),m_status(other.m_status),m_cardsArray(new Card[other.m_numOfCards])
{
    for(int i=0;i<m_numOfCards;i++)
    {
        m_cardsArray[i]=other.m_cardsArray[i];
    }
}
Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other)
{
    if(this==&other)//avoid self assignment
    {
        return *this;
    }
    Card *temp=new Card[other.m_numOfCards];
    delete[] m_cardsArray;
    m_cardsArray=temp;
    for(int i=0;i<other.m_numOfCards;i++)
    {
        m_cardsArray[i]=other.m_cardsArray[i];
    }
    m_nextCardIndex=other.m_nextCardIndex;
    m_numOfCards=other.m_numOfCards;
    m_player=other.m_player;
    m_status=other.m_status;
    return *this;
}
void Mtmchkin::playNextCard()
{
    Card nextCard=m_cardsArray[m_nextCardIndex];
    nextCard.printInfo();
    nextCard.applyEncounter(m_player);
    m_player.printInfo();
    updateStatus();
    updateNextCardIndex();
}

bool Mtmchkin::isOver() const
{
    if(getGameStatus()==GameStatus::MidGame)
    {
        return false;
    }
    return true;
}
GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

void Mtmchkin::updateStatus()
{
    if(m_player.getLevel()==MAX_PLAYER_LEVEL)
    {
        m_status=GameStatus::Win;
    }
    else
    {
        if(m_player.isKnockedOut())
        {
            m_status=GameStatus::Loss;
        }
    }
}

void Mtmchkin::updateNextCardIndex()
{
    m_nextCardIndex++;
    if(m_nextCardIndex==m_numOfCards)
    {
        m_nextCardIndex=0;
    }
}