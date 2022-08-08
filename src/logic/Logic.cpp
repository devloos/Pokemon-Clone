#include "Logic.h"

namespace Logic {
void Start(float &x, float &y, Sprite &nami) {
  if (IsKeyDown(KEY_LEFT)) {
    nami.m_InAnimation = true;
    x += GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kLeft;
  } else if (IsKeyReleased(KEY_LEFT)) {
    nami.m_InAnimation = false;
  }

  if (IsKeyDown(KEY_RIGHT)) {
    nami.m_InAnimation = true;
    x -= GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kRight;
  } else if (IsKeyReleased(KEY_RIGHT)) {
    nami.m_InAnimation = false;
  }

  if (IsKeyDown(KEY_DOWN)) {
    nami.m_InAnimation = true;
    y -= GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kForward;
  } else if (IsKeyReleased(KEY_DOWN)) {
    nami.m_InAnimation = false;
  }

  if (IsKeyDown(KEY_UP)) {
    nami.m_InAnimation = true;
    y += GetFrameTime() * 100.0f;
    nami.m_StateDir_ = Direction::kBackward;
  } else if (IsKeyReleased(KEY_UP)) {
    nami.m_InAnimation = false;
  }
}
}  // namespace Logic