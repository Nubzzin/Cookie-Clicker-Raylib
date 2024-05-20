#pragma once

#include <raylib.h>

class Cookie {
public:
  float size{140};
  Vector2 position{};

  float cookies{};
  float cookiesPS{};

  void Draw() {
    if (size < 140)
      size += 0.01;
    DrawCircle(position.x, position.y, size + 10, DARKBROWN);
    DrawCircle(position.x, position.y, size, BROWN);
    DrawCircle(position.x - 20 + size, position.y - 50 + size, 20, DARKBROWN);
    DrawCircle(position.x + 100 - size, position.y + 60 - size, 16, DARKBROWN);
    DrawCircle(position.x - 30 + size, position.y + 30 - size, 8, DARKBROWN);
    DrawCircle(position.x + 10 - size, position.y - 70 + size, 12, DARKBROWN);
  }

  void click(Vector2 mousePos) {
    if (CheckCollisionPointCircle(mousePos, position, size)) {
      if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) ||
          IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        cookies++;
        size = 120;
      }
    }
  }

  void ganhar_cookie() { cookies += cookiesPS; }
};
