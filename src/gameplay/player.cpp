#include "player.hpp"
#include "assets.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/weapon_control.hpp"
#include "globals.hpp"
#include <raylib.h>
#include <raymath.h>

void Player::update() {
    movementInput();
    playerMove();
    handleWeapon();
}

void Player::movementInput() {
    float up = IsKeyDown(KEY_W) ? 1 : 0;
    float down = IsKeyDown(KEY_S) ? 1 : 0;
    float left = IsKeyDown(KEY_A) ? 1 : 0;
    float right = IsKeyDown(KEY_D) ? 1 : 0;
    float speed = IsKeyDown(KEY_LEFT_SHIFT) ? SHIFT_SPEED : PLAYER_SPEED;

    vel = Vector2Normalize((Vector2){ right - left, down - up }) * speed;
}

void Player::playerMove() {
    if (Vector2Length(vel) > 0)
        UpdateMusicStream(sounds.walk_forest);

    pos += vel;
}

bool canShoot() {
    return (
        (!inventory.currentWeapon->isAuto && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ||
        (inventory.currentWeapon->isAuto && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) &&
            inventory.currentWeapon->magCount > 0
    );
}

bool canReload() {
    return (
        (IsKeyPressed(KEY_R) &&
         inventory.currentWeapon->magCount < inventory.currentWeapon->magCapacity &&
         inventory.currentWeapon->ammoCount > 0) ||
        inventory.currentWeapon->magCount == 0
    );
}

void Player::handleWeapon() {
    if (canShoot() && player.action == PlayerAction::Ready) {
        player.action = PlayerAction::Shooting;
        handleShootingSound();
    }

    if (canReload() && player.action == PlayerAction::Ready) {
        player.action = PlayerAction::Reloading;
        handleReloadingSound();
    }
}

void Player::draw() const {
    player.lookLeft = cursorPos.x < player.pos.x ? true : false;

    int flip = lookLeft ? -1 : 1;

    DrawTextureRec(
        textures.player,
        (Rectangle){ 0, 0, (float)textures.player.width * flip, (float)textures.player.height },
        { static_cast<float>(pos.x - textures.player.width / 2.0),
          static_cast<float>(pos.y - textures.player.height / 2.0) },
        WHITE
    );
}
