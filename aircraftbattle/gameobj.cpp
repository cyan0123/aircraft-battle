#include "gameobj.h"

GameObj::GameObj(int x, int y)
{
    this->x = x;
    this->y = y;
}

void GameObj::UpdatePosition(int x, int y)
{
    this->x = x;
    this->y = y;
}
int GameObj::getX()
{
    return x;
}
int GameObj::getY()
{
    return y;
}
