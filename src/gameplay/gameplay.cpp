#include "gameplay/gameplay.hpp"
#include "assets.hpp"
#include "camera.hpp"
#include "draw.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/ui.hpp"
#include "globals.hpp"
#include "player.hpp"
#include "raymath.h"
#include <raylib.h>

void Gameplay::run() {
    UpdateMusicStream(sounds.wood_ambiance);
    cursorPos = GetScreenToWorld2D(GetMousePosition(), gameCamera);

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

    if (IsKeyPressed(KEY_SPACE)) {
        player.pos = Vector2Zero();
    }

    player.lookLeft = cursorPos.x < player.pos.x ? true : false;

    if (IsKeyPressed(KEY_TAB)) {
        if (inventory.enable) {
            inventory.enable = false;
            HideCursor();
        } else {
            inventory.enable = true;
            ShowCursor();
        }
    }

    player.movementInput();
    player.playerMove();
    gameCamera.update();

    if (inventory.enable) {
        Vector2 screenSize = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
        gameCamera.targetOffset = screenSize;
    } else {
        gameCamera.handleAim();
        gameCamera.handleZoom();
        player.shooting();
    }
}

void Gameplay::draw() {
    BeginMode2D(gameCamera);
    drawGame();
    EndMode2D();
    if (inventory.enable) {
        inventory.draw();
    }
    ui();
}
