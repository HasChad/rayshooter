#include "gameplay/gameplay.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"

void Gameplay::ui() {
    int lineLeft = GetScreenWidth() / 2 - 50;
    DrawRectangle(lineLeft, GetScreenHeight() - 12, 100, 2, WHITE);

    int textSize = 0;
    const char* text;
    int xPadding = 0;

    text = TextFormat("Armor: %.0f", player.armor);
    textSize = MeasureText(text, 20);
    xPadding = lineLeft - textSize - 10;

    DrawRectangle(xPadding - 5, GetScreenHeight() - 23, textSize + 10, 25, ColorAlpha(BLACK, 0.5));
    DrawText(text, xPadding, GetScreenHeight() - 20, 20, WHITE);

    text = TextFormat("Health: %.0f", player.health);
    textSize = MeasureText(text, 20);
    xPadding -= textSize;

    DrawRectangle(xPadding - 20, GetScreenHeight() - 23, textSize + 10, 25, ColorAlpha(BLACK, 0.5));
    DrawText(text, xPadding - 15, GetScreenHeight() - 20, 20, WHITE);

    if (inventory.selected != WeaponSlot::Melee) {
        text = TextFormat(
            "Ammo: %d / %d", inventory.currentWeapon->magCount, inventory.currentWeapon->ammoCount
        );
        textSize = MeasureText(text, 20);

        DrawRectangle(
            GetScreenWidth() / 2 + 55,
            GetScreenHeight() - 23,
            textSize + 10,
            25,
            ColorAlpha(BLACK, 0.5)
        );
        DrawText(text, GetScreenWidth() / 2 + 60, GetScreenHeight() - 20, 20, WHITE);
    }
};
