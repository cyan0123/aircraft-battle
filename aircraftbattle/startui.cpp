#include "startui.h"

#include <iostream>
using namespace std;

StartUi::StartUi(QWidget *parent)
    : QWidget{parent}
{
    //设置属性::当窗口关闭时，窗口对象将被销毁，内存得以释放
    setAttribute(Qt::WA_DeleteOnClose,true);
    //设置窗口大小
    resize(450,800);

    QPushButton* start, * help, * about;
    start = new QPushButton("Start Game");
    help = new QPushButton("Help");
    about = new QPushButton("about");
    start->setStyleSheet("QPushButton{background: transparent;}");
    help->setStyleSheet("QPushButton{background: transparent;}");
    about->setStyleSheet("QPushButton{background: transparent;}");
    connect(start, SIGNAL(clicked()),this,SLOT(mystart()));
    connect(help, SIGNAL(clicked()),this,SLOT(myhelp()));
    connect(about, SIGNAL(clicked()),this,SLOT(myabout()));
    QLabel* title = new QLabel("Aircraft Battle");
    QFont font;
    font.setPointSize(20);
    title->setFont(font);
    font.setPointSize(15);
    start->setFont(font);
    help->setFont(font);
    about->setFont(font);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addSpacing(200);
    vbox->addWidget(title);
    vbox->addSpacing(200);
    vbox->addWidget(start);
    vbox->addWidget(help);
    vbox->addWidget(about);
    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addSpacing(100);
    hbox->addLayout(vbox);
    hbox->addSpacing(100);
    setLayout(hbox);

    //为游戏窗口设置背景
    setAutoFillBackground(true);
    QPalette pal;
    QPixmap pixmap(":/res/map.jpg");
    pal.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(pal);
}
void StartUi::mystart()
{
    Game* game = new Game;
    game->show();
//    this->close();
}
void StartUi::myhelp()
{
    QMessageBox::information(NULL,"Help","玩家利用WASD控制战机移动，按空格键发射子弹。\n子弹击中敌机可消灭敌人，得分增加；敌机触碰到战机会扣除生命值，生命值为零游戏结束。\n按Q键结束游戏，E键暂停游戏再次按E继续游戏。");
}
void StartUi::myabout()
{
    QMessageBox::information(NULL,"About","Author:桑赫林");
}
