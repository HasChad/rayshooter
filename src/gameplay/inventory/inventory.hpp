#pragma once

#include <raylib.h>

const float INV_WIDTH = 400.0;
const float INV_HEIGHT = 300.0;

enum PrimaryWeapon { NoPrimary, Ak47, MosinNagant };
enum SecondaryWeapon { NoSecondary, Colt, Glock };
enum MeleeWeapon { NoMelee, Knife, BaseballBat };

struct Inventory {
    bool enable;

    PrimaryWeapon primary;
    SecondaryWeapon secondary;
    MeleeWeapon melee;

    void draw();
};

inline Inventory inventory = {
    .enable = false,
    .primary = NoPrimary,
    .secondary = NoSecondary,
    .melee = NoMelee,
};
