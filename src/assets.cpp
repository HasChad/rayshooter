#include "assets.hpp"
#include "raylib.h"

void loadAssets() {
    textures.player = LoadTexture("sprites/player.png");
    textures.bullet = LoadTexture("sprites/bullet.png");
    textures.cursor = LoadTexture("sprites/cursor.png");
    textures.reloadSpinner = LoadTexture("sprites/reload-spinner.png");
    textures.ak47 = LoadTexture("sprites/weapons/ak47.png");
    textures.mosin = LoadTexture("sprites/weapons/mosin.png");
    textures.glock = LoadTexture("sprites/weapons/glock.png");
    textures.fnx = LoadTexture("sprites/weapons/fnx.png");
    textures.hand = LoadTexture("sprites/weapons/hand.png");
    textures.knife = LoadTexture("sprites/weapons/knife.png");
    textures.baseballbat = LoadTexture("sprites/weapons/baseballbat.png");

    textures.drop = LoadTexture("sprites/drop.png");
    textures.dropItems = LoadTexture("sprites/drop-items.png");

    terraTex.ground = LoadTexture("sprites/beton.png");

    sounds.wood_ambiance = LoadMusicStream("sounds/wood_ambiance.mp3");
    sounds.walk_forest = LoadMusicStream("sounds/walk_forest.mp3");

    sounds.ak_1 = LoadSound("sounds/ak_1.ogg");
    sounds.ak_2 = LoadSound("sounds/ak_2.ogg");
    sounds.ak_3 = LoadSound("sounds/ak_3.ogg");
}
