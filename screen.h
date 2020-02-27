#pragma once
#include <QtWidgets>
#include "Snake.h"
#include <math.h>
#include <thread>
class screen  : public QWidget
{

    public:
        Snake *snake;
        int V;
        QTime Timer;
        QTime gametime;
        int Framecounter;
        int framerate;
        static int width;
        static int height;
        screen(QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent *);
        void timerEvent(QTimerEvent *);
        void keyPressEvent(QKeyEvent *);
        //void keyReleaseEvent(QKeyEvent *);
        void mouseMoveEvent(QMouseEvent *event);

};


