#include <raylib.h>

#include "Ball.h"
#include "Paddle.h"

using namespace std;

int main() {

    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "Math Graph");

    SetTargetFPS(60);

    Ball ball = Ball(screen_width/ 2,screen_height / 2,7,7,20);
    Paddle player = Paddle(screen_width - 35, screen_height / 2 - 60, 25,120,7);
    //Game Loop
    while(WindowShouldClose() == false) {

        ClearBackground(BLACK);
        BeginDrawing();

        ball.Update();
        player.Update();

        DrawLine(screen_width / 2, 0, screen_width / 2,screen_height,WHITE);
        ball.Draw();
        player.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
