#include "camera.hpp"
#include "player.hpp"
#include "raylib.h"

void GameCamera::update() {
    camera.target = player.pos;
    camera.offset = Vector2Lerp(camera.offset, targetOffset, CAMERA_SMOOTH_SPEED);
}

void GameCamera::handleAim() {
    Vector2 screenSize = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Vector2 aimOffset = Vector2Subtract(GetMousePosition(), screenSize);

        if (Vector2Length(aimOffset) > MAX_AIM_OFFSET) {
            aimOffset = Vector2Scale(Vector2Normalize(aimOffset), MAX_AIM_OFFSET);
        }
        targetOffset = Vector2Subtract(screenSize, aimOffset);
    } else {
        targetOffset = screenSize;
    }
}

void GameCamera::handleZoom() {
    camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));

    if (camera.zoom > 2.0f)
        camera.zoom = 2.0f;
    else if (camera.zoom < 0.5f)
        camera.zoom = 0.5f;
}
