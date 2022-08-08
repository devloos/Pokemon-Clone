#include "Sprite.h"

Sprite::Sprite() {
  m_StateDir_ = Direction::kForward;
  NamiWalkingSheet_ = LoadTexture("../assets/sprites/NamiWalkingState.png");

  frameWidth_ = NamiWalkingSheet_.width / 3.0f;
  frameHeight_ = NamiWalkingSheet_.height / 4.0f;
  maxFrames_ = NamiWalkingSheet_.width / (int)frameWidth_;
}

Sprite::~Sprite() { UnloadTexture(NamiWalkingSheet_); }

void Sprite::Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION) {
  this->Logic();
  DrawTextureTiled(
      NamiWalkingSheet_,
      Rectangle{(frameWidth_ * frame_), height_, (frameWidth_), (frameHeight_)},
      Rectangle{CENTER_X - 2, CENTER_Y, 24, 34}, Vector2{0, 0}, ROTATION, 1.3f, WHITE);
}

void Sprite::Logic() {
  // ===============================
  timer_ += GetFrameTime();
  if (timer_ >= 0.2f) {
    timer_ = 0.0f;
    frame_ += 1;
  }
  frame_ = frame_ % maxFrames_;
  // ===============================

  switch (this->m_StateDir_) {
    case Direction::kForward: {
      height_ = (frameHeight_ * 0.0f);
      break;
    }
    case Direction::kBackward: {
      height_ = (frameHeight_ * 2.0f);
      break;
    }
    case Direction::kLeft: {
      height_ = (frameHeight_ * 1.0f);
      break;
    }
    case Direction::kRight: {
      height_ = (frameHeight_ * 3.0f);
      break;
    }
    default: {
      height_ = (frameHeight_ * 0.0f);
      break;
    }
  }
}
