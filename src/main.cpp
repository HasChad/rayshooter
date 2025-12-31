#include "assets.hpp"
#include "gameplay/camera.hpp"
#include "gameplay/gameplay.hpp"
#include "globals.hpp"
#include "main_menu/main_menu.hpp"
#include "pause_menu/pause_menu.hpp"
#include "raygui.h"
#include <raylib.h>
#include <raymath.h>

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(800, 600, "RayShooter");
    InitAudioDevice();
    SetTargetFPS(60);
    SetWindowIcon(LoadImage("sprites/icon.png"));
    SetExitKey(0);

    loadAssets();
    gameCamera.init();

    SetMasterVolume(game.volume);
    PlayMusicStream(sounds.wood_ambiance);
    PlayMusicStream(sounds.walk_forest);

    while (game.run && !WindowShouldClose()) {
        switch (gameState) {
        case GameState::MAINMENU:
            mainMenu.ui();
            break;

        case GameState::GAMEPLAY:
            gameplay.controller();
            break;

        case GameState::PAUSE:
            gameplay.draw();
            pauseMenu.ui();
            break;
        }
    }

    StopMusicStream(sounds.wood_ambiance);
    StopMusicStream(sounds.walk_forest);
    CloseAudioDevice();
    CloseWindow();
}
