#pragma once

#include <raylib.h>

enum class PrimaryWeapon {
    None,
    Ak47,
    MosinNagant,
};

enum class SecondaryWeapon {
    None,
    Fnx,
    Glock,
};

enum class MeleeWeapon {
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

inline Primary ak47{
    .weapon = PrimaryWeapon::Ak47,
    .prop =
        WeaponProp{
            .magCount = 30,
            .ammoCount = 120,
            .magCapacity = 30,
            .ammoCapacity = 120,
            .isAuto = true,
            .firerate = 0.12,
            .fireTimer = 0.0,
            .reloadSpeed = 2.0,
            .reloadTimer = 0.0,
        },
};

inline Primary mosinNagant{
    .weapon = PrimaryWeapon::MosinNagant,
    .prop =
        WeaponProp{
            .magCount = 5,
            .ammoCount = 25,
            .magCapacity = 5,
            .ammoCapacity = 25,
            .isAuto = false,
            .firerate = 1.0,
            .fireTimer = 0.0,
            .reloadSpeed = 3.0,
            .reloadTimer = 0.0,
        },
};

struct Secondary {
    SecondaryWeapon weapon;
    WeaponProp prop;
};

inline Secondary glock = {
    .weapon = SecondaryWeapon::Glock,
    .prop =
        WeaponProp{
            .magCount = 17,
            .ammoCount = 50,
            .magCapacity = 17,
            .ammoCapacity = 50,
            .isAuto = true,
            .firerate = 0.1,
            .fireTimer = 0.0,
            .reloadSpeed = 1.2,
            .reloadTimer = 0.0,
        },
};

inline Secondary fnx = {
    .weapon = SecondaryWeapon::Fnx,
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
            .reloadTimer = 0.0,
        },
};

struct Melee {
    MeleeWeapon weapon;
    WeaponProp prop;
};

inline Melee knife = {
    .weapon = MeleeWeapon::Knife,
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
            .reloadTimer = 0,
        },
};

// enum class Medkit { NoMedkit, Small, Medium, Big };

struct Inventory {
    int selected = 1;
    Primary primary = mosinNagant;
    Secondary secondary = glock;
    Melee melee = knife;
    WeaponProp* currentWeapon = &primary.prop;

    void changeInv();
    void useMedKit();
    void draw();
};

inline Inventory inventory;

void drawWeapons();
