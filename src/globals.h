#pragma once

#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>

const float BULLET_SPEED = 20.0f;

typedef enum GameScreen { GAMEPLAY, INVENTORY, PAUSE } GameScreen;

struct Screen {
    int width;
    int height;
};

constexpr Screen screen = {
    .width = 800,
    .height = 450,
};
constexpr Rectangle screenRec = { 0, 0, screen.width, screen.height };

struct Bullet {
    Vector2 pos;
    Vector2 vel;
    float lifeTime;
};

inline std::vector<Bullet> bullets;

inline Vector2 cursorPos;
inline int terrain[10][10];
