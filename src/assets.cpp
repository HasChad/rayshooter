#include "assets.hpp"
#include "raylib.h"

void loadAssets() {
    textures.player = LoadTexture("assets/sprites/player.png");
    textures.cursor = LoadTexture("assets/sprites/cursor.png");
    textures.reloadSpinner = LoadTexture("assets/sprites/reload-spinner.png");
    textures.ak47 = LoadTexture("assets/sprites/weapons/ak47.png");
    textures.mosin = LoadTexture("assets/sprites/weapons/mosin.png");
    textures.glock = LoadTexture("assets/sprites/weapons/glock.png");
    textures.fnx = LoadTexture("assets/sprites/weapons/fnx.png");
    textures.hand = LoadTexture("assets/sprites/weapons/hand.png");
    textures.knife = LoadTexture("assets/sprites/weapons/knife.png");
    textures.baseballbat = LoadTexture("assets/sprites/weapons/baseballbat.png");

    textures.drop = LoadTexture("assets/sprites/drop.png");
    textures.target = LoadTexture("assets/sprites/target.png");

    textures.particle_metal_hit = LoadTexture("assets/sprites/metal-impact.png");

    terraTex.ground = LoadTexture("assets/sprites/dirt.png");

    sounds.wood_ambiance = LoadMusicStream("assets/sounds/wood_ambiance.mp3");
    sounds.run_1 = LoadMusicStream("assets/sounds/run_1.ogg");
    sounds.run_1 = LoadMusicStream("assets/sounds/run_2.ogg");
    sounds.run_1 = LoadMusicStream("assets/sounds/run_3.ogg");

    sounds.reload_rifle = LoadSound("assets/sounds/reload_rifle.ogg");
    sounds.reload_pistol = LoadSound("assets/sounds/reload_pistol.ogg");

    sounds.ak_shot = LoadSound("assets/sounds/ak_shot.ogg");
    sounds.mosin_shot = LoadSound("assets/sounds/mosin_shot.ogg");
    sounds.glock_shot = LoadSound("assets/sounds/glock_shot.ogg");
    sounds.fnx_shot = LoadSound("assets/sounds/fnx_shot.ogg");

    sounds.open_drop = LoadSound("assets/sounds/open_drop.ogg");
    sounds.metal_impact = LoadSound("assets/sounds/metal_impact.ogg");
}
