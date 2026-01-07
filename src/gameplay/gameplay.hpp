#pragma once

#include "assets.hpp"
#include "gameplay/camera.hpp"
#include "gameplay/inventory/inventory.hpp"
#include "gameplay/player.hpp"
#include "raylib.h"
#include "raymath.h"

class Gameplay {
  public:
    void controller();
    void run();
    void draw();
    void ui();
};
inline Gameplay gameplay;

class Cursor {
  public:
    Vector2 pos = GetScreenToWorld2D(GetMousePosition(), gameCamera.camera);

    void update() { pos = GetScreenToWorld2D(GetMousePosition(), gameCamera.camera); }

    void draw() {
        DrawTexture(
            textures.cursor,
            pos.x - textures.cursor.width / 2.0,
            pos.y - textures.cursor.width / 2.0,
            WHITE
        );
    }
};
inline Cursor cursor;

class Drop {
  public:
    Vector2 pos = { 0, 0 };
    bool available = true;
    bool canInteract;

    void update() {
        if (available) {
            checkDistance();
            getSupply();
        }
    }

    void checkDistance() { canInteract = Vector2Distance(player.pos, pos) < 50 ? true : false; }

    void getSupply() {
        if (IsKeyPressed(KEY_E)) {
            if (canInteract) {
                inventory.primary.prop.ammoCount = inventory.primary.prop.ammoCapacity;
                inventory.secondary.prop.ammoCount = inventory.secondary.prop.ammoCapacity;
                available = false;
                // play sound
            } else {
                return;
            }
        }
    }

    void draw() {
        if (!available)
            return;

        float frame = canInteract ? textures.drop.width / 2 : 0;

        Rectangle frameRec = {
            frame,
            0,
            (float)textures.drop.width / 2,
            (float)textures.drop.height,
        };

        DrawTextureRec(
            textures.drop,
            frameRec,
            {
                pos.x - frameRec.width / 2,
                pos.y - frameRec.height / 2,
            },
            WHITE
        );
    }
};
inline Drop drop;

class DummyTarget {
  public:
    Vector2 pos = { 0, -100 };
    bool hit = false;

    void isHit() {
        if (hit) {
            // play sound and make contact sprite animation
        }
    }

    void draw() {
        DrawTexture(
            textures.target,
            pos.x - static_cast<float>(textures.target.width) / 2,
            pos.y - static_cast<float>(textures.target.height) / 2,
            WHITE
        );

        DrawCircleLinesV(pos, 16, PINK);
    }
};
inline DummyTarget target;
