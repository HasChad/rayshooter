#include "gameplay/weapon_control.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"
#include "raymath.h"

void weaponShooting() {
    if (inventory.selected == 3) {
        // make cqc fight
    } else {
        inventory.currentWeapon->magCount--;
        bulletSpawner();
    }
}

void weaponReloading() {
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

void handleShootingSound() { PlaySound(*inventory.primary.assets.shootingSound); }
void handleReloadingSound() { PlaySound(*inventory.primary.assets.reloadingSound); }

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
