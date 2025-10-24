#include "gameplay/weapon_control.hpp"
#include "assets.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"
#include "raymath.h"

void weaponShooting() {
    if (inventory.selected == 3) {
    } else {
        if (inventory.currentWeapon->magCount > 0) {
            inventory.currentWeapon->magCount--;
            handleShootingSound();
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
    if (player.action == PlayerAction::Shooting) {
        if (inventory.currentWeapon->fireTimer <= 0) {
            inventory.currentWeapon->fireTimer = inventory.currentWeapon->firerate;
            weaponShooting();

        } else {
            inventory.currentWeapon->fireTimer -= GetFrameTime();

            if (inventory.currentWeapon->fireTimer <= 0) {
                player.action = PlayerAction::Ready;
            }
        }
    }

    if (player.action == PlayerAction::Reloading) {
        if (inventory.currentWeapon->reloadTimer <= 0) {
            inventory.currentWeapon->reloadTimer = inventory.currentWeapon->reloadSpeed;

        } else {
            inventory.currentWeapon->reloadTimer -= GetFrameTime();

            if (inventory.currentWeapon->reloadTimer <= 0) {
                weaponReloading();
                player.action = PlayerAction::Ready;
            }
        }
    }
}

void handleShootingSound() {
    switch (GetRandomValue(1, 3)) {
    case 1:
        PlaySound(sounds.ak_1);
        break;
    case 2:
        PlaySound(sounds.ak_2);
        break;
    case 3:
        PlaySound(sounds.ak_3);
        break;
    }
}

void bulletSpawner() {
    Bullet bullet;

    bullets.push_back(bullet);
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
