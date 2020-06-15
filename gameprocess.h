#ifndef GAMEPROCESS_H
#define GAMEPROCESS_H
#include <iostream>
#include "player.h"
#include "monster.h"

class GameProcess
{
    Player m_player;
    void GameProcess::attackPlayer(Monster& mon, Player& p);
    void GameProcess::attackMonster(Monster& mon, Player& p);
    void GameProcess::fightMonster( Player& p);
    void GameProcess::showResult();

public:
    GameProcess(const Player &player) : m_player(player) { }
    void run();
};

#endif // GAMEPROCESS_H
