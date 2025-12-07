#include "assets.hpp"
#include "gameplay/gameplay.hpp"
#include "globals.hpp"
#include "main_menu/main_menu.hpp"
#include "pause/pause.hpp"
#include "raygui.h"

#include <cstdio>
#include <raylib.h>
#include <raymath.h>

int main() {
    printf("MAIN STARTED\n");

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    printf("FLAGS SET\n");
    fflush(stdout);

    InitWindow(800, 600, "RayShooter");
    InitAudioDevice();

    printf("WINDOW INIT\n");
    fflush(stdout);

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
            case GameState::MAINMENU:
                break;
            case GameState::GAMEPLAY:
                gameState = GameState::PAUSE;
                ShowCursor();
                break;
            case GameState::PAUSE:
                gameState = GameState::GAMEPLAY;
                HideCursor();
            }
        }

        switch (gameState) {
        case GameState::MAINMENU:
            break;

        case GameState::GAMEPLAY:
            gameplay.run();
            break;

        case GameState::PAUSE:
            break;
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        switch (gameState) {
        case GameState::MAINMENU:
            mainMenu.ui();
            break;

        case GameState::GAMEPLAY:
            gameplay.draw();
            break;

        case GameState::PAUSE:
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
