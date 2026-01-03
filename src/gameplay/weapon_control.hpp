#pragma once

#include "gameplay/gameplay.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"
#include <vector>

class HitNumber {
  public:
    Vector2 pos = { 0, 0 };
    int damage = inventory.currentWeapon->damage;
    float lifeTime = 1;

    void updateLife() {
        pos.y -= 5 * GetFrameTime();
        lifeTime -= GetFrameTime();
    }

    void draw() const {
        const char* text = TextFormat("%d", damage);
        DrawText(text, pos.x, pos.y, 10, WHITE);
    }
};
inline std::vector<HitNumber> hitNum;

class Bullet {
  public:
    Vector2 pos = player.pos;
    Vector2 oldPos = player.pos;
    int damage = inventory.currentWeapon->damage;
    int speed = inventory.currentWeapon->bulletSpeed;
    Vector2 vel = Vector2Normalize(cursor.pos - player.pos);
    float lifeTime = 2;

    void castRay(Vector2 circleCol) {
        if (CheckCollisionCircleLine(circleCol, 16, oldPos, pos)) {
            HitNumber hit;
            hit.pos = pos;
            hit.damage = damage;
            hitNum.push_back(hit);

            lifeTime = 0;
        };
    }

    void updatePos() {
        oldPos = pos;
        pos += vel * speed;
        lifeTime -= GetFrameTime();
    }

    void draw() const { DrawLineEx(oldPos, pos, 2, YELLOW); }
};
inline std::vector<Bullet> bullets;

void bulletController();
void bulletSpawner();

void handleShootingSound();
void handleReloadingSound();

void weaponShooting();
void weaponReloading();
void weaponTimerController();
