#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include "Node.h"
#include "coordinates.h"
class Snake
{
  public:
    Snake(int l);
    int getx(unsigned int i);
    int gety(unsigned int i);
    void mv();
    void apple();
    void bodytrack();



/* varables*/
    Node *head;
    std::vector<Node> snake;
    std::vector<coordinates> codmap;


    int applex;
    int appley;
    double dx = 0;
    double dy = 0;
    double angle = 0;


    bool spawnable[800][800];
    bool grow;
};
