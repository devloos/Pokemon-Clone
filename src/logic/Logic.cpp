#include "Logic.h"

namespace Logic {
void Start(float &x, float &y, Player &Nami) {
  if (x >= -3.0f) {
    Nami.SetPlayerZone(PlayerZone::kZoneLeft);
    x = -3.0f;
  }

  if (Nami.PosX_ > 302.0f) {
    Nami.SetPlayerZone(PlayerZone::kFreeZone);
    Nami.PosX_ = 302.0f;
  }

  if (x <= -3574.0f) {
    Nami.SetPlayerZone(PlayerZone::kZoneRight);
    x = -3574.0f;
  }

  if (Nami.PosX_ < 302.0f) {
    Nami.SetPlayerZone(PlayerZone::kFreeZone);
    Nami.PosX_ = 302.0f;
  }

  if (y >= -3.0f) {
    Nami.SetPlayerZone(PlayerZone::kZoneTop);
    y = -3.0f;
  }

  if (Nami.PosY_ > 220.0f) {
    Nami.SetPlayerZone(PlayerZone::kFreeZone);
    Nami.PosY_ = 220.0f;
  }

  if (y <= -2333.0f) {
    Nami.SetPlayerZone(PlayerZone::kZoneBottom);
    y = -2333.0f;
  }

  if (Nami.PosY_ < 220.0f) {
    Nami.SetPlayerZone(PlayerZone::kFreeZone);
    Nami.PosY_ = 220.0f;
  }

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
  switch (Nami.GetPlayerZone()) {
    case PlayerZone::kFreeZone: {
      if (IsRunning(x, y, Nami)) {
        return;
      }
      if (IsWalking(x, y, Nami)) {
        return;
      }
      break;
    }
    case PlayerZone::kZoneLeft:
    case PlayerZone::kZoneRight: {
      if (IsPlayerRunning(y, Nami)) {
        return;
      }
      if (IsPlayerWalking(y, Nami)) {
        return;
      }
      break;
    }
    case PlayerZone::kZoneTop:
    case PlayerZone::kZoneBottom: {
      if (IsPlayerRunningY(x, Nami)) {
        return;
      }
      if (IsPlayerWalkingY(x, Nami)) {
        return;
      }
      break;
    }
  }
  Nami.SetInAnimation(false);
  return;
  // this is a comment
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

bool IsPlayerRunning(float &y, Player &Nami) {
  if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    Nami.PosX_ -= GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(Nami, Direction::kLeft, FRAME_ROW_TWO, AnimationState::kRunning);

  } else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    Nami.PosX_ += GetFrameSpeed(SPRITE_RUNNING_SPEED);
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

bool IsPlayerWalking(float &y, Player &Nami) {
  if (IsKeyDown(KEY_LEFT)) {
    Nami.PosX_ -= GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(Nami, Direction::kLeft, FRAME_ROW_TWO, AnimationState::kWalking);

  } else if (IsKeyDown(KEY_RIGHT)) {
    Nami.PosX_ += GetFrameSpeed(SPRITE_WALKING_SPEED);
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

bool IsPlayerRunningY(float &x, Player &Nami) {
  if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    x += GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(Nami, Direction::kLeft, FRAME_ROW_TWO, AnimationState::kRunning);

  } else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT_SHIFT)) {
    x -= GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(Nami, Direction::kRight, FRAME_ROW_THREE, AnimationState::kRunning);

  } else if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT_SHIFT)) {
    Nami.PosY_ += GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kBackward, FRAME_ROW_ONE, AnimationState::kRunning);

  } else if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT_SHIFT)) {
    Nami.PosY_ -= GetFrameSpeed(SPRITE_RUNNING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kForward, FRAME_ROW_FOUR, AnimationState::kRunning);
  } else {
    return false;
  }

  return true;
}

bool IsPlayerWalkingY(float &x, Player &Nami) {
  if (IsKeyDown(KEY_LEFT)) {
    x += GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(Nami, Direction::kLeft, FRAME_ROW_TWO, AnimationState::kWalking);

  } else if (IsKeyDown(KEY_RIGHT)) {
    x -= GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(Nami, Direction::kRight, FRAME_ROW_THREE, AnimationState::kWalking);

  } else if (IsKeyDown(KEY_DOWN)) {
    Nami.PosY_ += GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kBackward, FRAME_ROW_ONE, AnimationState::kWalking);

  } else if (IsKeyDown(KEY_UP)) {
    Nami.PosY_ -= GetFrameSpeed(SPRITE_WALKING_SPEED);
    SetFrameAnimation(
        Nami, Direction::kForward, FRAME_ROW_FOUR, AnimationState::kWalking);

  } else {
    return false;
  }

  return true;
}
}  // namespace Logic