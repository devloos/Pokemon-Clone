#include "Logic.h"

namespace Logic {
void Start(float &x, float &y, Sprite &nami) {
  if (IsKeyDown(KEY_LEFT)) {
    x += GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kLeft;
  }
  // spritedir = left
  // is it animated or did they just oress the key down  nce
  if (IsKeyDown(KEY_RIGHT)) {
    x -= GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kRight;
  }
  if (IsKeyDown(KEY_DOWN)) {
    y -= GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kForward;
  }
  if (IsKeyDown(KEY_UP)) {
    y += GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kBackward;
  }
}
}  // namespace Logic