#pragma once

#include "raylib.h"

struct Textures {
    Texture2D player;
    Texture2D bullet;
    Texture2D cursor;
    Texture2D reloadSpinner;
    Texture2D ak47;
    Texture2D mosin;
    Texture2D glock;
    Texture2D fnx;
    Texture2D hand;
    Texture2D knife;
    Texture2D baseballbat;
    Texture2D drop;
};
inline Textures textures;

struct TerrainTextures {
    Texture2D ground;
};
inline TerrainTextures terraTex;

struct Audio {
    Music wood_ambiance;
    Music walk_forest;
    Sound reload_rifle;
    Sound reload_pistol;
    Sound ak_shot;
    Sound mosin_shot;
    Sound glock_shot;
    Sound fnx_shot;
    Sound open_drop;
};
inline Audio sounds;

void loadAssets();
