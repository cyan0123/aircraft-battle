#include "enemy.h"

Enemy::Enemy(int x, int y):GameObj(x, y)
{
    pic.load(":/res/enemy.png");
}
void Enemy::UpdatePosition()
{
    GameObj::UpdatePosition(getX(),getY() + speed);
}
