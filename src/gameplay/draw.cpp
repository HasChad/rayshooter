#include "draw.hpp"
#include "assets.hpp"
#include "gameplay/weapon_control.hpp"
#include "globals.hpp"
#include "player.hpp"
#include "raylib.h"

void drawGame() {
    drawTerrain();
    player.draw();

    for (const auto& bullet : bullets) {
        float angleDeg = atan2f(bullet.vel.y, bullet.vel.x) * RAD2DEG;

        DrawTextureEx(
            textures.bullet,
            {
                static_cast<float>(bullet.pos.x - textures.bullet.width / 2.0),
                static_cast<float>(bullet.pos.y - textures.bullet.height / 2.0),
            },
            angleDeg,
            1,
            WHITE
        );
    }

    DrawTexture(
        textures.cursor,
        cursorPos.x - textures.cursor.width / 2.0,
        cursorPos.y - textures.cursor.width / 2.0,
        WHITE
    );
}

void drawTerrain() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Vector2 texPos = (Vector2){
                static_cast<float>(j * terraTex.ground.width),
                static_cast<float>(i * terraTex.ground.height),
            };
            DrawTextureEx(terraTex.ground, texPos, 0, 1, WHITE);
        }
    }
}
