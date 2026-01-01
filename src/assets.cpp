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

    terraTex.ground = LoadTexture("sprites/dirt.png");

    sounds.wood_ambiance = LoadMusicStream("sounds/wood_ambiance.mp3");
    sounds.walk_forest = LoadMusicStream("sounds/walk_forest.mp3");

    sounds.reload_rifle = LoadSound("sounds/reload_rifle.ogg");
    sounds.reload_pistol = LoadSound("sounds/reload_pistol.ogg");

    sounds.ak_shot = LoadSound("sounds/ak_1.ogg");
    sounds.mosin_shot = LoadSound("sounds/mosin_1.ogg");
    sounds.glock_shot = LoadSound("sounds/glock19_single_1.ogg");
    sounds.fnx_shot = LoadSound("sounds/fnx_1.ogg");

    sounds.open_drop = LoadSound("sounds/open_drop.ogg");
}
