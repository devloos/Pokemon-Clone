#include "Sprite.h"

Sprite::Sprite()
    : DirectionState_(Direction::kForward),
      SpriteWalking_(LoadTexture("../assets/sprites/NamiWalkingState.png")),
      inAnimation_(false) {
  frameWidth_ = SpriteWalking_.width / 3.0f;
  frameHeight_ = SpriteWalking_.height / 3.9f;
  maxFrames_ = SpriteWalking_.width / (int)frameWidth_;
}

Sprite::~Sprite() { UnloadTexture(SpriteWalking_); }

void Sprite::Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION) {
  if (inAnimation_) {
    this->Logic();
  } else {
    frame_ = 1;
  }
  DrawTextureTiled(
      SpriteWalking_,
      Rectangle{(frameWidth_ * frame_), height_, frameWidth_, frameHeight_},
      Rectangle{CENTER_X, CENTER_Y, 25, 34}, Vector2{0, 0}, ROTATION, 1.3f, WHITE);
}

void Sprite::Logic() {
  // ===============================
  timer_ += GetFrameTime();
  if (timer_ >= 0.2f) {
    timer_ = 0.0f;
    frame_ += 1;
  }
  frame_ %= maxFrames_;
  // ===============================

  height_ = (frameHeight_ * FrameRow_);
}

void Sprite::SetDirection(const Direction &dir, const float &FrameRow) {
  DirectionState_ = dir;
  FrameRow_ = FrameRow;
}

void Sprite::SetInAnimation(const bool &inAnimation) { inAnimation_ = inAnimation; }
