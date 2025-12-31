#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raygui.h"
#include "raylib.h"

void Inventory::update() {
    changeInv();
    useMedKit();
}

void Inventory::changeInv() {
    if (player.action == PlayerAction::Ready) {
        if (IsKeyPressed(KEY_ONE) && primary.weapon != PrimaryWeapon::None) {
            selected = WeaponSlot::Primary;
            currentWeapon = &primary.prop;
        } else if (IsKeyPressed(KEY_TWO) && secondary.weapon != SecondaryWeapon::None) {
            selected = WeaponSlot::Secondary;
            currentWeapon = &secondary.prop;
        } else if (IsKeyPressed(KEY_THREE)) {
            selected = WeaponSlot::Melee;
            currentWeapon = &melee.prop;
        }
    }
}

void Inventory::useMedKit() {}

void Inventory::draw() {
    DrawRectangleGradientH(0, 0, 30, 3 * 48, DARKGRAY, ColorAlpha(WHITE, 0.0));

    int offset = static_cast<int>(inventory.selected);

    DrawRectangleGradientH(0, offset * 48, 70, 48, GRAY, ColorAlpha(WHITE, 0.0));
    DrawRectangle(0, offset * 48, 5, 48, WHITE);

    int paddingX = 10;

    DrawTexture(*inventory.primary.assets.sprite, paddingX, 0, WHITE);
    DrawTexture(*inventory.secondary.assets.sprite, paddingX, 1 * 48, WHITE);
    DrawTexture(*inventory.melee.assets.sprite, paddingX, 2 * 48, WHITE);
}
