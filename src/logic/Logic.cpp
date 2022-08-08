#include "Logic.h"

namespace Logic {
void Start(float &x, float &y, Sprite &nami) {
  if (KeysPressedSimultaneously()) {
    nami.m_InAnimation = false;
    return;
  }

  if (IsKeyDown(KEY_LEFT)) {
    x += GetFrameTime() * SPRITE_SPEED;
    nami.m_StateDir_ = Direction::kLeft;
  } else if (IsKeyDown(KEY_RIGHT)) {
    x -= GetFrameTime() * SPRITE_SPEED;
    nami.m_StateDir_ = Direction::kRight;
  } else if (IsKeyDown(KEY_DOWN)) {
    y -= GetFrameTime() * SPRITE_SPEED;
    nami.m_StateDir_ = Direction::kForward;
  } else if (IsKeyDown(KEY_UP)) {
    y += GetFrameTime() * SPRITE_SPEED;
    nami.m_StateDir_ = Direction::kBackward;
  } else {
    nami.m_InAnimation = false;
    return;
  }
  nami.m_InAnimation = true;
  return;
}

bool KeysPressedSimultaneously() {
  return IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP) ||
         IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN) ||
         IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP) ||
         IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN);
}
}  // namespace Logic