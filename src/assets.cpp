#include "assets.hpp"
#include "raylib.h"

void loadAssets() {
    textures.player = LoadTexture("sprites/player.png");
    textures.bullet = LoadTexture("sprites/bullet.png");
    textures.cursor = LoadTexture("sprites/cursor.png");
    textures.reloadSpinner = LoadTexture("sprites/reload-spinner.png");
    textures.ak47 = LoadTexture("sprites/ak47.png");
    textures.glock = LoadTexture("sprites/glock.png");
    textures.hand = LoadTexture("sprites/hand.png");
    textures.knife = LoadTexture("sprites/knife.png");
    textures.dropItems = LoadTexture("sprites/drop-items.png");

    terraTex.ground = LoadTexture("sprites/beton.png");

    sounds.wood_ambiance = LoadMusicStream("sounds/wood_ambiance.mp3");
    sounds.walk_forest = LoadMusicStream("sounds/walk_forest.mp3");
    sounds.gunshot = LoadSound("sounds/gunshot.mp3");
}
