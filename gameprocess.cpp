#include "gameprocess.h"
/*
GameProcess::GameProcess()
{

}

*/

void GameProcess::attackPlayer(Monster& mon, Player& p) {
    if (p.isDead())
        return;
    p.reduceHealth(mon.getAttackLevel());
    std::cout << "The " << mon.getName() << " hit you for "<< mon.getAttackLevel() <<" damage.\n";
}

void GameProcess::attackMonster(Monster& mon, Player& p){
    if (mon.isDead())
        return;
    mon.reduceHealth(p.getAttackLevel());
    std::cout << "You hit the " << mon.getName() << " for "<< p.getAttackLevel() <<" damage.\n";
    if (mon.isDead())
    {
        p.levelUp();
        std::cout << "You killed the " << mon.getName() << ".\n";
        std::cout << "You are now level " << p.getLevel() << ".\n";
        std::cout << "You found " << mon.getGold() << " gold.\n";
    }
}

void GameProcess::fightMonster( Player& p)
{
    Monster mon = Monster::getRandomMonster();
    std::cout << "You have encountered a " << mon.getName() << " (" << mon.getSymbol() << ").\n";
    while (!mon.isDead() && !p.isDead()) {
        std::cout << "(R)un or (F)ight: ";
        char symbol;
        std::cin >> symbol;
        if (symbol == 'r' || symbol == 'R'){
            if (0 != Monster::getRandomNumber(0, 1))
            {
                std::cout << "You successfully fled.\n";
                break;
            }
            else
                attackPlayer(mon, p);
        }
        else if (symbol == 'f'  || symbol == 'F'){
            attackMonster(mon, p);
            if (mon.isDead())
            {
                p.addGold(mon.getGold());
                break;
            }
            attackPlayer(mon, p);
        }
    }
}


void GameProcess::run()
{
    while (!m_player.hasWon() && !m_player.isDead())
    {
        fightMonster(m_player);
    }
    showResult();
}

void GameProcess::showResult()
{
    if (m_player.isDead())
    {
        std::cout << "You died at level " << m_player.getLevel() << " and with " << m_player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "You won at level " << m_player.getLevel() << " and with " << m_player.getGold() << " gold.\n";
        std::cout << "Congrtulation!\n";
    }
}
