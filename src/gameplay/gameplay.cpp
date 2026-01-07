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
    gameplay.draw();
}

void Gameplay::run() {
    UpdateMusicStream(sounds.wood_ambiance);

    player.update();

    drop.update();

    Bullet::updateAll(target.pos);
    HitNumber::updateAll();

    weaponTimerController();

    inventory.update();
    gameCamera.update();
    cursor.update();
}
