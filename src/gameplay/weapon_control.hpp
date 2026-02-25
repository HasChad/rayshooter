#pragma once

#include "gameplay/draw.hpp"
#include "gameplay/gameplay.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"
#include <cstdlib>
#include <vector>

class DamageNumber {
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

inline std::vector<DamageNumber> damageNumbers;

inline void DamageNumber::updateAll() {
    for (auto& hit : damageNumbers) {
        hit.updateLife();
    }

    for (int i = damageNumbers.size() - 1; i >= 0; i--) {
        if (damageNumbers[i].lifeTime < 0)
            damageNumbers.erase(damageNumbers.begin() + i);
    }
}

inline void DamageNumber::drawAll() {
    for (auto& hit : damageNumbers) {
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

    bool castRay(Vector2 circleCol, int collisionRad) {
        if (hasHit)
            return false;

        if (CheckCollisionCircleLine(circleCol, collisionRad, oldPos, pos)) {
            DamageNumber damageNum;
            damageNum.pos = { pos.x + rand() % 11, pos.y };
            damageNum.damage = damage;
            damageNumbers.push_back(damageNum);
            lifeTime = 0;
            hasHit = true;

            ParticleEffect picle = {
                .pos = damageNum.pos,
                .texture = textures.particle_metal_hit,
                .lifeTime = 0.1,
            };

            particles.push_back(picle);

            return true;
        } else {
            return false;
        }
    }

    void updatePos() {
        oldPos = pos;
        pos += vel * speed;
        lifeTime -= GetFrameTime();
    }

    void draw() const { DrawLineEx(oldPos, pos, 2, YELLOW); }

    static void spawn();
    static void updateAll(std::vector<DummyTarget>& targets);
    static void drawAll();
};

inline std::vector<Bullet> bullets;

inline void Bullet::spawn() {
    Bullet bullet;
    bullets.push_back(bullet);
}

inline void Bullet::updateAll(std::vector<DummyTarget>& targets) {
    for (auto& bullet : bullets) {
        bullet.updatePos();

        for (auto& target : targets) {
            target.hit = bullet.castRay(target.pos, target.collisionRad);
        }
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
