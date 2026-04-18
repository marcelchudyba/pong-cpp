//
// Created by XXX on 17.04.2026.
//

#ifndef BALL_H
#define BALL_H
#include <raylib.h>
#include <vector>


class Ball {
public:
    float x,y;
    int speed_x,speed_y;
    int radius;
    Ball(float x, float y, int speed_x, int speed_y, int radius);
    void Draw();
    void Update();

};



#endif //BALL_H
