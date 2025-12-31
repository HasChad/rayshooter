#include "gameplay/gameplay.hpp"
#include "assets.hpp"
#include "camera.hpp"
#include "globals.hpp"
#include "inventory/inventory.hpp"
#include "player.hpp"
#include "raymath.h"
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
    /* Maybe i will use this locking cursor if i cant find better solution
    if (GetMousePosition().x < 0)
        SetMousePosition(0, GetMousePosition().y);
    if (GetMousePosition().x > screen.width)
        SetMousePosition(screen.width, GetMousePosition().y);
    if (GetMousePosition().y < 0)
        SetMousePosition(GetMousePosition().x, 0);
    if (GetMousePosition().y > screen.height)
        SetMousePosition(GetMousePosition().x, screen.height);
    */

    UpdateMusicStream(sounds.wood_ambiance);
    if (IsKeyPressed(KEY_SPACE)) {
        player.pos = Vector2Zero();
    }

    bulletController();
    weaponTimerController();

    player.movementInput();
    player.playerMove();
    player.handleWeapon();

    inventory.changeInv();

    gameCamera.update();
    gameCamera.handleAim();
    gameCamera.handleZoom();

    cursorPos = GetScreenToWorld2D(GetMousePosition(), gameCamera.camera);
}
