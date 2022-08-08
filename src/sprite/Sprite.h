#ifndef NAMI_H_
#define NAMI_H_

#include <raylib.h>

#include <iostream>

enum struct Direction { kForward, kBackward, kLeft, kRight };

class Sprite {
 public:
  Sprite()
      : m_StateDir_(Direction::kForward),
        NamiWalkingSheet_(LoadTexture("../assets/sprites/NamiWalkingState.png")),
        m_InAnimation(false) {
    frameWidth_ = NamiWalkingSheet_.width / 3.0f;
    frameHeight_ = NamiWalkingSheet_.height / 4.0f;
    maxFrames_ = NamiWalkingSheet_.width / (int)frameWidth_;
  }
  ~Sprite();
  void Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION);
  void Logic();

  Direction m_StateDir_;
  Texture2D NamiWalkingSheet_;
  bool m_InAnimation;

 private:
  float timer_;
  int frame_;
  float frameWidth_;
  float height_;
  float frameHeight_;
  int maxFrames_;
};

#endif  // NAMI_H_