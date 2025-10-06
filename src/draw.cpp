#include "draw.h"
#include "assets.h"
#include "globals.h"
#include "player.h"
#include "raylib.h"
#include <cmath>

void drawGame() {
    DrawTexturePro(textures.bg, screenRec, screenRec, { 0.0f, 0.0f }, 0, WHITE);

    player.draw();

    for (const auto& bullet : bullets) {
        float angleDeg = atan2f(bullet.vel.y, bullet.vel.x) * RAD2DEG;

        DrawTextureEx(
            textures.bullet,
            { static_cast<float>(bullet.pos.x - textures.bullet.width / 2.0),
              static_cast<float>(bullet.pos.y - textures.bullet.height / 2.0) },
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
