#include <algorithm>
#include <raylib.h>

#include "Ball.h"
#include "CpuPaddle.h"
#include "Paddle.h"

using namespace std;
struct Ball_Struct {
    float x;
    float y;
    int r;
};
struct Rec_Struct {
    float x,y;
    int width,height;
};

bool checkColCircleRec(Ball_Struct ball,Rec_Struct rec ){
    float closestX;
    float closestY;

    //closestX w zasadzie to to tutaj po prostu sprawdzamy ktory punkt jest najblizej czy bedzie to od lewej czy od prawej strony
    //jak ball.x jest mniejsza od rec.x czyli tego po lewej stronie to mamy wtedy

    //lewa krawedz
    if(ball.x < rec.x) {
        closestX = rec.x;
    }
    //prawa krawedz
    else if(ball.x > rec.x + rec.width) {
        closestX = rec.x + rec.width;
    }
    else {
        closestX = ball.x;
    }
    //gora
    if(ball.y < rec.y) {
        closestY = rec.y;
    }
    //dol
    else if(ball.y > rec.y + rec.height) {
        closestY = rec.y + rec.height;
    }
    else {
        closestY = ball.y;
    }


    //sprawdzamy czy w ten punkt ktory oszacowalismy jako najblizszy jest w srodku okregu z rownania okregu
    //(x- x0)2 + (y- y0)2 <= r2 jezeli r2 jest wieksze to znaczy ze punkt jest w okregu jezeli jest mniejsze to po za nim
    float left_equation = (closestX - ball.x)*(closestX - ball.x) + (closestY - ball.y)*(closestY - ball.y);
    if(left_equation <= ball.r*ball.r) {
        return true;
    }
    return false;
}


int main() {

    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "Pong Game");

    SetTargetFPS(60);

    Ball ball = Ball(screen_width/ 2,screen_height / 2,7,7,20);
    Paddle player = Paddle(screen_width - 35, screen_height / 2 - 60, 25,120,7);
    CpuPaddle cpu = CpuPaddle(10, screen_height / 2 - 60, 25, 120, 7);
    //Game Loop
    while(WindowShouldClose() == false) {

        ClearBackground(BLACK);
        BeginDrawing();

        ball.Update();
        player.Update();
        cpu.Update(ball.y);



        if(checkColCircleRec(Ball_Struct(ball.x,ball.y,ball.radius),Rec_Struct(player.x,player.y,player.width,player.height))){
            ball.speed_x *= -1;
        }
        if(checkColCircleRec(Ball_Struct(ball.x,ball.y,ball.radius),Rec_Struct(cpu.x,cpu.y,cpu.width,cpu.height))){
            ball.speed_x *= -1;
        }
        DrawLine(screen_width / 2, 0, screen_width / 2,screen_height,WHITE);

        cpu.Draw();
        ball.Draw();
        player.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
