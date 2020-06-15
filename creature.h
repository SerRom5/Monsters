#ifndef CREATURE_H
#define CREATURE_H
#include <string>

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_attackLevel;
    int m_gold;

public:
    Creature(std::string name, char symbol, int health, int attackLevel, int gold)
        : m_name(name), m_symbol(symbol), m_health(health), m_attackLevel(attackLevel), m_gold(gold)
    {}

    std::string& getName() { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getAttackLevel() const { return m_attackLevel; }
    int getGold() const { return m_gold; }

    void reduceHealth(int health) { m_health -= health; }
    bool isDead() const { return (m_health <= 0) ? true : false; }
    void addGold(int gold) { m_gold += gold; }

};

#endif // CREATURE_H
