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
    gameplay.draw();
}

void Gameplay::run() {
    UpdateMusicStream(sounds.wood_ambiance);

    player.update();

    drop.update();

    for (auto& bullet : bullets) {
        bullet.updatePos();
    }

    for (auto& hit : hitNum) {
        hit.updateLife();
    }

    for (int i = hitNum.size() - 1; i >= 0; i--) {
        if (hitNum[i].lifeTime < 0)
            hitNum.erase(hitNum.begin() + i);
    }

    bulletController();
    weaponTimerController();

    inventory.update();
    gameCamera.update();
    cursor.update();
}
