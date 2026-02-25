#include "gameplay/draw.hpp"
#include "assets.hpp"
#include "gameplay/camera.hpp"
#include "gameplay/gameplay.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/weapon_control.hpp"
#include "globals.hpp"
#include "player.hpp"
#include "raylib.h"

void drawTerrain();
void drawSpinner();

void Gameplay::draw() {
    BeginMode2D(gameCamera.camera);

    // Game thingies
    drawTerrain();
    drop.draw();
    DummyTarget::drawAll();
    Bullet::drawAll();
    HitNumber::drawAll();
    ParticleEffect::drawAll();
    player.draw();

    // UI thingies
    drawSpinner();
    cursor.draw();

    EndMode2D();
    inventory.draw();
    gameplay.ui();
}

void drawTerrain() {
    float offset = static_cast<float>(terraTex.ground.width) * ROWS / 2;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Vector2 texPos = (Vector2){
                static_cast<float>(j * terraTex.ground.width - offset),
                static_cast<float>(i * terraTex.ground.height - offset),
            };
            DrawTextureEx(terraTex.ground, texPos, 0, 1, WHITE);
        }
    }
}

void drawSpinner() {
    if (player.action != PlayerAction::Reloading)
        return;

    Vector2 position = {
        player.pos.x - (float)textures.reloadSpinner.width / 8 / 2,
        player.pos.y - 50,
    };

    int frame = 8 * (inventory.currentWeapon->reloadSpeed - inventory.currentWeapon->reloadTimer) /
                inventory.currentWeapon->reloadSpeed;

    int nextPos = textures.reloadSpinner.width / 8 * frame;
    Rectangle frameRec = {
        static_cast<float>(nextPos),
        0.0f,
        (float)textures.reloadSpinner.width / 8,
        (float)textures.reloadSpinner.height,
    };

    DrawTextureRec(textures.reloadSpinner, frameRec, position, WHITE);
}
