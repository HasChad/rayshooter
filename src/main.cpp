#include "assets.h"
#include "camera.h"
#include "draw.h"
#include "globals.h"
#include "player.h"

#include <raylib.h>
#include <raymath.h>

int main() {
    InitWindow(screen.width, screen.height, "RayShooter");
    InitAudioDevice();
    SetTargetFPS(60);
    SetWindowIcon(LoadImage("sprites/icon.png"));
    HideCursor();

    GameScreen currentScreen = GAMEPLAY;
    textures.player = LoadTexture("sprites/player.png");
    textures.bullet = LoadTexture("sprites/bullet.png");
    textures.cursor = LoadTexture("sprites/cursor.png");
    textures.bg = LoadTexture("sprites/beton.png");

    sounds.wood_ambiance = LoadMusicStream("sounds/wood_ambiance.mp3");
    sounds.walk_forest = LoadMusicStream("sounds/walk_forest.mp3");
    sounds.gunshot = LoadSound("sounds/gunshot.mp3");
    SetMasterVolume(0.3);
    PlayMusicStream(sounds.wood_ambiance);
    PlayMusicStream(sounds.walk_forest);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateMusicStream(sounds.wood_ambiance);
        cursorPos = GetScreenToWorld2D(GetMousePosition(), gameCamera);
        player.lookLeft = cursorPos.x < player.pos.x ? true : false;

        player.movementInput();
        player.playerMove();
        player.shooting();

        gameCamera.update();
        gameCamera.handleAim();
        gameCamera.handleZoom();

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(gameCamera);

        drawGame();

        EndMode2D();

        DrawText(TextFormat("Health: %.0f", player.health), 5, screen.height - 20, 20, ORANGE);
        DrawText(TextFormat("Ammo: "), screen.width - 80, screen.height - 20, 20, ORANGE);

        EndDrawing();
    }

    StopMusicStream(sounds.wood_ambiance);
    StopMusicStream(sounds.walk_forest);
    CloseAudioDevice();
    CloseWindow();
}
