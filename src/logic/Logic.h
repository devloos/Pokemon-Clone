#ifndef LOGIC_H_
#define LOGIC_H_
#include <raylib.h>

#include "../sprite/Sprite.h"
namespace Logic {
const float SPRITE_SPEED = 100.0f;
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
}  // namespace Logic

#endif  // LOGIC_H_