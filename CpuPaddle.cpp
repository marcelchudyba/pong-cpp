//
// Created by XXX on 17.04.2026.
//

#include "CpuPaddle.h"

#include "Paddle.h"


CpuPaddle::CpuPaddle(float x, float y, int width, int height, int speed): Paddle(x, y, width, height, speed){};

void CpuPaddle::Update(float ball_y) {
    if(y + height / 2 > ball_y) {
        y = y - speed;
    }
    if(y + height / 2 < ball_y) {
        y = y + speed;
    }
    LimitMovement();
}