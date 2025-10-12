#pragma once

#include "raylib.h"

struct Textures {
    Texture2D player;
    Texture2D bullet;
    Texture2D cursor;
};
inline Textures textures;

struct TerrainTextures {
    Texture2D ground;
};
inline TerrainTextures terraTex;

struct Sounds {
    Music wood_ambiance;
    Music walk_forest;
    Sound gunshot;
};
inline Sounds sounds;

void loadAssets();
