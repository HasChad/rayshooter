#pragma once

#include "gameplay/player.hpp"
#include "globals.hpp"
#include "raylib.h"
#include <vector>

const float BULLET_SPEED = 20.0f;

struct Bullet {
    Vector2 pos = player.pos;
    Vector2 vel = Vector2Normalize(cursorPos - player.pos);
    float lifeTime = 3;
};
inline std::vector<Bullet> bullets;

void bulletController();
void bulletSpawner();

void handleShootingSound();

void weaponShooting();
void weaponReloading();
void weaponTimerController();
