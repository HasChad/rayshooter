#include "gameplay/weapon_control.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"

void Inventory::weaponTimerController() {
    if (player.action == PlayerAction::Shooting) {
        if (currentWeapon->fireTimer == currentWeapon->firerate) {
            weaponShooting();
            handleShootingSound();
            currentWeapon->fireTimer -= GetFrameTime();
        } else {
            currentWeapon->fireTimer -= GetFrameTime();

            if (currentWeapon->fireTimer <= 0) {
                currentWeapon->fireTimer = currentWeapon->firerate;
                player.action = PlayerAction::Ready;
            }
        }
    }

    if (player.action == PlayerAction::Reloading) {
        if (currentWeapon->reloadTimer == currentWeapon->reloadSpeed) {
            handleReloadingSound();
            currentWeapon->reloadTimer -= GetFrameTime();
        } else {
            currentWeapon->reloadTimer -= GetFrameTime();

            if (currentWeapon->reloadTimer <= 0) {
                weaponReloading();
                currentWeapon->reloadTimer = currentWeapon->reloadSpeed;
                player.action = PlayerAction::Ready;
            }
        }
    }
}

void Inventory::weaponShooting() {
    if (selected == WeaponSlot::Melee) {
        // make cqc fight
    } else {
        currentWeapon->magCount--;
        Bullet::spawn();
    }
}

void Inventory::weaponReloading() {
    if (currentWeapon->ammoCount + currentWeapon->magCount >= currentWeapon->magCapacity) {
        currentWeapon->ammoCount -= (currentWeapon->magCapacity - currentWeapon->magCount);
        currentWeapon->magCount = currentWeapon->magCapacity;

    } else {
        currentWeapon->magCount += currentWeapon->ammoCount;
        currentWeapon->ammoCount = 0;
    }
}

void Inventory::handleShootingSound() {
    switch (selected) {
    case WeaponSlot::Primary:
        PlaySound(*primary.assets.shootingSound);
        break;
    case WeaponSlot::Secondary:
        PlaySound(*secondary.assets.shootingSound);
        break;
    case WeaponSlot::Melee:
        break;
    }
}

void Inventory::handleReloadingSound() {
    switch (selected) {
    case WeaponSlot::Primary:
        PlaySound(*primary.assets.reloadingSound);
        break;
    case WeaponSlot::Secondary:
        PlaySound(*secondary.assets.reloadingSound);
        break;
    case WeaponSlot::Melee:
        break;
    }
}
