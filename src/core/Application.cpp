#include "Application.h"

#include "../nami/Nami.h"

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
  // Texture2D Nami = LoadTexture("../assets/sprites/Nami.png");

  Texture2D NamiWalkingState = LoadTexture("../assets/sprites/NamiWalkingState.png");

  float x = START_X;
  float y = START_Y;

  float frameWidth = (float)(NamiWalkingState.width / 3);
  int maxFrames = (int)(NamiWalkingState.width / (int)frameWidth);
  float frameHeight = (float)(NamiWalkingState.height / 4);

  float timer = 0.0f;
  int frame = 0;

  Nami namiObj;

  // Main game loop
  while (!WindowShouldClose()) {
    Logic::Start(x, y, namiObj);
    Draw::Start(
        SafariMap, NamiWalkingState, x, y, frameWidth, timer, maxFrames, frame,
        frameHeight, namiObj);
  }
}

void Finish() {
  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();  // Close window and OpenGL context
  //--------------------------------------------------------------------------------------
}
}  // namespace Application