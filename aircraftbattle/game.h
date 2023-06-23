#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QString>
//#include <time.h>
#include <vector>
#include <cstdlib>
#include <math.h>
#include "myplane.h"
#include "enemy.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
    void GameInit();
    void GamePlay();
    void GameOver();
    void paintEvent(QPaintEvent *E);
    void myUpdate();
    void GUIUpdate();
    void keyPressEvent(QKeyEvent* E);
private:
    const int width = 450;
    bool pause;
    const int length = 800;
    const int max_enemy = 10;
    Ui::Game *ui;
    QLabel* label_hp, * label_score, * label_value;
    int hp, score;
    MyPlane* myplane;
    vector<Enemy> enemys;
    QTimer Timer;
    int dtime1;
    int dtime2;
    int num_enemy;
};
#endif // GAME_H
