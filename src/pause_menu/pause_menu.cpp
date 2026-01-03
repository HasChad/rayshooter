#include "pause_menu.hpp"
#include "globals.hpp"
#include "raygui.h"
#include "raylib.h"

void PauseMenu::ui() {
    Vector2 boxSize = { 200, 100 };
    Rectangle boxRec{
        static_cast<float>(GetScreenWidth() / 2.0 - boxSize.x / 2.0),
        static_cast<float>(GetScreenHeight() / 2.0 - boxSize.y / 2.0),
        boxSize.x,
        boxSize.y,
    };

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorAlpha(BLACK, 0.5));
    GuiPanel(boxRec, NULL);

    // Draw text
    const char* text = TextFormat("Game Paused");
    int textSize = MeasureText(text, 20);
    DrawText(text, boxRec.x + boxRec.width / 2.0 - textSize / 2.0, boxRec.y + 10, 20, BLACK);

    // Vertical buttons
    Vector2 buttonSize = { 150, 25 };
    Rectangle playButton = { boxRec.x + 25, boxRec.y + 40, buttonSize.x, buttonSize.y };
    Rectangle quitButton = { boxRec.x + 25, boxRec.y + 70, buttonSize.x, buttonSize.y };

    if (GuiButton(playButton, "Resume") || IsKeyPressed(KEY_ESCAPE)) {
        HideCursor();
        gameState = GameState::GAMEPLAY;
    }

    if (GuiButton(quitButton, "Quit")) {
        game.run = false;
    }
}
