//
// Created by XXX on 17.04.2026.
//

#include "Ball.h"

#include <iostream>
#include <ostream>

#include "GameState.h"
Ball::Ball(float x, float y, int speed_x, int speed_y, int radius) :start_x(x),start_y(y), x(x), y(y), speed_x(speed_x), speed_y(speed_y), radius(radius){}
void Ball::Draw() {
    DrawCircle(x,y,radius,WHITE);
}
void Ball::Init() {
    x = start_x;
    y = start_y;
    speed_x*= -1;
}

void Ball::Update(GameState& state) {

    x += speed_x;
    y += speed_y;

    if(y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
    }

    //right - cpu gets a point
    if(x + radius >= GetScreenWidth()) {
        state.cpu_score++;
        Init();
    }

    //left - player gets a point
    if(x - radius <= 0) {
        state.player_score++;
        Init();
    }


}