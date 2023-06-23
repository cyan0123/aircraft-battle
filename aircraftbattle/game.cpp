#include "game.h"
#include "ui_game.h"
using namespace std;

double getDistance(int x1, int y1, int x2, int y2);

Game::Game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    //设置属性::当窗口关闭时，窗口对象将被销毁，内存得以释放
    setAttribute(Qt::WA_DeleteOnClose,true);
    //设置窗口大小
    resize(450,800);
    //为游戏窗口设置背景
    setAutoFillBackground(true);
    QPalette pal;
    QPixmap pixmap(":/res/map.jpg");
    pal.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(pal);

    label_hp = new QLabel("hp:10", this);
    label_score = new QLabel("score:", this);
    label_value = new QLabel("000", this);
    QFont font;
    font.setPointSize(20);
    label_hp->setFont(font);
    label_score->setFont(font);
    label_value->setFont(font);
    label_hp->move(20, 20);
    label_score->move(150, 20);
    label_value->move(230, 20);

    myplane = new MyPlane(225, 750);

    srand(time(NULL));
    GameInit();
}

void Game::GameInit()
{
    myplane->UpdatePosition(225, 700);
    myplane->setHp(10);
    myplane->bullets.clear();
    hp = myplane->getHp();
    score = 0;
    dtime1 = 0;
    dtime2 = 0;
    num_enemy = 0;
    pause = 0;
    Timer.setInterval(25); //设置定时器间隔，每10ms刷新一次
    GamePlay();
}

void Game::GamePlay()
{
    Timer.start();
    connect(&Timer , &QTimer::timeout,[=](){
        myUpdate();
        GUIUpdate();
        update();
    }); 	//connect开始计时刷新
}

void Game::GameOver()
{
    QMessageBox::information(NULL,"游戏结束",QString::fromStdString("GAME OVER\nScore:"+to_string(score)+"\n按OK继续"));
    this->close();
}

void Game::myUpdate()
{
    dtime1++;
    dtime2++;
    if (myplane->getHp() > 0)
    {
        if (dtime1 > 4)
        {
            for (int f = 0; f < myplane->bullets.size(); f++)
            {
                if (myplane->bullets[f].getY() < 50)
                {
                    myplane->bullets.erase(myplane->bullets.begin() + f);
                    f--;
                }
                else
                {
                    myplane->bullets[f].UpdatePosition();
                }
            }
            dtime1 = 0;
        }
        if (dtime2 > 20)
        {
            for (int f = 0; f < enemys.size(); f++)
            {
                if (enemys[f].getY() >= length - 100)
                {
                    enemys.erase(enemys.begin() + f);
                    f--;
                    num_enemy--;
                }
                else
                {
                    enemys[f].UpdatePosition();
                }
            }
            if (num_enemy < max_enemy)
            {
                Enemy enemy(rand() % (width - 80) + 20, 0);
                enemys.push_back(enemy);
                num_enemy++;
            }
            dtime2 = 0;
        }
        //检测碰撞
        for (int f = 0; f < enemys.size(); f++)
        {
            //子弹
            for (int f1 = 0; f1 < myplane->bullets.size() && f < enemys.size(); f1++)
            {
                if (getDistance(myplane->bullets[f1].getX(),myplane->bullets[f1].getY(),enemys[f].getX()+10,enemys[f].getY())<25)
                {
                    enemys.erase(enemys.begin() + f);
                    f--;
                    num_enemy--;
                    score++;
                    myplane->bullets.erase(myplane->bullets.begin() + f1);
                    f1--;
                }
            }
            //myplane
            if (f < enemys.size() && getDistance(myplane->getX()+10,myplane->getY(),enemys[f].getX()+10,enemys[f].getY())<35)
            {
                myplane->setHp(myplane->getHp()-1);
                enemys.erase(enemys.begin() + f);
                f--;
                num_enemy--;
            }
        }
    }
    else
        GameOver();
}
void Game::GUIUpdate()
{
    label_hp->setText(QString::fromStdString("hp:"+to_string(myplane->getHp())));
    label_value->setText(QString::fromStdString(to_string(score)));
}
void Game::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(myplane->getX(),myplane->getY(),myplane->pic);
    for (int f = 0; f < enemys.size(); f++)
    {
        painter.drawPixmap(enemys[f].getX(),enemys[f].getY(),enemys[f].pic);
    }
    for (int f = 0; f < myplane->bullets.size(); f++)
    {
        painter.drawPixmap(myplane->bullets[f].getX(),myplane->bullets[f].getY(),myplane->bullets[f].pic);
    }
    update();
}

void Game::keyPressEvent(QKeyEvent* E)
{
    char key = char(E->key());
    key = key >= 'a' ? key - 32 : key;	//统一转换为大写字母
    switch (key)
    {
    case 'W':
        if (myplane->getY() > 100)
            myplane->UpdatePosition(myplane->getX(), myplane->getY()-10);
        break;
    case 'S':
        if (myplane->getY() < length - 100)
            myplane->UpdatePosition(myplane->getX(), myplane->getY()+10);
        break;
    case 'A':
        if (myplane->getX() > 20)
            myplane->UpdatePosition(myplane->getX()-10, myplane->getY());
        break;
    case 'D':
        if (myplane->getX() < width - 100)
            myplane->UpdatePosition(myplane->getX()+10, myplane->getY());
        break;
    case 'Q':
        myplane->setHp(0);
        break;
    case 'E':
        if (pause)
        {
            pause = 0;
            Timer.start();
        }
        else
        {
            pause = 1;
            Timer.stop();
        }
        break;
    case ' ':
        Bullet bullet(myplane->getX()+40, myplane->getY() - 40);
        myplane->bullets.push_back(bullet);
        break;
    }
    update();
}
double getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
Game::~Game()
{
    delete ui;
    delete label_hp;
    delete label_score;
}

