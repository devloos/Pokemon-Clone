#include "Nami.h"

Nami::Nami() {
  m_StateDir_ = Direction::kForward;
  // Texture2D NamiWalkingState = LoadTexture("../assets/sprites/NamiWalkingState.png");
  m_InAnimation = false;
}

Nami::~Nami() {}

// void Nami::DrawNami(
//     Texture2D &SafariMap, Texture2D &NamiWalkingState, const float &x, const float &y,
//     float &frameWidth, float &timer, int &maxFrames, int &frame, int &frameHeight) {
//   //
//   DrawTextureTiled(
//       NamiWalkingState,
//       Rectangle{
//           (frameWidth * frame), (frameHeight * 1.0f), (frameWidth),
//           (float)(frameHeight)},
//       Rectangle{(640 / 2.0f) - 15, (480 / 2.0f) - 20, 24, 34}, Vector2{0, 0},
//       0.0f, 1.3f, WHITE);
// }
