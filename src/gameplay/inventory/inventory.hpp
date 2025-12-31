#pragma once

#include "assets.hpp"
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

/*
enum class Medkit {
    None,
    Small,
    Medium,
    Big,
};
*/

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

struct WeaponAssets {
    Texture2D* sprite;
    Sound* shootingSound;
    Sound* reloadingSound;
};

struct Primary {
    PrimaryWeapon weapon;
    WeaponProp prop;
    WeaponAssets assets;
};

struct Secondary {
    SecondaryWeapon weapon;
    WeaponProp prop;
    WeaponAssets assets;
};

struct Melee {
    MeleeWeapon weapon;
    WeaponProp prop;
    WeaponAssets assets;
};

// ----- Primary Weapons ---------------------------------------

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
    .assets =
        WeaponAssets{
            .sprite = &textures.ak47,
            .shootingSound = &sounds.ak_shot,
            .reloadingSound = &sounds.reload_rifle,
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
    .assets =
        WeaponAssets{
            .sprite = &textures.mosin,
            .shootingSound = &sounds.mosin_shot,
            .reloadingSound = &sounds.reload_rifle,
        },
};

// ----- Secondary Weapons ---------------------------------------

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
    .assets =
        WeaponAssets{
            .sprite = &textures.glock,
            .shootingSound = &sounds.glock_shot,
            .reloadingSound = &sounds.reload_pistol,
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
    .assets =
        WeaponAssets{
            .sprite = &textures.fnx,
            .shootingSound = &sounds.fnx_shot,
            .reloadingSound = &sounds.reload_pistol,
        },
};

// --- Melee Weapons ---------------------------------------

inline Melee hand = {
    .weapon = MeleeWeapon::Hand,
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
    .assets =
        WeaponAssets{
            .sprite = &textures.hand,
            .shootingSound = &sounds.mosin_shot,
            .reloadingSound = &sounds.reload_rifle,
        },
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
    .assets =
        WeaponAssets{
            .sprite = &textures.knife,
            .shootingSound = &sounds.mosin_shot,
            .reloadingSound = &sounds.reload_rifle,
        },
};

inline Melee baseballbat = {
    .weapon = MeleeWeapon::BaseballBat,
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
    .assets =
        WeaponAssets{
            .sprite = &textures.baseballbat,
            .shootingSound = &sounds.mosin_shot,
            .reloadingSound = &sounds.reload_rifle,
        },
};

// --- Inventory ---------------------------------------

class Inventory {
  public:
    int selected = 1;
    Primary primary = ak47;
    Secondary secondary = glock;
    Melee melee = hand;
    WeaponProp* currentWeapon = &primary.prop;

    void changeInv();
    void useMedKit();
    void draw();
};

inline Inventory inventory;
