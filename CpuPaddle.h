//
// Created by XXX on 17.04.2026.
//

#ifndef CPUPADDLE_H
#define CPUPADDLE_H
#include "Paddle.h"


class CpuPaddle : public Paddle {
public:
    CpuPaddle(float x, float y, int width, int height, int speed);
    void Update(float ball_y);

};


#endif //CPUPADDLE_H
