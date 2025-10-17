#include "assets.hpp"
#include "gameplay/gameplay.hpp"
#include "globals.hpp"
#include "main_menu/main_menu.hpp"
#include "pause/pause.hpp"
#include "raygui.h"

#include <raylib.h>
#include <raymath.h>

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "RayShooter");
    InitAudioDevice();
    SetTargetFPS(60);
    SetWindowIcon(LoadImage("sprites/icon.png"));

    SetExitKey(0);

    loadAssets();

    SetMasterVolume(0.3);
    PlayMusicStream(sounds.wood_ambiance);
    PlayMusicStream(sounds.walk_forest);

    while (!mainMenu.quit) {

        mainMenu.quit = WindowShouldClose();

        if (IsKeyPressed(KEY_ESCAPE)) {
            switch (gameState) {
            case MAINMENU:
                break;
            case GAMEPLAY:
                gameState = PAUSE;
                ShowCursor();
                break;
            case PAUSE:
                gameState = GAMEPLAY;
                HideCursor();
            }
        }

        switch (gameState) {
        case MAINMENU:
            break;

        case GAMEPLAY:
            gameplay.run();
            break;

        case PAUSE:
            break;
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        switch (gameState) {
        case MAINMENU:
            mainMenu.ui();
            break;

        case GAMEPLAY:
            gameplay.draw();
            break;

        case PAUSE:
            gameplay.draw();
            pause.ui();
            break;
        }

        EndDrawing();
    }

    StopMusicStream(sounds.wood_ambiance);
    StopMusicStream(sounds.walk_forest);
    CloseAudioDevice();
    CloseWindow();
}
