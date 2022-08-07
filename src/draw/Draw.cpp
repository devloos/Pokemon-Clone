#include "Draw.h"

namespace Draw {
void Start(Texture2D &SafariMap, Texture2D &Nami, const float &x, const float &y) {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  DrawTextureEx(SafariMap, Vector2{x, y}, ROTATION, SCALE, WHITE);
  DrawTextureTiled(
      Nami, Rectangle{24, 5, 20, 29}, Rectangle{CENTER_X, CENTER_Y, 27, 34},
      Vector2{0, 0}, ROTATION, 1.3f, WHITE);

  EndDrawing();
}
}  // namespace Draw