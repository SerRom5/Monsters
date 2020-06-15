#ifndef MONSTER_H
#define MONSTER_H
#include "creature.h"


#include <cstdlib> // dla rand() и srand()
#include <ctime> // dla time()

class Monster : public Creature
{
public:
    struct MonsterData
    {
        std::string name;
        char symbol;
        int health;
        int attackLevel;
        int gold;

    };

    enum Type {
        FRAGON,
        ORC,
        SLIME,
        MAX_TYPES,
    };

    Monster(Type type):
        Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health,
                 monsterData[type].attackLevel, monsterData[type].gold) {}

    static MonsterData monsterData[MAX_TYPES];

    static int getRandomNumber(int min, int max);
    static Monster getRandomMonster();

};

#endif // MONSTER_H
