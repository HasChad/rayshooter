#pragma once

#include <raylib.h>
#include <raymath.h>

const float PLAYER_SPEED = 2.0f;
const float SHIFT_SPEED = 1.0f;

enum class PlayerAction {
    Ready,
    Shooting,
    Reloading,
};

class Player {
  public:
    float health = 100.0f;
    float armor = 100.0f;
    Vector2 vel = { 0, 0 };
    Vector2 pos = { 0, 0 };
    Vector2 rec = { 20, 20 };
    bool lookLeft = false;
    PlayerAction action = PlayerAction::Ready;

    void movementInput();
    void playerMove();
    void handleWeapon();
    void draw() const;
};

inline Player player;
