#include "gameprocess.h"

int main()
{
    srand(static_cast<unsigned int>(time(0))); //  ustawienie zegara systemowego jako począkowa liczba
    rand(); // resetuje pierwszy wynik

    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    Player p(name);
    GameProcess gameProc(p);
    gameProc.run();
    return 0;
}
