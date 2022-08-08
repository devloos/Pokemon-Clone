#ifndef SPRITE_H_
#define SPRITE_H_

#include <raylib.h>

#include <iostream>

enum struct Direction { kForward, kBackward, kLeft, kRight };

class Sprite {
 public:
  Sprite();
  ~Sprite();
  void Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION);
  void Logic();

  // Setters
  /**
   * @brief Set the Direction State object
   *
   * @param dir
   */
  void SetDirectionState(const Direction &dir);

  void SetInAnimation(const bool &inAnimation);

  Texture2D SpriteWalking_;

 private:
  Direction DirectionState_;
  bool inAnimation_;
  // TODO: Clean Up variable names?
  float timer_;
  int frame_;
  float height_;
  float frameWidth_;
  float frameHeight_;
  int maxFrames_;
};

#endif  // SPRITE_H_