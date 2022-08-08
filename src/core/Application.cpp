#include "Application.h"

namespace Application {
void Start() {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 640;
  const int screenHeight = 480;

  InitWindow(screenWidth, screenHeight, "Pokemon Clone");

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  Texture2D SafariMap = LoadTexture("../assets/maps/SafariMap.png");
  Texture2D Nami = LoadTexture("../assets/sprites/Nami.png");

  float x = START_X;
  float y = START_Y;

  // Main game loop
  while (!WindowShouldClose()) {
    Logic::Start(x, y);
    Draw::Start(SafariMap, Nami, x, y);
  }
}

void Finish() {
  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------
}
}  // namespace Application

//