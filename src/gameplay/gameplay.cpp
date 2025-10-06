#include "gameplay/gameplay.h"
#include "assets.h"
#include "camera.h"
#include "draw.h"
#include "globals.h"
#include "player.h"
#include <raylib.h>

void Gameplay::run() {
    UpdateMusicStream(sounds.wood_ambiance);
    cursorPos = GetScreenToWorld2D(GetMousePosition(), gameCamera);
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
    DrawText(TextFormat("Health: %.0f", player.health), 5, screen.height - 20, 20, ORANGE);
    DrawText(TextFormat("Ammo: "), screen.width - 80, screen.height - 20, 20, ORANGE);
}
