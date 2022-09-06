#include "Logic.h"

namespace Logic {
void Start(float &x, float &y, Player &Nami) {
  if (KeysPressedSimultaneously()) {
    Nami.SetInAnimation(false);
    return;
  }
  Movement(x, y, Nami);
}

bool KeysPressedSimultaneously() {
  auto TwoKeysPressed = [](const int &KEY_1, const int &KEY_2) {
    return IsKeyDown(KEY_1) && IsKeyDown(KEY_2);
  };

  return TwoKeysPressed(KEY_LEFT, KEY_UP) || TwoKeysPressed(KEY_LEFT, KEY_DOWN) ||
         TwoKeysPressed(KEY_RIGHT, KEY_UP) || TwoKeysPressed(KEY_RIGHT, KEY_DOWN);
}

void Movement(float &x, float &y, Player &Nami) {
  if (IsRunning(x, y, Nami)) {
    return;
  }
  if (IsWalking(x, y, Nami)) {
    return;
  }
  Nami.SetInAnimation(false);
  return;
}

void SetFrameAnimation(
    Player &Nami, const Direction &dir, const float &frameRow,
    const AnimationState &animationState) {
  Nami.SetDirection(dir, frameRow);
  Nami.Animation_ = animationState;
  Nami.SetInAnimation(true);
}

float GetFrameSpeed(const float &Speed) { return GetFrameTime() * Speed; }

bool IsRunning(float &x, float &y, Player &Nami) {
  if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    x += GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(Nami, Direction::kLeft, FRAME_ROW_TWO, AnimationState::kRunning);

  } else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    x -= GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(Nami, Direction::kRight, FRAME_ROW_THREE, AnimationState::kRunning);

  } else if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT_SHIFT)) {
    y -= GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kBackward, FRAME_ROW_ONE, AnimationState::kRunning);

  } else if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT_SHIFT)) {
    y += GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kForward, FRAME_ROW_FOUR, AnimationState::kRunning);
  } else {
    return false;
  }

  return true;
}

bool IsWalking(float &x, float &y, Player &Nami) {
  if (IsKeyDown(KEY_LEFT)) {
    x += GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(Nami, Direction::kLeft, FRAME_ROW_TWO, AnimationState::kWalking);

  } else if (IsKeyDown(KEY_RIGHT)) {
    x -= GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(Nami, Direction::kRight, FRAME_ROW_THREE, AnimationState::kWalking);

  } else if (IsKeyDown(KEY_DOWN)) {
    y -= GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kBackward, FRAME_ROW_ONE, AnimationState::kWalking);

  } else if (IsKeyDown(KEY_UP)) {
    y += GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kForward, FRAME_ROW_FOUR, AnimationState::kWalking);

  } else {
    return false;
  }

  return true;
}
}  // namespace Logic