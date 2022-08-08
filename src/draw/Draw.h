#ifndef DRAW_H_
#define DRAW_H_
#include <raylib.h>

#include "../sprite/Sprite.h"

namespace Draw {
const float ROTATION = 0.0f;
const float SCALE = 2.2f;
const float CENTER_X = (640 / 2.0f) - 15;
const float CENTER_Y = (480 / 2.0f) - 20;

void Start(Texture2D &SafariMap, const float &x, const float &y, Sprite &nami);
}  // namespace Draw

#endif  // DRAW_H_