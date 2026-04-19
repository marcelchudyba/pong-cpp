//
// Created by XXX on 17.04.2026.
//

#ifndef PADDLE_H
#define PADDLE_H



class Paddle {
public:
    float x,y;
    int width,height;
    int speed;
    Paddle(float x, float y, int width, int height, int speed);
    void Draw();
    void Update();
protected:
    void LimitMovement();
};



#endif //PADDLE_H
