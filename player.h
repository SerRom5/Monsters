#ifndef PLAYER_H
#define PLAYER_H
#include "creature.h"

class Player : public Creature
{
    int m_level;
public:
    Player(std::string name)
        : Creature(name, '@', 10, 1, 0), m_level(1) {}

    void levelUp();
    int getLevel() const { return m_level; }
    bool hasWon() { return m_level >= 20; }

};
#endif // PLAYER_H
