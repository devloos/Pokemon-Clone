#include "Player.h"

PlayerTexture::PlayerTexture() {}
PlayerTexture::PlayerTexture(const std::string &Path) {
  Texture_ = LoadTexture(Path.c_str());
  FrameWidth_ = Texture_.width / 3.0f;
  FrameHeight_ = Texture_.height / 4.0f;
  MaxFrameCols_ = Texture_.width / (int)FrameWidth_;
}

Player::Player()
    : DirectionState_(Direction::kForward),
      inAnimation_(false),
      Animation_(AnimationState::kWalking),
      Zone_(PlayerZone::kFreeZone),
      PosX_(((640 / 2.0f) - 15)),
      PosY_((480 / 2.0f) - 20) {
  Textures_.emplace(
      AnimationState::kWalking, PlayerTexture("../assets/sprites/Nami-Walking.png"));
  Textures_[AnimationState::kWalking].RecWidth = 25.0f;
  Textures_[AnimationState::kWalking].RecHeight = 34.0f;

  Textures_.emplace(
      AnimationState::kRunning, PlayerTexture("../assets/sprites/Nami-Running.png"));
  Textures_[AnimationState::kRunning].RecWidth = 28.0f;
  Textures_[AnimationState::kRunning].RecHeight = 37.0f;
}

Player::~Player() {
  UnloadTexture(Textures_[AnimationState::kWalking].Texture_);
  UnloadTexture(Textures_[AnimationState::kRunning].Texture_);
}

void Player::Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION) {
  if (inAnimation_) {
    this->Logic();
  } else {
    Animation_ = AnimationState::kWalking;
    Textures_[Animation_].FrameCol_ = 1;
  }
  float frameCol = Textures_[Animation_].FrameWidth_ * Textures_[Animation_].FrameCol_;
  float frameRow = Textures_[Animation_].FrameHeight_ * Textures_[Animation_].FrameRow_;

  if (this->Zone_ == PlayerZone::kFreeZone) {
    DrawTextureTiled(
        Textures_[Animation_].Texture_,
        Rectangle{
            frameCol, frameRow, Textures_[Animation_].FrameWidth_,
            Textures_[Animation_].FrameHeight_},
        Rectangle{
            CENTER_X, CENTER_Y, Textures_[Animation_].RecWidth,
            Textures_[Animation_].RecHeight},
        Vector2{0, 0}, ROTATION, 1.3f, WHITE);
  } else {
    DrawTextureTiled(
        Textures_[Animation_].Texture_,
        Rectangle{
            frameCol, frameRow, Textures_[Animation_].FrameWidth_,
            Textures_[Animation_].FrameHeight_},
        Rectangle{
            this->PosX_, this->PosY_, Textures_[Animation_].RecWidth,
            Textures_[Animation_].RecHeight},
        Vector2{0, 0}, ROTATION, 1.3f, WHITE);
  }
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

void Player::SetPlayerZone(const PlayerZone &zone) { this->Zone_ = zone; }

PlayerZone Player::GetPlayerZone() const { return this->Zone_; }
