#ifndef LOGIC_H_
#define LOGIC_H_
#include <raylib.h>

#include "../sprites/Player.h"
namespace Logic {
const float SPRITE_WALKING_SPEED = 100.0f;
const float SPRITE_RUNNING_SPEED = 150.0f;
const float FRAME_ROW_ONE = 0.0f;
const float FRAME_ROW_TWO = 1.0f;
const float FRAME_ROW_THREE = 3.0f;
const float FRAME_ROW_FOUR = 2.0f;
/**
 * @brief
 *
 * @param x
 * @param y
 */
void Start(float &x, float &y, Player &Nami);

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool KeysPressedSimultaneously();

/**
 * @brief
 *
 * @param x
 * @param y
 * @param Nami
 * @param Speed
 */
void Movement(float &x, float &y, Player &Nami);

/**
 * @brief Get the Frame Speed object
 *
 * @param Speed
 * @return float
 */
float GetFrameSpeed(const float &Speed);

/**
 * @brief Set the Frame Animation object
 *
 * @param Nami
 * @param dir
 * @param frameRow
 * @param animationState
 */
void SetFrameAnimation(
    Player &Nami, const Direction &dir, const float &frameRow,
    const AnimationState &animationState);
}  // namespace Logic

#endif  // LOGIC_H_