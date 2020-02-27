#include <QTime>
#include <QPainter>
#include <iostream>
#include <QKeyEvent>
#include <string>
#include <thread>
#include "screen.h"
#include "coordinates.h"
screen::screen(QWidget *parent) : QWidget(parent)
{

    setStyleSheet("background-color:black;");
    setMouseTracking(true);
    resize(800,800);
    startTimer(1);
    snake = new Snake(700);
    snake->bodytrack();
    snake->apple();
    Timer.start();
    gametime.start();
    V=0;
    Framecounter = 0;
}

void screen::paintEvent(QPaintEvent *e)
{
    QPainter qp(this);

    qp.setPen(Qt::red);
    qp.drawPoint(snake->getx(0),snake->gety(0));
    qp.setPen(Qt::yellow);
    for(unsigned int i = 1; i < snake->snake.size(); i++)
    {
        qp.drawPoint(snake->getx(i),snake->gety(i));
    }
    qp.fillRect(snake->applex,snake->appley,10,10,Qt::blue);
    qp.drawText(10,10,QString::fromStdString(std::to_string(framerate)));
    qp.drawText(500,10,"Lenth :");
    qp.drawText(560,10,QString::fromStdString(std::to_string(snake->snake.size())));
    e->accept();


}
void screen::timerEvent(QTimerEvent *e)
{

    ++Framecounter;
    if(Timer.elapsed() >= 1000)
    {
        framerate = Framecounter;
        Timer.restart();
        Framecounter = 0;
    }

    if(gametime.elapsed() >= 100)
    {
       for(int i = 0; i < 1; i++)
       {
           snake->mv();
           snake->bodytrack();
       }


        V=0;
        repaint();
        gametime.restart();
    }
    ++V;
    e->accept();
}
void screen::keyPressEvent(QKeyEvent *e)
{

    int key = e->key();
    if(key == Qt::Key_Left)
    {
        snake->angle += 10;
    }
    if(key == Qt::Key_Right)
    {
        snake->angle -= 10;
    }
//    if(key == Qt::Key_Up)
//    {
//        snake->dy -= 1;
//    }
//    if(key == Qt::Key_Down)
//    {
//        snake->dy += 1;
//    }
}
void screen::mouseMoveEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();
    double la = x - snake->snake.at(0).codx;
    double lo = snake->snake.at(0).cody - y;
    if(la > 0 && lo >= 0)
    {
        snake->angle = atan(lo/la)*180/3.1415926;
    }

    if(la < 0 && lo >= 0)
    {
        snake->angle = atan(lo/la)*180/3.1415926+180;
    }
    if(la < 0 && lo < 0)
    {
        snake->angle = 180+atan(lo/la)*180/3.1415926;
    }
    if(la > 0 && lo < 0)
    {
        snake->angle = atan(lo/la)*180/3.1415926+360;
    }
    e->accept();
}
