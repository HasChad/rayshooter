#include "assets.h"

void loadAssets() {
    textures.player = LoadTexture("sprites/player.png");
    textures.bullet = LoadTexture("sprites/bullet.png");
    textures.cursor = LoadTexture("sprites/cursor.png");
    textures.bg = LoadTexture("sprites/beton.png");

    sounds.wood_ambiance = LoadMusicStream("sounds/wood_ambiance.mp3");
    sounds.walk_forest = LoadMusicStream("sounds/walk_forest.mp3");
    sounds.gunshot = LoadSound("sounds/gunshot.mp3");
}
