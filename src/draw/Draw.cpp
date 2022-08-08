#include "Draw.h"

#include <iostream>

namespace Draw {
void Start(
    Texture2D &SafariMap, Texture2D &NamiWalkingState, const float &x, const float &y,
    float &frameWidth, float &timer, int &maxFrames, int &frame, float &frameHeight,
    Nami &namiObj) {
  float height;
  BeginDrawing();
  ClearBackground(RAYWHITE);

  // ===============================
  timer += GetFrameTime();
  if (timer >= 0.2f) {
    timer = 0.0f;
    frame += 1;
  }
  frame = frame % maxFrames;
  std::cout << frame << std::endl;
  // ===============================

  switch (namiObj.m_StateDir_) {
    case Direction::kForward: {
      height = (frameHeight * 0.0f);
      break;
    }
    case Direction::kBackward: {
      height = (frameHeight * 2.0f);
      break;
    }
    case Direction::kLeft: {
      height = (frameHeight * 1.0f);
      break;
    }
    case Direction::kRight: {
      height = (frameHeight * 3.0f);
      break;
    }
    default: {
      height = (frameHeight * 0.0f);
      break;
    }
  }

  DrawTextureEx(SafariMap, Vector2{x, y}, ROTATION, SCALE, WHITE);

  DrawTextureTiled(
      NamiWalkingState,
      Rectangle{(frameWidth * frame), height, (frameWidth), (frameHeight)},
      Rectangle{CENTER_X - 2, CENTER_Y, 24, 34}, Vector2{0, 0}, ROTATION, 1.3f, WHITE);

  EndDrawing();
}
}  // namespace Draw