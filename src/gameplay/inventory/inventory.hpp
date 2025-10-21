#pragma once

#include <raylib.h>

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
    bool isAuto;
    float firerate;
    float fireTimer;
    float reloadSpeed;
    float reloadTimer;
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
                    .isAuto = false,
                    .firerate = 0.3,
                    .fireTimer = 0.0,
                    .reloadSpeed = 1.5,
                    .reloadTimer = 1.5,
                },
        },

    .melee =
        Melee{
            .weapon = Hand,
            .prop =
                WeaponProp{
                    .magCount = 1,
                    .ammoCount = 1,
                    .magCapacity = 1,
                    .ammoCapacity = 1,
                    .isAuto = false,
                    .firerate = 1,
                    .fireTimer = 0,
                    .reloadSpeed = 1,
                    .reloadTimer = 1,
                },
        },

    .currentWeapon = &inventory.melee.prop,
};

void drawWeapons();
