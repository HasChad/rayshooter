#include "main_menu.h"
#include "globals.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void MainMenu::ui() {
    Vector2 boxSize = { 250, 150 };
    Rectangle boxRec{
        static_cast<float>(GetScreenWidth() / 2.0 - boxSize.x / 2.0),
        static_cast<float>(GetScreenHeight() / 2.0 - boxSize.y / 2.0),
        boxSize.x,
        boxSize.y,
    };

    // GuiWindowBox(boxRec, "window box");
    // GuiGroupBox(boxRec, "group box");
    GuiPanel(boxRec, "");
    // GuiLine(boxRec, "line");

    // Draw text
    DrawText("RayShooter", boxRec.x + 65, boxRec.y + 40, 20, BLACK);

    // Vertical buttons
    Rectangle playButton = { boxRec.x + 50, boxRec.y + 80, 150, 25 };
    Rectangle quitButton = { boxRec.x + 50, boxRec.y + 110, 150, 25 };

    if (GuiButton(playButton, "Play")) {
        gameState = GAMEPLAY;
        HideCursor();
    }

    if (GuiButton(quitButton, "Quit")) {
        quit = true;
    }
}
