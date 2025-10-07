#pragma once

#include <raylib.h>
#include <raymath.h>

const float PLAYER_SPEED = 2.0f;
const float SHIFT_SPEED = 1.0f;

struct Player {
    float health;
    Vector2 vel;
    Vector2 pos;
    Vector2 rec;
    bool lookLeft;

    void movementInput();
    void playerMove();
    void shooting();
    void draw();
};

inline Player player = {
    .health = 100,
    .vel = Vector2Zero(),
    .pos = { 0, 0 },
    .rec = { 20, 20 },
    .lookLeft = false,
};
