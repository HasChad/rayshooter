#pragma once

#include "raylib.h"
#include <vector>

const float BULLET_SPEED = 20.0f;

struct Bullet {
    Vector2 pos;
    Vector2 vel;
    float lifeTime;
};
inline std::vector<Bullet> bullets;

void bulletController();
void bulletSpawner();

void handleShootingSound();

void weaponShooting();
void weaponReloading();
void weaponTimerController();
