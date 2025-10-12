#pragma once

#include <raylib.h>

constexpr float CAMERA_SMOOTH_SPEED = 0.1f;
constexpr float MAX_AIM_OFFSET = 200.0f;

struct GameCamera {
    Camera2D camera;
    Vector2 targetOffset;

    GameCamera() {
        camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
        camera.target = { 0, 0 };
        camera.rotation = 0;
        camera.zoom = 1.0f;
        targetOffset = camera.offset;
    }

    void update();
    void handleAim();
    void handleZoom();

    operator Camera2D&() { return camera; }
};

inline GameCamera gameCamera;
