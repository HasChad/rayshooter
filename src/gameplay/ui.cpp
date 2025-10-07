#include "gameplay/ui.h"
#include "gameplay/player.h"
#include "raylib.h"

void ui() {
    DrawText(TextFormat("Health: %.0f", player.health), 5, GetScreenHeight() - 20, 20, ORANGE);
    DrawText(TextFormat("Ammo: "), GetScreenWidth() - 80, GetScreenHeight() - 20, 20, ORANGE);
};
