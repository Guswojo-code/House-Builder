#include "raylib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"


char* coord(Vector2 object)
{

    char buffer [50];
    sprintf(buffer, "x=%d y=%d", object.x, object.y);

    return buffer;

}


int main(int argc, char *argv[])
{
  const int screenWidth = 800;
  const int screenHeight = 450;
  Vector2 object = { -100.0f, -100.0f };
  
  object.x = 400;
  object.y = 225;

  InitWindow(screenWidth, screenHeight, "house");
  SetTargetFPS(60);

  float acceleration = 0.000769;
  const int speed = 30.0f;
  Vector2 object1;
  int sleepTime;
  Vector2 size;
  Vector2 block[10];
  int blocknum = 0;
  int i;
  int roof = 10;

  Image cat = LoadImage("objects/graybrick.png");
  ImageFlipHorizontal(&cat);
  ImageResize(&cat, 30, 30);

  //ImageDrawRectangle(&cat, 4, 20, 10, 10, WHITE);

  Texture2D texture = LoadTextureFromImage(cat);

  while (!WindowShouldClose()){

    float deltaTime = GetFrameTime();
    sleepTime = deltaTime;
    size.x = 30;
    size.y = 30;
    if (IsKeyPressed(KEY_ENTER)) {
      block[blocknum] = object;
      printf("%d", blocknum);
      if (roof > blocknum){
        blocknum ++;
      }
    }
    if (IsKeyPressed(KEY_RIGHT)) { object.x += speed; }
    if (IsKeyPressed(KEY_LEFT)) { object.x -= speed; }
    if (IsKeyPressed(KEY_UP)) { object.y -= speed; }
    if (IsKeyPressed(KEY_DOWN)){ object.y += speed;}

    //acceleration += 0.000125;

    //ball = GetMousePosition();
    BeginDrawing();

    ClearBackground(RAYWHITE);
    //DrawRectangleV(object, size, GREEN);

    for (i = 0; i < blocknum; i++) {
          DrawTextureV(texture, block[i], WHITE);
    }
    DrawTextureV(texture, object, WHITE);
    DrawRectangleLines(object.x, object.y, size.x, size.y, BLACK);
    
    DrawText(TextFormat("Y = %03i", object.y), screenWidth/2, screenHeight/2, 10, BLACK);

    EndDrawing();
  }
  UnloadImage(cat);
  CloseWindow();
  return 0;
}


