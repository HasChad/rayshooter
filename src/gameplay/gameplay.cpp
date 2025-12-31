#include "gameplay/gameplay.hpp"
#include "camera.hpp"
#include "globals.hpp"
#include "inventory/inventory.hpp"
#include "player.hpp"
#include "weapon_control.hpp"
#include <raylib.h>

void Gameplay::controller() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        ShowCursor();
        gameState = GameState::PAUSE;
    }

    gameplay.run();

    BeginDrawing();
    ClearBackground(BLACK);
    gameplay.draw();
    EndDrawing();
}

void Gameplay::run() {
    /*
    if (GetMousePosition().x < 0)
        SetMousePosition(0, GetMousePosition().y);
    if (GetMousePosition().x > GetScreenWidth())
        SetMousePosition(GetScreenWidth(), GetMousePosition().y);
    if (GetMousePosition().y < 0)
        SetMousePosition(GetMousePosition().x, 0);
    if (GetMousePosition().y > GetScreenHeight())
        SetMousePosition(GetMousePosition().x, GetScreenHeight());

    UpdateMusicStream(sounds.wood_ambiance);
    if (IsKeyPressed(KEY_SPACE)) {
        player.pos = Vector2Zero();
    }
    */

    bulletController();
    weaponTimerController();

    player.update();
    inventory.update();
    gameCamera.update();

    cursorPos = GetScreenToWorld2D(GetMousePosition(), gameCamera.camera);
}
