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
  if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    x += GetFrameSpeed(SPRITE_RUNNING_SPEED);
    Nami.SetDirection(Direction::kLeft, FRAME_ROW_TWO);
    Nami.Animation_ = AnimationState::kRunning;

  } else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    x -= GetFrameSpeed(SPRITE_RUNNING_SPEED);
    Nami.SetDirection(Direction::kRight, FRAME_ROW_THREE);
    Nami.Animation_ = AnimationState::kRunning;

  } else if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT_SHIFT)) {
    y -= GetFrameSpeed(SPRITE_RUNNING_SPEED);
    Nami.SetDirection(Direction::kBackward, FRAME_ROW_ONE);
    Nami.Animation_ = AnimationState::kRunning;

  } else if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT_SHIFT)) {
    y += GetFrameSpeed(SPRITE_RUNNING_SPEED);
    Nami.SetDirection(Direction::kForward, FRAME_ROW_FOUR);
    Nami.Animation_ = AnimationState::kRunning;
  }

  if (!IsKeyDown(KEY_LEFT_SHIFT)) {
    if (IsKeyDown(KEY_LEFT)) {
      x += GetFrameSpeed(SPRITE_WALKING_SPEED);
      Nami.SetDirection(Direction::kLeft, FRAME_ROW_TWO);
      Nami.Animation_ = AnimationState::kWalking;

    } else if (IsKeyDown(KEY_RIGHT)) {
      x -= GetFrameSpeed(SPRITE_WALKING_SPEED);
      Nami.SetDirection(Direction::kRight, FRAME_ROW_THREE);
      Nami.Animation_ = AnimationState::kWalking;

    } else if (IsKeyDown(KEY_DOWN)) {
      y -= GetFrameSpeed(SPRITE_WALKING_SPEED);
      Nami.SetDirection(Direction::kBackward, FRAME_ROW_ONE);
      Nami.Animation_ = AnimationState::kWalking;

    } else if (IsKeyDown(KEY_UP)) {
      y += GetFrameSpeed(SPRITE_WALKING_SPEED);
      Nami.SetDirection(Direction::kForward, FRAME_ROW_FOUR);
      Nami.Animation_ = AnimationState::kWalking;

    } else {
      Nami.SetInAnimation(false);
      return;
    }
  }

  Nami.SetInAnimation(true);
  return;
}

float GetFrameSpeed(const float &Speed) { return GetFrameTime() * Speed; }
}  // namespace Logic