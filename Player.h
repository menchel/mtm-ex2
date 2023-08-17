#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <iostream>
class Player
{
    public:

        //constractor of the player
        //@name- the name of the player
        //@maxHP- maximum health points for the player
        //@force- the force of the player
        //returns a new instance of the player
        Player(const std::string name,const int maxHP=DEFAULT_MAX_HP,const int force=DEFAULT_FORCE);

        //destructor
        ~Player()=default;

        //copy constructor
        Player(const Player& other)=default;

        //= operator
        Player& operator=(const Player& other)=default;

        //prints the info of the player
        void printInfo() const;

        //lift the players level by 1
        //if level is not less than 10, the function does nothing
        void levelUp();

        //getter for the player level
        int getLevel() const;

        //buff the player points by the parameter given
        void buff(const int forcePoints);

        //heals the player by the amount of points given
        //cannot heal to a HP of more than maxHP
        //if argument is smaller than 0 it will do nothing
        void heal(const int healPoints);

        //damages the player by the amount of points given
        //cannot remove to a smaller HP than 0
        //if argument is smaller than 0 it will do nothing
        void damage(const int damgaePoints);

        //Returns if the player's HP reached 0
        bool isKnockedOut() const;

        //adds the coins to the player
        void addCoins(const int coins);

        //returns if the player can pay the given price
        //if he can, he pays
        //else he does nothing
        bool pay(const int price);

        //returns the attack streangth of the player
        int getAttackStrength()const;


    private:
        std::string m_name;
        int m_maxHP;
        unsigned int m_force;
        int m_level;
        int m_hp;
        int m_coins;
        static const int START_LEVEL=1;
        static const int DEFAULT_FORCE=5;
        static const int DEFAULT_MAX_HP=100;
        static const int MAX_LEVEL=10;

};
#endif