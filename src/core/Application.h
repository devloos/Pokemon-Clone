#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <raylib.h>

#include <iostream>

#include "../draw/Draw.h"
#include "../logic/Logic.h"
#include "../sprite/Sprite.h"

namespace Application {
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;
const float START_X = -800;
const float START_Y = -1500;
/**
 * @brief
 *
 */
void Start();

/**
 * @brief
 *
 */
void Finish();
}  // namespace Application

#endif  // APPLICATION_H_