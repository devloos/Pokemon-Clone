#include "Sprite.h"

Sprite::Sprite()
    : DirectionState_(Direction::kForward),
      SpriteWalking_(LoadTexture("../assets/sprites/NamiWalkingState.png")),
      inAnimation_(false) {
  FrameWidth_ = SpriteWalking_.width / 3.0f;
  FrameHeight_ = SpriteWalking_.height / 4.0f;
  MaxFrameCols_ = SpriteWalking_.width / (int)FrameWidth_;
}

Sprite::~Sprite() { UnloadTexture(SpriteWalking_); }

void Sprite::Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION) {
  if (inAnimation_) {
    this->Logic();
  } else {
    FrameCol_ = 1;
  }
  DrawTextureTiled(
      SpriteWalking_,
      Rectangle{
          (FrameWidth_ * FrameCol_), (FrameHeight_ * FrameRow_), FrameWidth_,
          FrameHeight_},
      Rectangle{CENTER_X, CENTER_Y, 25, 34}, Vector2{0, 0}, ROTATION, 1.3f, WHITE);
}

void Sprite::Logic() {
  // ===============================
  TimePerFrame_ += GetFrameTime();
  if (TimePerFrame_ >= 0.2f) {
    TimePerFrame_ = 0.0f;
    FrameCol_ += 1;
  }
  FrameCol_ %= MaxFrameCols_;
  // ===============================
}

void Sprite::SetDirection(const Direction &dir, const float &FrameRow) {
  DirectionState_ = dir;
  FrameRow_ = FrameRow;
}

void Sprite::SetInAnimation(const bool &inAnimation) { inAnimation_ = inAnimation; }
