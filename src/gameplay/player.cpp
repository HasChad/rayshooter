#include "player.h"
#include "assets.h"
#include "globals.h"
#include <raylib.h>
#include <raymath.h>

void Player::movementInput() {
    float up = IsKeyDown(KEY_W) ? 1 : 0;
    float down = IsKeyDown(KEY_S) ? 1 : 0;
    float left = IsKeyDown(KEY_A) ? 1 : 0;
    float right = IsKeyDown(KEY_D) ? 1 : 0;
    float speed = IsKeyDown(KEY_LEFT_SHIFT) ? SHIFT_SPEED : PLAYER_SPEED;

    vel = Vector2Normalize((Vector2){ right - left, down - up }) * speed;
}

void Player::playerMove() {
    if (Vector2Length(vel) > 0)
        UpdateMusicStream(sounds.walk_forest);

    pos += vel;
}

void Player::shooting() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        PlaySound(sounds.gunshot);

        Vector2 bulletVel = cursorPos - pos;
        bulletVel = Vector2Normalize(bulletVel);
        int move = lookLeft ? -10 : 10;
        Vector2 bulletPos = { pos.x + move, pos.y - 4 };

        bullets.push_back({ bulletPos, bulletVel, 3.0 });
    }

    for (auto& bullet : bullets) {
        bullet.pos += bullet.vel * BULLET_SPEED;
        bullet.lifeTime -= GetFrameTime();
    }

    for (int i = bullets.size() - 1; i >= 0; i--) {
        if (bullets[i].lifeTime < 0)
            bullets.erase(bullets.begin() + i);
    }
}

void Player::draw() {
    int flip = lookLeft ? -1 : 1;

    DrawTextureRec(
        textures.player,
        (Rectangle){ 0, 0, (float)textures.player.width * flip, (float)textures.player.height },
        { static_cast<float>(pos.x - textures.player.width / 2.0),
          static_cast<float>(pos.y - textures.player.height / 2.0) },
        WHITE
    );
}
