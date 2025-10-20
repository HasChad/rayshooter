#include "gameplay/gameplay.hpp"
#include "assets.hpp"
#include "camera.hpp"
#include "draw.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/ui.hpp"
#include "gameplay/weapon_control.hpp"
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

    if (IsKeyPressed(KEY_X)) {
        inventory.primary.weapon = PrimaryWeapon::Ak47;
        inventory.primary.prop = WeaponProp{
            .magCount = 30,
            .ammoCount = 120,
            .magCapacity = 30,
            .ammoCapacity = 120,
            .firerate = 0.3,
            .isAuto = true,
        };
        // inventory.selected = 1;
        // inventory.currentWeapon = &inventory.primary.prop;
    }

    bulletController();

    player.movementInput();
    player.playerMove();
    player.handleWeapon();

    inventory.changeInv();

    gameCamera.update();
    gameCamera.handleAim();
    gameCamera.handleZoom();
}

void Gameplay::draw() {
    BeginMode2D(gameCamera);
    drawGame();
    EndMode2D();
    inventory.draw();
    ui();
}
