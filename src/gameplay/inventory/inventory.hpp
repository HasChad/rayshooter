#pragma once

#include <raylib.h>

const float INV_WIDTH = 300.0;
const float INV_HEIGHT = 300.0;

struct Inventory {
    int slots;
    int primary;
    int secondary;
    int melee;

    void draw();
};

inline Inventory inventory = {
    .slots = 1,
    .primary = 1,
    .secondary = 1,
    .melee = 1,
};
