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

    static void updateAll();
    static void drawAll();
};

inline std::vector<HitNumber> hitNum;

inline void HitNumber::updateAll() {
    for (auto& hit : hitNum) {
        hit.updateLife();
    }

    for (int i = hitNum.size() - 1; i >= 0; i--) {
        if (hitNum[i].lifeTime < 0)
            hitNum.erase(hitNum.begin() + i);
    }
}

inline void HitNumber::drawAll() {
    for (auto& hit : hitNum) {
        hit.draw();
    }
}

class Bullet {
  public:
    Vector2 pos = player.pos;
    Vector2 oldPos = player.pos;
    int damage = inventory.currentWeapon->damage;
    int speed = inventory.currentWeapon->bulletSpeed;
    Vector2 vel = Vector2Normalize(cursor.pos - player.pos);
    float lifeTime = 2;
    bool hasHit = false;

    void castRay(Vector2 circleCol) {
        if (hasHit)
            return;

        if (CheckCollisionCircleLine(circleCol, 16, oldPos, pos)) {
            HitNumber hit;
            hit.pos = pos;
            hit.damage = damage;
            hitNum.push_back(hit);
            lifeTime = 0;
            hasHit = true;
        }
    }

    void updatePos() {
        oldPos = pos;
        pos += vel * speed;
        lifeTime -= GetFrameTime();
    }

    void draw() const { DrawLineEx(oldPos, pos, 2, YELLOW); }

    static void spawn();
    static void updateAll(Vector2 targetPos);
    static void drawAll();
};

inline std::vector<Bullet> bullets;

inline void Bullet::spawn() {
    Bullet bullet;
    bullets.push_back(bullet);
}

inline void Bullet::updateAll(Vector2 targetPos) {
    for (auto& bullet : bullets) {
        bullet.updatePos();
        bullet.castRay(targetPos);
    }

    for (int i = bullets.size() - 1; i >= 0; i--) {
        if (bullets[i].lifeTime < 0)
            bullets.erase(bullets.begin() + i);
    }
}

inline void Bullet::drawAll() {
    for (const auto& bullet : bullets) {
        bullet.draw();
    }
}

void handleShootingSound();
void handleReloadingSound();

void weaponShooting();
void weaponReloading();
void weaponTimerController();
