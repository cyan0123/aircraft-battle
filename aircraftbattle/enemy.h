#ifndef ENEMY_H
#define ENEMY_H

#include "gameobj.h"

class Enemy : public GameObj
{
public:
    Enemy(int x, int y);
    void UpdatePosition();
    QPixmap pic;
private:
    int speed = 15;
};

#endif // ENEMY_H
