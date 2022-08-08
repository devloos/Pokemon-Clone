#ifndef NAMI_H_
#define NAMI_H_

#include <raylib.h>

#include <iostream>

enum struct Direction { kForward, kBackward, kLeft, kRight };

class Sprite {
 public:
  Sprite();
  ~Sprite();
  void Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION);
  void Logic();

  Direction m_StateDir_;
  Texture2D NamiWalkingSheet_;
  bool m_InAnimation;

 private:
  float height_;
  float timer_;
  float frameWidth_;
  float frameHeight_;
  int maxFrames_;
  int frame_;
};

#endif  // NAMI_H_