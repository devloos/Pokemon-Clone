#include "Logic.h"

namespace Logic {
void Start(float &x, float &y, Sprite &nami) {
  if (KeysPressedSimultaneously()) {
    nami.SetInAnimation(false);
    return;
  }
  Movement(x, y, nami);
}

bool KeysPressedSimultaneously() {
  auto TwoKeysPressed = [](const int &KEY_1, const int &KEY_2) {
    return IsKeyDown(KEY_1) && IsKeyDown(KEY_2);
  };

  return TwoKeysPressed(KEY_LEFT, KEY_UP) || TwoKeysPressed(KEY_LEFT, KEY_DOWN) ||
         TwoKeysPressed(KEY_RIGHT, KEY_UP) || TwoKeysPressed(KEY_RIGHT, KEY_DOWN);
}

void Movement(float &x, float &y, Sprite &nami) {
  if (IsKeyDown(KEY_LEFT)) {
    x += GetFrameTime() * SPRITE_SPEED;
    nami.SetDirectionState(Direction::kLeft);

  } else if (IsKeyDown(KEY_RIGHT)) {
    x -= GetFrameTime() * SPRITE_SPEED;
    nami.SetDirectionState(Direction::kRight);

  } else if (IsKeyDown(KEY_DOWN)) {
    y -= GetFrameTime() * SPRITE_SPEED;
    nami.SetDirectionState(Direction::kBackward);

  } else if (IsKeyDown(KEY_UP)) {
    y += GetFrameTime() * SPRITE_SPEED;
    nami.SetDirectionState(Direction::kForward);

  } else {
    nami.SetInAnimation(false);
    return;
  }

  nami.SetInAnimation(true);
  return;
}
}  // namespace Logic