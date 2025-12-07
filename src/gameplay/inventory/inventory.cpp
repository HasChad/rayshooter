#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raygui.h"
#include "raylib.h"

void Inventory::changeInv() {
    if (player.action == PlayerAction::Ready) {
        if (IsKeyPressed(KEY_ONE) && primary.weapon != PrimaryWeapon::None) {
            selected = 1;
            currentWeapon = &primary.prop;
        } else if (IsKeyPressed(KEY_TWO) && secondary.weapon != SecondaryWeapon::None) {
            selected = 2;
            currentWeapon = &secondary.prop;
        } else if (IsKeyPressed(KEY_THREE)) {
            selected = 3;
            currentWeapon = &melee.prop;
        }
    }
}

/*
void Inventory::useMedKit() {
    if (inventory.selected == 4) {
        switch (inventory.medkit) {
        case NoMedkit:
            break;
        case Small:
            break;
        case Medium:
            break;
        case Big:
            break;
        }
    }
}
*/

void Inventory::draw() {
    DrawRectangleGradientH(0, 0, 30, 3 * 48, DARKGRAY, ColorAlpha(WHITE, 0.0));
    DrawRectangleGradientH(0, (inventory.selected - 1) * 48, 70, 48, GRAY, ColorAlpha(WHITE, 0.0));
    DrawRectangle(0, (inventory.selected - 1) * 48, 5, 48, WHITE);

    drawWeapons();
}

void drawWeapons() {
    int paddingX = 10;

    DrawTexture(*inventory.primary.assets.sprite, paddingX, 0, WHITE);
    DrawTexture(*inventory.secondary.assets.sprite, paddingX, 1 * 48, WHITE);
    DrawTexture(*inventory.melee.assets.sprite, paddingX, 2 * 48, WHITE);
}
