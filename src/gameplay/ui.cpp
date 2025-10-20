#include "gameplay/ui.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"

void ui() {
    DrawRectangle(0, GetScreenHeight() - 23, 120, 25, ColorAlpha(BLACK, 0.5));
    DrawText(TextFormat("Health: %.0f", player.health), 5, GetScreenHeight() - 20, 20, WHITE);

    DrawRectangle(125, GetScreenHeight() - 23, 120, 25, ColorAlpha(BLACK, 0.5));
    DrawText(
        TextFormat(
            "Ammo: %d / %d", inventory.currentWeapon->magCount, inventory.currentWeapon->ammoCount
        ),
        130,
        GetScreenHeight() - 20,
        20,
        WHITE
    );
};
