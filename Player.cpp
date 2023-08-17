#include "Player.h"
#include "utilities.h"
Player::Player(const std::string name,const int maxHP,const int force):m_name(name),m_maxHP(maxHP),m_force(force),m_level(START_LEVEL),m_hp(maxHP),m_coins(0)
{
    if(m_maxHP<=0)
    {
        m_maxHP=DEFAULT_MAX_HP;
        m_hp = DEFAULT_MAX_HP;
    }
    if(force<0)
    {
        m_force=DEFAULT_FORCE;
    }
}

void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(),m_level,m_force,m_hp,m_coins);
}

void Player::levelUp()
{
    if(m_level<MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(const int forcePoints)
{
    if (forcePoints > 0)
    {
        m_force += forcePoints;
    }
}

void Player::heal(const int healPoints)
{
    if(healPoints>0)
    {
        if(m_hp+healPoints<=m_maxHP)
        {
            m_hp+=healPoints;
        }
        else
        {
            m_hp=m_maxHP;
        }
    }
}

void Player::damage(const int damgaePoints)
{
    if(damgaePoints>0)
    {
        if(damgaePoints>m_hp)
        {
            m_hp=0;
        }
        else
        {
            m_hp-=damgaePoints;
        }
    }
}

bool Player::isKnockedOut() const
{
    return m_hp==0;
}

void Player::addCoins(const int coins)
{
    if (coins > 0)
    {
        m_coins += coins;
    }
}

bool Player::pay(const int price)
{
    if(price>m_coins)
    {
        return false;
    }
    if (price <= 0)//according to FAQ published
    {
        return true;
    }
    m_coins-=price;
    return true;
}

int Player::getAttackStrength()const
{
    return m_force+m_level;
}