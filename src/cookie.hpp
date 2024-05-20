#pragma once

#include <raylib.h>

class Cookie {
public:
  int size{140};
  Vector2 position{};

  int cookies;

  void Draw() { DrawCircle(position.x, position.y, size, BROWN); }

  void click(Vector2 mousePos) {
    if (CheckCollisionPointCircle(mousePos, position, size)) {
      if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) ||
          IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        cookies++;
      }
    }
  }
};
