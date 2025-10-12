#pragma once

#include <raylib.h>
#include <raymath.h>
#include <vector>

const float BULLET_SPEED = 20.0f;

typedef enum GameState { MAINMENU, GAMEPLAY, PAUSE } GameState;
inline GameState gameState = MAINMENU;

struct Bullet {
    Vector2 pos;
    Vector2 vel;
    float lifeTime;
};

inline std::vector<Bullet> bullets;

inline Vector2 cursorPos;

constexpr int ROWS = 10;
constexpr int COLS = 10;
inline int terrain[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
