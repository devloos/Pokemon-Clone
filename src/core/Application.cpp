#include "Application.h"

namespace Application {
void Start() {
  InitWindow(WIN_WIDTH, WIN_HEIGHT, "Pokemon Clone");
  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  Texture2D SafariMap = LoadTexture("../assets/maps/SafariMap.png");

  float x = START_X;
  float y = START_Y;

  Player Nami;

  // Main game loop
  while (!WindowShouldClose()) {
    Logic::Start(x, y, Nami);
    Draw::Start(SafariMap, x, y, Nami);
  }
}

void Finish() {
  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------
}
}  // namespace Application