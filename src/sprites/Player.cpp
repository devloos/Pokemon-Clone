#include "Player.h"

PlayerTexture::PlayerTexture(const std::string &Path) {
  Texture_ = LoadTexture(Path.c_str());
  FrameWidth_ = Texture_.width / 3.0f;
  FrameHeight_ = Texture_.height / 4.0f;
  MaxFrameCols_ = Texture_.width / (int)FrameWidth_;
}

Player::Player()
    : DirectionState_(Direction::kForward),
      inAnimation_(false),
      Animation_(AnimationState::kWalking) {
  Textures_[AnimationState::kWalking] = std::string("../assets/sprites/Nami-Walking.png");
  Textures_[AnimationState::kRunning] = std::string("../assets/sprites/Nami-Running.png");
}

Player::~Player() {
  UnloadTexture(Textures_[AnimationState::kWalking].Texture_);
  UnloadTexture(Textures_[AnimationState::kRunning].Texture_);
}

void Player::Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION) {
  if (inAnimation_) {
    this->Logic();
  } else {
    Textures_[Animation_].FrameCol_ = 1;
  }
  DrawTextureTiled(
      Textures_[Animation_].Texture_,
      Rectangle{
          (Textures_[Animation_].FrameWidth_ * Textures_[Animation_].FrameCol_),
          (Textures_[Animation_].FrameHeight_ * Textures_[Animation_].FrameRow_),
          Textures_[Animation_].FrameWidth_, Textures_[Animation_].FrameHeight_},
      Rectangle{CENTER_X, CENTER_Y, 25, 34}, Vector2{0, 0}, ROTATION, 1.3f, WHITE);
}

void Player::Logic() {
  // ===============================
  TimePerFrame_ += GetFrameTime();
  if (TimePerFrame_ >= 0.2f) {
    TimePerFrame_ = 0.0f;
    Textures_[Animation_].FrameCol_ += 1;
  }
  Textures_[Animation_].FrameCol_ %= Textures_[Animation_].MaxFrameCols_;
  // ===============================
}

void Player::SetDirection(const Direction &dir, const float &FrameRow) {
  DirectionState_ = dir;
  Textures_[Animation_].FrameRow_ = FrameRow;
}

void Player::SetInAnimation(const bool &inAnimation) { inAnimation_ = inAnimation; }
