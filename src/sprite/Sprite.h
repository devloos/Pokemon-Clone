#ifndef SPRITE_H_
#define SPRITE_H_

#include <raylib.h>

#include <iostream>

enum struct Direction { kForward, kBackward, kLeft, kRight };

class Sprite {
 public:
  /**
   * @brief Construct a new Sprite object
   *
   */
  Sprite();

  /**
   * @brief Destroy the Sprite object
   *
   */
  ~Sprite();

  /**
   * @brief
   *
   * @param CENTER_X
   * @param CENTER_Y
   * @param ROTATION
   */
  void Draw(const float &CENTER_X, const float &CENTER_Y, const float &ROTATION);

  /**
   * @brief
   *
   */
  void Logic();

  // Setters
  /**
   * @brief Set the Direction State object
   *
   * @param dir
   */
  void SetDirectionState(const Direction &dir);

  /**
   * @brief Set the In Animation object
   *
   * @param inAnimation
   */
  void SetInAnimation(const bool &inAnimation);

 private:
  Texture2D SpriteWalking_;
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