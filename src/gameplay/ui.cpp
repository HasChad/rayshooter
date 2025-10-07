#include "gameplay/ui.h"
#include "gameplay/player.h"
#include "globals.h"
#include "raylib.h"

void ui() {
    DrawText(TextFormat("Health: %.0f", player.health), 5, screen.height - 20, 20, ORANGE);
    DrawText(TextFormat("Ammo: "), screen.width - 80, screen.height - 20, 20, ORANGE);
};
