#include "raylib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"



int main(int argc, char *argv[])
{
  const int screenWidth = 810;
  const int screenHeight = 450;
  Vector2 object = { -100.0f, -100.0f };
  Vector2 grassSet = { 0, 0 };
  object.x = 0;
  object.y = 0;

  InitWindow(screenWidth, screenHeight, "house");
  InitAudioDevice();
  SetTargetFPS(60);

  //Audio
  Sound placeWav = LoadSound("objects/sounds/build.wav");
  Sound errorWav = LoadSound("objects/sounds/error.wav");
  float acceleration = 0.000769;
  const int speed = 30.0f;
  Vector2 object1;
  int sleepTime;
  Vector2 size;
  Vector2 block[20];
  Vector2 textPos = {0,0};
  int blocknum = 0;
  int i;
  int roof = 20;
  int leftBlocks = roof;

  Font fontTtf = LoadFontEx("objects/PixAntiqua.ttf", 32, 0, 250);    

  Image graybrick = LoadImage("objects/graybrick.png");
  ImageFlipHorizontal(&graybrick);
  ImageResize(&graybrick, 30, 30);
  Texture2D texture = LoadTextureFromImage(graybrick);
  
  Image grass = LoadImage("objects/Grass.png");
  ImageResize(&grass, 30, 30);
  Texture2D grassTexture = LoadTextureFromImage(grass);
  


  while (!WindowShouldClose()){

    float deltaTime = GetFrameTime();
    sleepTime = deltaTime;
    size.x = 30;
    size.y = 30;

    if (IsKeyPressed(KEY_ENTER)) {
      block[blocknum] = object;
      if (leftBlocks != 0){
            leftBlocks --;
            PlaySound(placeWav);
      }
      else {
            PlaySound(errorWav);
      }
      if (roof > blocknum){
        blocknum ++;
      }
    }
    if (IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D)) { object.x += speed; }
    if (IsKeyPressed(KEY_LEFT)) { object.x -= speed; }
    if (IsKeyPressed(KEY_UP)) { object.y -= speed; }
    if (IsKeyPressed(KEY_DOWN)){ object.y += speed;}

    BeginDrawing();

    ClearBackground(RAYWHITE);


    for (grassSet.y = 0; grassSet.y < 450;) {
           DrawTextureV(grassTexture, grassSet, WHITE);
           grassSet.x += 30;

           if (grassSet.x > 800) {
              grassSet.y += 30;
              grassSet.x = 0;

           }

    }   

   for (i = 0; i < blocknum; i++) {
          DrawTextureV(texture, block[i], WHITE);
    }

    //Baundry collision
   if (object.x < 0) {
    object.x += 30;
   }
   else if (object.x >= screenWidth){
    object.x -= 30;
   }
   if (object.y < 0) {
    object.y += 30;
   }
   else if (object.y >= screenHeight) {
    object.y -= 30;
   }

    DrawTextureV(texture, object, WHITE);

    DrawRectangleLines(object.x, object.y, size.x, size.y, BLACK);

    DrawTextEx(fontTtf,TextFormat("Blocks left: %3i", leftBlocks), textPos, (float)fontTtf.baseSize/2, 2, BLACK);
    //DrawText(i, int posX, int posY, int fontSize, Color color)
    EndDrawing();
  }
  UnloadSound(errorWav);
  UnloadSound(placeWav);

  UnloadImage(graybrick);
  UnloadImage(grass);
  
  UnloadFont(fontTtf);

  CloseWindow();
  return 0;
}


