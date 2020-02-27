#include "Snake.h"
Snake::Snake(int l)
{
    grow = true;
    head = new Node(100,100);
    for(int i = 0; i < l; i++)
    {
        snake.insert(snake.begin(),*head);
        head->codx +=1;
    }

}
int Snake::getx(unsigned int i)
{
    return snake.at(i).codx;
}
int Snake::gety(unsigned int i)
{
    return snake.at(i).cody;
}
void Snake::mv()
{
    if(angle > 359)
    {
        angle = 0;
    }
    if(angle < 0)
    {
        angle = 359;
    }
    dx += cos(angle*3.1415926/180);
    dy += sin(angle*3.1415926/180);
//    std::cout<<angle<<std::endl;
//    std::cout<<dx<<std::endl;
    if(dx >= 1)
    {
        Node a(snake.at(0).codx+1,snake.at(0).cody);
        snake.insert(snake.begin(),a);
        if(!grow)
        {
            snake.pop_back();
        }
        if(snake.at(0).codx > 799)
        {
            snake.at(0).codx = 1;
        }
        dx -= 1;
        grow = false;

    }
    if(dx <= -1)
    {
        Node a(snake.at(0).codx-1,snake.at(0).cody);
        snake.insert(snake.begin(),a);
        if(!grow)
        {
            snake.pop_back();
        }
        if(snake.at(0).codx < 0)
        {
            snake.at(0).codx = 799;
        }
        dx += 1;
        grow = false;
    }

    if(dy >= 1)
    {

        Node a(snake.at(0).codx,snake.at(0).cody-1);
        snake.insert(snake.begin(),a);
        if(!grow)
        {
            snake.pop_back();
        }
        if(snake.at(0).cody < 0)
        {
            snake.at(0).cody = 799;
        }
        dy -= 1;
        grow = false;
    }
    if(dy <= -1)
    {

        Node a(snake.at(0).codx,snake.at(0).cody+1);
        snake.insert(snake.begin(),a);
        if(!grow)
        {
            snake.pop_back();
        }
        if(snake.at(0).cody > 799)
        {
            snake.at(0).cody = 0;
        }
        dy += 1;
        grow = false;
    }

}
void Snake::apple()
{
    for(int y = 0; y < 800; ++y)
    {
        for(int x = 0; x < 800; ++x)
        {
            spawnable[x][y] = true;
        }
    }
    for(unsigned int i = 0; i < snake.size(); ++i)
    {
        spawnable[(snake.at(i).codx)][(snake.at(i).cody)] = false;
    }
    std::vector<coordinates> codmap;
        for(int y = 0; y < 800; ++y)
        {
            for(int x = 0; x < 800; ++x)
            {

                if(spawnable[x][y] == true)
                {
                    coordinates cods(x,y);
                    codmap.insert(codmap.end(),cods);
                }
            }
        }
   std::random_shuffle(codmap.begin(),codmap.end());
   applex = codmap.at(0).x;
   appley = codmap.at(0).y;
   //std::cout<<codmap.size()<<std::endl;
}
void Snake::bodytrack()
{
    for(unsigned int i = 0; i < snake.size(); ++i)
    {
        if(i>0)
        {
            if(snake.at(0).codx == snake.at(i).codx && snake.at(0).cody == snake.at(i).cody)
            {
                snake.erase(snake.begin()+i,snake.end());
               // std::cout<<"ok"<<std::endl;
            }

        }
    }
    if(getx(0) <= applex+10 && getx(0) >= applex && gety(0) >= appley && gety(0) <= appley+10)
    {
        grow = true;
        apple();
    }
}


