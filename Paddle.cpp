//
// Created by XXX on 17.04.2026.
//

#include "Paddle.h"

#include <raylib.h>

Paddle::Paddle(float x, float y, int width, int height, int speed) : x(x), y(y), width(width), height(height), speed(speed) {}

void Paddle::Draw() {
    DrawRectangle(x,y, width, height, WHITE);
}

void Paddle::Update() {
    if (IsKeyDown(KEY_UP)) {
        if(y > 0) y -= speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
        if(y < GetScreenHeight() - height) y += speed;
    }
}
