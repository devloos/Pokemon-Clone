#ifndef NAMI_H_
#define NAMI_H_

#include <raylib.h>

enum struct Direction { kForward, kBackward, kLeft, kRight };

class Nami {
 public:
  Nami();
  ~Nami();
  void DrawNami(
      Texture2D &SafariMap, Texture2D &NamiWalkingState, const float &x, const float &y,
      float &frameWidth, float &timer, int &maxFrames, int &frame, int &frameHeight);

  Direction m_StateDir_;
  bool m_InAnimation;
};

#endif  // NAMI_H_