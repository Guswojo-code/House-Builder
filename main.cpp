#include "raylib.h"
#include "stdio.h"
#include "unistd.h"
int main(int argc, char *argv[])
{
  const int screenWidth = 800;
  const int screenHeight = 450;
  Vector2 ball = { -100.0f, -100.0f };
  ball.x = 400;
  ball.y = 225;
  InitWindow(screenWidth, screenHeight, "house");
  SetTargetFPS(60);
  float acceleration = 0.000769;
  const int speed = 1.0f;
  int sleepTime;
  Vector2 size;
  while (!WindowShouldClose()) {
    
    float deltaTime = GetFrameTime();
    sleepTime = deltaTime;
    size.x = 30;
    size.y = 30;
    if (IsKeyDown(KEY_RIGHT)) { ball.x += speed; usleep(sleepTime);}
    if (IsKeyDown(KEY_LEFT)) { ball.x -= speed; usleep(sleepTime); }
    if (IsKeyDown(KEY_UP)) { ball.y -= speed; usleep(1000); }
    if (IsKeyDown(KEY_DOWN)){ ball.y += speed; usleep(1000); }
    //acceleration += 0.000125;

    //ball = GetMousePosition();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleV(ball, size, GREEN);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
