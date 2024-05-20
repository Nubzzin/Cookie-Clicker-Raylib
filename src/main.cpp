#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include <raylib.h>

#include "cookie.hpp"

int winWidth{900};
int winHight{700};

Cookie cookie;

bool open_menu = false;
int state_menu{};

int count_fazenda;
int count_loja;
int count_mina;
int count_foguete;
int count_end;

int main() {
  InitWindow(winWidth, winHight, "Cookie Clicker");

  Vector2 mousePos;

  cookie.position.x = GetScreenWidth() / 2.0;
  cookie.position.y = GetScreenHeight() / 2.0;

  while (!WindowShouldClose()) {
    // Updates
    mousePos = GetMousePosition();
    if (!open_menu)
      cookie.click(mousePos);
    cookie.ganhar_cookie();

    // Drawing
    BeginDrawing();
    ClearBackground(BLUE);

    cookie.Draw();

    DrawText(TextFormat("%.0f", cookie.cookies), GetScreenWidth() / 2 - 30, 40,
             80, WHITE);

    DrawText(TextFormat("CPS: %.3f", cookie.cookiesPS * 60),
             GetScreenWidth() / 2 - 80, 120, 30, WHITE);

    if (GuiButton((Rectangle){static_cast<float>(GetScreenWidth() / 2.0 - 90.0),
                              static_cast<float>(GetScreenHeight() - 80), 180,
                              60},
                  "#162#Instalações")) {
      open_menu = true;
    }

    // Menu

    if (open_menu) {
      state_menu = GuiWindowBox(
          (Rectangle){static_cast<float>(GetScreenWidth() / 2.0 - 250), 45, 500,
                      650},
          "#162#Instalações");

      GuiLabel((Rectangle){(float)GetScreenWidth() / 2, 43, 1000, 30},
               TextFormat("%.0f", cookie.cookies));

      // Buttons
      GuiLabel((Rectangle){(float)GetScreenWidth() / 2 - 230, 100, 1000, 30},
               TextFormat("%i", count_fazenda));
      GuiLabel((Rectangle){(float)GetScreenWidth() / 2, 100, 1000, 30},
               "Fazendas produzem: 0.06c/ps");
      if (GuiButton(
              (Rectangle){(float)GetScreenWidth() / 2 - 200, 100, 180, 30},
              "Fazenda de Cookies $100")) {
        if (cookie.cookies >= 100) {
          cookie.cookies -= 100;
          cookie.cookiesPS += 0.001;
          count_fazenda++;
        }
      }

      GuiLabel((Rectangle){(float)GetScreenWidth() / 2 - 230, 180, 1000, 30},
               TextFormat("%i", count_loja));
      GuiLabel((Rectangle){(float)GetScreenWidth() / 2, 180, 1000, 30},
               "Lojas produzem 6c/ps");
      if (GuiButton(
              (Rectangle){(float)GetScreenWidth() / 2 - 200, 180, 180, 30},
              "Loja de Cookies: $2.000")) {
        if (cookie.cookies >= 2000) {
          cookie.cookies -= 2000;
          cookie.cookiesPS += 0.1;
          count_loja++;
        }
      }

      GuiLabel((Rectangle){(float)GetScreenWidth() / 2 - 230, 260, 1000, 30},
               TextFormat("%i", count_mina));
      GuiLabel((Rectangle){(float)GetScreenWidth() / 2, 260, 1000, 30},
               "Minas produzem: 180c/ps");
      if (GuiButton(
              (Rectangle){(float)GetScreenWidth() / 2 - 200, 260, 180, 30},
              "Mina de Cookies $50.000")) {
        if (cookie.cookies >= 50000) {
          cookie.cookies -= 50000;
          cookie.cookiesPS += 3;
          count_mina++;
        }
      }

      GuiLabel((Rectangle){(float)GetScreenWidth() / 2 - 230, 340, 1000, 30},
               TextFormat("%i", count_foguete));
      GuiLabel((Rectangle){(float)GetScreenWidth() / 2, 340, 1000, 30},
               "Foguetes produzem: 12.000c/ps");
      if (GuiButton(
              (Rectangle){(float)GetScreenWidth() / 2 - 200, 340, 180, 30},
              "Foguete de Cookies $1.000.000")) {
        if (cookie.cookies >= 1000000) {
          cookie.cookies -= 100000;
          cookie.cookiesPS += 200;
          count_foguete++;
        }
      }

      GuiLabel((Rectangle){(float)GetScreenWidth() / 2 - 230, 420, 1000, 30},
               TextFormat("%i", count_end));
      GuiLabel((Rectangle){(float)GetScreenWidth() / 2, 420, 1000, 30},
               "#180# produzem: ∞c/ps");
      if (GuiButton(
              (Rectangle){(float)GetScreenWidth() / 2 - 200, 420, 180, 30},
              "#180# de Cookies $##############################")) {
        if (cookie.cookies >= 1'000'000'000) {
          cookie.cookies -= 1'000'000'000;
          cookie.cookiesPS += 10'000'000'000;
          count_end++;
        }
      }
      //
      if (state_menu > 0) {
        open_menu = false;
      }
    }
    //

    EndDrawing();

    // Debug
    // std::cout << mousePos.x << " - " << mousePos.y << std::endl;
    std::cout << cookie.cookies << std::endl;
  }

  CloseWindow();
}
