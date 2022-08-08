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
  auto TwoKeysPressed = [](const int &KEY_1, const int &KEY_2) {
    return IsKeyDown(KEY_1) && IsKeyDown(KEY_2);
  };

  return TwoKeysPressed(KEY_LEFT, KEY_UP) || TwoKeysPressed(KEY_LEFT, KEY_DOWN) ||
         TwoKeysPressed(KEY_RIGHT, KEY_UP) || TwoKeysPressed(KEY_RIGHT, KEY_DOWN);
}
}  // namespace Logic