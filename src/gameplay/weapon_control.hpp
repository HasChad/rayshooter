#pragma once

#include "assets.hpp"
#include "gameplay/gameplay.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"
#include <vector>

const float BULLET_SPEED = 20.0f;

class Bullet {
  public:
    Vector2 pos = player.pos;
    Vector2 vel = Vector2Normalize(cursor.pos - player.pos);
    float lifeTime = 3;

    void draw() const {
        float angleDeg = atan2f(vel.y, vel.x) * RAD2DEG;

        DrawTextureEx(
            textures.bullet,
            {
                static_cast<float>(pos.x - textures.bullet.width / 2.0),
                static_cast<float>(pos.y - textures.bullet.height / 2.0),
            },
            angleDeg,
            1,
            WHITE
        );
    }
};
inline std::vector<Bullet> bullets;

void bulletController();
void bulletSpawner();

void handleShootingSound();
void handleReloadingSound();

void weaponShooting();
void weaponReloading();
void weaponTimerController();
