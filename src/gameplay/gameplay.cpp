#include "gameplay/gameplay.h"
#include "assets.h"
#include "camera.h"
#include "draw.h"
#include "gameplay/ui.h"
#include "globals.h"
#include "player.h"
#include "raymath.h"
#include <raylib.h>

void Gameplay::run() {
    UpdateMusicStream(sounds.wood_ambiance);
    cursorPos = GetScreenToWorld2D(GetMousePosition(), gameCamera);

    /* Maybe i will use this if i cant find better solution
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

    player.movementInput();
    player.playerMove();
    player.shooting();

    gameCamera.update();
    gameCamera.handleAim();
    gameCamera.handleZoom();
}

void Gameplay::draw() {
    BeginMode2D(gameCamera);
    drawGame();
    EndMode2D();
    ui();
}
