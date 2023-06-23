#include "myplane.h"

MyPlane::MyPlane(int x, int y):GameObj(x, y)
{
    pic.load(":/res/plane.png");
    hp = 10;
    bullets.clear();
}
int MyPlane::getHp()
{
    return hp;
}
void MyPlane::setHp(int hp)
{
    this->hp=hp;
}
