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
    Texture2D dropItems;
};
inline Textures textures;

struct TerrainTextures {
    Texture2D ground;
};
inline TerrainTextures terraTex;

struct Sounds {
    Music wood_ambiance;
    Music walk_forest;
    Sound ak_1;
    Sound ak_2;
    Sound ak_3;
};
inline Sounds sounds;

void loadAssets();
