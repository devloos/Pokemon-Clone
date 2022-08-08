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

  Direction DirectionState_;
  Texture2D SpriteWalking_;
  bool inAnimation_;

 private:
  // TODO: Clean Up variable names?
  float timer_;
  int frame_;
  float height_;
  float frameWidth_;
  float frameHeight_;
  int maxFrames_;
};

#endif  // NAMI_H_