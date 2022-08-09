#ifndef LOGIC_H_
#define LOGIC_H_
#include <raylib.h>

#include "../sprite/Sprite.h"
namespace Logic {
const float SPRITE_SPEED = 100.0f;
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
void Start(float &x, float &y, Sprite &nami);

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
 * @param nami
 */
void Movement(float &x, float &y, Sprite &nami);
}  // namespace Logic

#endif  // LOGIC_H_