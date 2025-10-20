#pragma once

#include <raylib.h>

const float INV_WIDTH = 400.0;
const float INV_HEIGHT = 300.0;

enum PrimaryWeapon {
    NoPrimary,
    Ak47,
    MosinNagant,
};

enum SecondaryWeapon {
    NoSecondary,
    Fnx,
    Glock,
};

enum MeleeWeapon {
    Hand,
    Knife,
    BaseballBat,
};

struct WeaponProp {
    int magCount;
    int ammoCount;
    int magCapacity;
    int ammoCapacity;
    float firerate;
    bool isAuto;
};

struct Primary {
    PrimaryWeapon weapon;
    WeaponProp prop;
};

struct Secondary {
    SecondaryWeapon weapon;
    WeaponProp prop;
};

struct Melee {
    MeleeWeapon weapon;
    WeaponProp prop;
};

// enum Medkit { NoMedkit, Small, Medium, Big };

struct Inventory {
    int selected;
    Primary primary;
    Secondary secondary;
    Melee melee;
    WeaponProp* currentWeapon;

    void changeInv();
    void useMedKit();
    void draw();
};

inline Inventory inventory = {
    .selected = 3,
    .primary =
        Primary{
            .weapon = NoPrimary,
            .prop =
                WeaponProp{
                    .magCount = 0,
                    .ammoCount = 0,
                    .firerate = 0.0,
                    .isAuto = false,
                },
        },

    .secondary =
        Secondary{
            .weapon = Fnx,
            .prop =
                WeaponProp{
                    .magCount = 10,
                    .ammoCount = 30,
                    .magCapacity = 10,
                    .ammoCapacity = 30,
                    .firerate = 0.3,
                    .isAuto = false,
                },
        },

    .melee =
        Melee{
            .weapon = Hand,
            .prop =
                WeaponProp{
                    .magCount = 1,
                    .ammoCount = 0,
                    .firerate = 1.0,
                    .isAuto = false,
                },
        },
    .currentWeapon = &inventory.melee.prop,
};

void drawWeapons();
