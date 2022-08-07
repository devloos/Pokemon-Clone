#include "Logic.h"

namespace Logic {
void Start(float &x, float &y) {
  if (IsKeyDown(KEY_LEFT)) x += GetFrameTime() * 100.0f;
  if (IsKeyDown(KEY_RIGHT)) x -= GetFrameTime() * 100.0f;
  if (IsKeyDown(KEY_DOWN)) y -= GetFrameTime() * 100.0f;
  if (IsKeyDown(KEY_UP)) y += GetFrameTime() * 100.0f;
}
}  // namespace Logic