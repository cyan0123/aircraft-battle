#ifndef GAMEOBJ_H
#define GAMEOBJ_H
#include <QPixmap>

class GameObj
{
public:
    GameObj(int x, int y);
    void UpdatePosition(int x, int y);
    int getX();
    int getY();
private:
    int x;
    int y;
};

#endif // GAMEOBJ_H
