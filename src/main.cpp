#include "assets.h"
#include "gameplay/gameplay.h"
#include "globals.h"
#include "main_menu/main_menu.h"
#include "pause/pause.h"
#include "raygui.h"

#include <raylib.h>
#include <raymath.h>

int main() {
    InitWindow(screen.width, screen.height, "RayShooter");
    InitAudioDevice();
    SetTargetFPS(60);
    SetWindowIcon(LoadImage("sprites/icon.png"));
    // HideCursor();

    loadAssets();

    SetMasterVolume(0.3);
    PlayMusicStream(sounds.wood_ambiance);
    PlayMusicStream(sounds.walk_forest);

    while (!mainMenu.quit) {
        mainMenu.quit = WindowShouldClose();
        if (IsKeyPressed(KEY_TAB)) {
            switch (gameState) {
            case MAINMENU:
                break;
            case GAMEPLAY:
                gameState = PAUSE;
                break;
            case PAUSE:
                gameState = GAMEPLAY;
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
