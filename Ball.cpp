//
// Created by XXX on 17.04.2026.
//

#include "Ball.h"
Ball::Ball(float x, float y, int speed_x, int speed_y, int radius) : x(x), y(y), speed_x(speed_x), speed_y(speed_y), radius(radius){}
void Ball::Draw() {
    DrawCircle(x,y,radius,WHITE);
}
void Ball::Update() {
    x += speed_x;
    y += speed_y;

    if(y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
    }

    if(x + radius >= GetScreenWidth() || x - radius <= 0) {
        speed_x *= -1;
    }

}