#include "gameplay/inventory/inventory.hpp"
#include "assets.hpp"
#include "gameplay/player.hpp"
#include "raygui.h"
#include "raylib.h"

void Inventory::changeInv() {
    if (player.action == Ready) {
        if (IsKeyPressed(KEY_ONE) && inventory.primary.weapon != PrimaryWeapon::NoPrimary) {
            inventory.selected = 1;
            inventory.currentWeapon = &inventory.primary.prop;
        } else if (IsKeyPressed(KEY_TWO) &&
                   inventory.secondary.weapon != SecondaryWeapon::NoSecondary) {
            inventory.selected = 2;
            inventory.currentWeapon = &inventory.secondary.prop;
        } else if (IsKeyPressed(KEY_THREE)) {
            inventory.selected = 3;
            inventory.currentWeapon = &inventory.melee.prop;
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
    DrawRectangleGradientH(0, (inventory.selected - 1) * 48, 100, 48, GRAY, ColorAlpha(WHITE, 0.0));
    DrawRectangle(0, (inventory.selected - 1) * 48, 5, 48, WHITE);

    drawWeapons();
}

void drawWeapons() {
    int paddingX = 20;

    // primary
    switch (inventory.primary.weapon) {
    case NoPrimary:
        break;
    case Ak47:
        DrawTexture(textures.ak47, paddingX, 0, WHITE);
        break;
    case MosinNagant:
        DrawTexture(textures.ak47, paddingX, 0, WHITE);
        break;
    }

    // secondary
    switch (inventory.secondary.weapon) {
    case NoSecondary:
        break;
    case Glock:
        DrawTexture(textures.glock, paddingX, 1 * 48, WHITE);
        break;
    case Fnx:
        DrawTexture(textures.glock, paddingX, 1 * 48, WHITE);
        break;
    }

    // melee
    switch (inventory.melee.weapon) {
    case Hand:
        DrawTexture(textures.hand, paddingX, 2 * 48, WHITE);
        break;
    case Knife:
        DrawTexture(textures.knife, paddingX, 2 * 48, WHITE);
        break;
    case BaseballBat:
        DrawTexture(textures.knife, paddingX, 2 * 48, WHITE);
        break;
    }
}
