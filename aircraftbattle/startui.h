#ifndef STARTUI_H
#define STARTUI_H

#include <QWidget>
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include "game.h"

class StartUi : public QWidget
{
    Q_OBJECT
public:
    explicit StartUi(QWidget *parent = nullptr);
    ~StartUi(){};
public slots:
    void mystart();
    void myhelp();
    void myabout();
};

#endif // STARTUI_H
