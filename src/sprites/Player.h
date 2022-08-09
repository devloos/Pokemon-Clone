#ifndef SPRITE_H_
#define SPRITE_H_

#include <raylib.h>

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

enum struct Direction { kForward, kBackward, kLeft, kRight };
enum struct AnimationState { kWalking = 0, kRunning };

struct PlayerTexture {
  PlayerTexture();
  PlayerTexture(const std::string &Path);

  Texture2D Texture_;
  float FrameRow_;
  float FrameWidth_;
  float FrameHeight_;
  int FrameCol_;
  int MaxFrameCols_;
  float RecWidth;
  float RecHeight;
};

class Player {
 public:
  /**
   * @brief Construct a new Player object
   *
   */
  Player();

  /**
   * @brief Destroy the Player object
   *
   */
  ~Player();

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
  void SetDirection(const Direction &dir, const float &FrameRow);

  /**
   * @brief Set the In Animation object
   *
   * @param inAnimation
   */
  void SetInAnimation(const bool &inAnimation);

 private:
  std::unordered_map<AnimationState, PlayerTexture> Textures_;
  Direction DirectionState_;
  float TimePerFrame_;

 public:
  AnimationState Animation_;
  bool inAnimation_;
};

#endif  // SPRITE_H_