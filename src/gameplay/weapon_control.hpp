#pragma once

#include "gameplay/gameplay.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

class Bullet {
  public:
    Vector2 pos = player.pos;
    Vector2 oldPos = player.pos;
    int damage = inventory.currentWeapon->damage;
    int speed = inventory.currentWeapon->bulletSpeed;
    Vector2 vel = Vector2Normalize(cursor.pos - player.pos);
    float lifeTime = 3;

    void castRay(Vector2 circleCol) {
        if (CheckCollisionCircleLine(circleCol, 16, oldPos, pos)) {
            std::cout << "hit\n";
        };
    }

    void updatePos() {
        oldPos = pos;
        pos += vel * speed;
        lifeTime -= GetFrameTime();
    }

    void draw() const { DrawLineEx(oldPos, pos, 3, YELLOW); }
};
inline std::vector<Bullet> bullets;

void bulletController();
void bulletSpawner();

void handleShootingSound();
void handleReloadingSound();

void weaponShooting();
void weaponReloading();
void weaponTimerController();
