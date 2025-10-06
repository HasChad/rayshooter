#include "camera.h"
#include "player.h"

void GameCamera::update() {
    camera.target = player.pos;
    camera.offset = Vector2Lerp(camera.offset, targetOffset, CAMERA_SMOOTH_SPEED);
}

void GameCamera::handleAim() {
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Vector2 aimOffset =
            Vector2Subtract(GetMousePosition(), { screen.width / 2.0f, screen.height / 2.0f });
        if (Vector2Length(aimOffset) > MAX_AIM_OFFSET) {
            aimOffset = Vector2Scale(Vector2Normalize(aimOffset), MAX_AIM_OFFSET);
        }
        targetOffset = Vector2Subtract({ screen.width / 2.0f, screen.height / 2.0f }, aimOffset);
    } else {
        targetOffset = { screen.width / 2.0f, screen.height / 2.0f };
    }
}

void GameCamera::handleZoom() {
    camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));
    if (camera.zoom > 2.0f)
        camera.zoom = 2.0f;
    else if (camera.zoom < 0.5f)
        camera.zoom = 0.5f;
}
