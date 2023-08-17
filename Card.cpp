//
// Created by Itamar on 12/05/2023.
//
#include "Card.h"
#include "utilities.h"
Card::Card(CardType type, const CardStats& stats): m_effect(type),m_stats(CardStats(stats.force,stats.hpLossOnDefeat,stats.cost,stats.heal,stats.buff,stats.loot))
{

}
void Card::printInfo() const
{
    if(this->m_effect == CardType::Battle)
    {
        printBattleCardInfo(this->m_stats);
    }
    else if(this->m_effect == CardType::Heal)
    {
        printHealCardInfo(this->m_stats);
    }
    else if(this->m_effect == CardType::Buff)
    {
        printBuffCardInfo(this->m_stats);
    }
    else //Treasure
    {
        printTreasureCardInfo(this->m_stats);
    }
}

void Card::applyEncounter(Player& player) const
{
    if(this->m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
    else if(this->m_effect == CardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
    }
    else if(this->m_effect == CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
    }
    else //Battle
    {
        if(player.getAttackStrength() >= m_stats.force) //the player wins the battle
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        }
        else // the player loses the battle
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
    }
}