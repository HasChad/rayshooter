#pragma once

#include <raylib.h>

const float CAMERA_SMOOTH_SPEED = 0.1f;
constexpr float MAX_AIM_OFFSET = 200.0f;

struct GameCamera {
    Camera2D camera = {
        .offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f },
        .target = { 0, 0 },
        .rotation = 0,
        .zoom = 1.0f,
    };
    Vector2 targetOffset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

    void update();
    void handleAim();
    void handleZoom();
};

inline GameCamera gameCamera;
