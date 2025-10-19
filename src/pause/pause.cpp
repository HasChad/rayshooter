#include "pause.hpp"
#include "globals.hpp"
#include "main_menu/main_menu.hpp"
#include "raygui.h"
#include "raylib.h"

void Pause::ui() {
    Vector2 boxSize = { 200, 100 };
    Rectangle boxRec{
        static_cast<float>(GetScreenWidth() / 2.0 - boxSize.x / 2.0),
        static_cast<float>(GetScreenHeight() / 2.0 - boxSize.y / 2.0),
        boxSize.x,
        boxSize.y,
    };

    GuiPanel(boxRec, NULL);

    // Draw text
    DrawText("Game Paused", boxRec.x + 35, boxRec.y + 5, 20, BLACK);

    // Vertical buttons
    Vector2 buttonSize = { 150, 25 };
    Rectangle playButton = { boxRec.x + 25, boxRec.y + 40, buttonSize.x, buttonSize.y };
    Rectangle quitButton = { boxRec.x + 25, boxRec.y + 70, buttonSize.x, buttonSize.y };

    if (GuiButton(playButton, "Resume")) {
        gameState = GAMEPLAY;
    }

    if (GuiButton(quitButton, "Quit")) {
        mainMenu.quit = true;
    }
}
