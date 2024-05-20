#include <iostream>
#include <raylib.h>

#include "cookie.hpp"

int winWidth{800};
int winHight{600};

Cookie cookie;

int main() {
  InitWindow(winWidth, winHight, "Cookie Clicker");

  Vector2 mousePos;

  cookie.position.x = GetScreenWidth() / 2.0;
  cookie.position.y = GetScreenHeight() / 2.0;

  while (!WindowShouldClose()) {
    // Updates
    mousePos = GetMousePosition();
    cookie.click(mousePos);

    // Drawing
    BeginDrawing();
    ClearBackground(BLUE);

    cookie.Draw();
    DrawText(TextFormat("%i", cookie.cookies), GetScreenWidth() / 2 - 22, 40,
             80, WHITE);

    EndDrawing();

    // Debug
    // std::cout << mousePos.x << " - " << mousePos.y << std::endl;
    std::cout << cookie.cookies << std::endl;
  }

  CloseWindow();
}
