#include "bullet.h"

Bullet::Bullet(int x, int y):GameObj(x, y)
{
    pic.load(":/res/bullet.png");
}
void Bullet::UpdatePosition()
{
    GameObj::UpdatePosition(getX(),getY() - speed);
}
