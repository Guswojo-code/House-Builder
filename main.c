#include "raylib.h"
#include "stdio.h"

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
  float speed = 0.1;
  while (!WindowShouldClose()) {

    if (IsKeyDown(KEY_RIGHT)) { ball.x += speed*acceleration; acceleration += 0.000125; }
    if (IsKeyDown(KEY_LEFT)) { ball.x -= speed*acceleration; acceleration -= 0.000125; }
    if (IsKeyDown(KEY_UP)) { ball.y -= speed*acceleration; acceleration -= 0.000125; }
    if (IsKeyDown(KEY_DOWN)){ ball.y += speed*acceleration; acceleration += 0.000125; }
    //acceleration += 0.000125; 

    //ball = GetMousePosition();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleV(ball, 20, GREEN);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
