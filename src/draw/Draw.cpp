#include "Draw.h"

#include <iostream>

namespace Draw {
void Start(Texture2D &SafariMap, const float &x, const float &y, Player &Nami) {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  DrawTextureEx(SafariMap, Vector2{x, y}, ROTATION, SCALE, WHITE);
  Nami.Draw(CENTER_X, CENTER_Y, ROTATION);
  EndDrawing();
  std::cout << "X: " << x << " Y: " << y << "\n";
  std::cout << "Player X: " << Nami.PosX_ << " Player Y: " << Nami.PosY_ << "\n";
}
}  // namespace Draw