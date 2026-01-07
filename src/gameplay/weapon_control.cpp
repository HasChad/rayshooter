#include "gameplay/weapon_control.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"

void weaponShooting() {
    if (inventory.selected == WeaponSlot::Melee) {
        // make cqc fight
    } else {
        inventory.currentWeapon->magCount--;
        Bullet::spawn();
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

void handleShootingSound() {
    switch (inventory.selected) {
    case WeaponSlot::Primary:
        PlaySound(*inventory.primary.assets.shootingSound);
        break;
    case WeaponSlot::Secondary:
        PlaySound(*inventory.secondary.assets.shootingSound);
        break;
    case WeaponSlot::Melee:
        break;
    }
}

void handleReloadingSound() {
    switch (inventory.selected) {
    case WeaponSlot::Primary:
        PlaySound(*inventory.primary.assets.reloadingSound);
        break;
    case WeaponSlot::Secondary:
        PlaySound(*inventory.secondary.assets.reloadingSound);
        break;
    case WeaponSlot::Melee:
        break;
    }
}
