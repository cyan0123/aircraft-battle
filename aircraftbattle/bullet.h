#ifndef BULLET_H
#define BULLET_H

#include "gameobj.h"

class Bullet : public GameObj
{
public:
    Bullet(int x, int y);
    void UpdatePosition();
    QPixmap pic;
private:
    int speed = 25;
};

#endif // BULLET_H
