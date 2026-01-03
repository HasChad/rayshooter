#include "main_menu.hpp"
#include "globals.hpp"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void MainMenu::ui() {
    Vector2 boxSize = { 250, 100 };
    Rectangle boxRec{
        static_cast<float>(GetScreenWidth() / 2.0 - boxSize.x / 2.0),
        static_cast<float>(GetScreenHeight() / 2.0 - boxSize.y / 2.0),
        boxSize.x,
        boxSize.y,
    };

    GuiPanel(boxRec, NULL);

    // Draw text
    const char* text = TextFormat("RayShooter");
    int textSize = MeasureText(text, 20);
    DrawText(text, boxRec.x + boxRec.width / 2.0 - textSize / 2.0, boxRec.y + 10, 20, BLACK);

    // Vertical buttons
    Rectangle playButton = { boxRec.x + 50, boxRec.y + 40, 150, 25 };
    Rectangle quitButton = { boxRec.x + 50, boxRec.y + 70, 150, 25 };

    if (GuiButton(playButton, "Play")) {
        HideCursor();
        gameState = GameState::GAMEPLAY;
    }

    if (GuiButton(quitButton, "Quit")) {
        game.run = false;
    }
}
