#ifndef MYPLANE_H
#define MYPLANE_H

#include "gameobj.h"
#include "bullet.h"
#include <vector>
using namespace std;

class MyPlane : public GameObj
{
public:
    MyPlane(int x, int y);
    QPixmap pic;
    int getHp();
    void setHp(int hp);
    vector<Bullet> bullets;
private:
    int hp;
};

#endif // MYPLANE_H
