#pragma once

#include "raylib.h"
enum class ZombieAction {
    Run,
    Atack,
    Die,
};

class Zombie {
  public:
    float health = 100.0f;
    // float armor = 100.0f;
    Vector2 vel = { 0, 0 };
    Vector2 pos = { 0, 0 };
    int collisionRad = 12;
    ZombieAction action = ZombieAction::Run;

    void update();
    void draw() const;
};
