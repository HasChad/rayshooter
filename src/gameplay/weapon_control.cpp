#include "gameplay/weapon_control.hpp"
#include "assets.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "globals.hpp"
#include "raylib.h"
#include "raymath.h"

void weaponShooting() {
    if (inventory.selected == 3) {
    } else {
        if (inventory.currentWeapon->magCount > 0) {
            inventory.currentWeapon->magCount--;
            bulletSpawner();
        }
    }
}

void weaponReloading() {
    if (inventory.currentWeapon->magCount < inventory.currentWeapon->magCapacity &&
        inventory.currentWeapon->ammoCount > 0) {

        inventory.currentWeapon->reloadTimer -= GetFrameTime();

        if (inventory.currentWeapon->reloadTimer <= 0) {
            if (inventory.currentWeapon->ammoCount + inventory.currentWeapon->magCount >=
                inventory.currentWeapon->magCapacity) {
                inventory.currentWeapon->ammoCount -=
                    (inventory.currentWeapon->magCapacity - inventory.currentWeapon->magCount);
                inventory.currentWeapon->magCount = inventory.currentWeapon->magCapacity;

            } else {
                inventory.currentWeapon->magCount += inventory.currentWeapon->ammoCount;
                inventory.currentWeapon->ammoCount = 0;
            }
        }
    }
}

void weaponTimerController() {
    if (player.action == Shooting) {
        if (inventory.currentWeapon->fireTimer <= 0) {
            inventory.currentWeapon->fireTimer = inventory.currentWeapon->firerate;
            weaponShooting();

        } else {
            inventory.currentWeapon->fireTimer -= GetFrameTime();

            if (inventory.currentWeapon->fireTimer <= 0) {
                player.action = Ready;
            }
        }
    }

    if (player.action == Reloading) {
        if (inventory.currentWeapon->reloadTimer <= 0) {
            inventory.currentWeapon->reloadTimer = inventory.currentWeapon->reloadSpeed;

        } else {
            inventory.currentWeapon->reloadTimer -= GetFrameTime();

            if (inventory.currentWeapon->reloadTimer <= 0) {
                weaponReloading();
                player.action = Ready;
            }
        }
    }
}

void bulletSpawner() {
    PlaySound(sounds.gunshot);

    Vector2 bulletVel = cursorPos - player.pos;
    bulletVel = Vector2Normalize(bulletVel);
    int move = player.lookLeft ? -10 : 10;
    Vector2 bulletPos = { player.pos.x + move, player.pos.y - 4 };

    bullets.push_back({ bulletPos, bulletVel, 3.0 });
}

void bulletController() {
    for (auto& bullet : bullets) {
        bullet.pos += bullet.vel * BULLET_SPEED;
        bullet.lifeTime -= GetFrameTime();
    }

    for (int i = bullets.size() - 1; i >= 0; i--) {
        if (bullets[i].lifeTime < 0)
            bullets.erase(bullets.begin() + i);
    }
}
