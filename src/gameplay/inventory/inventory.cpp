#include "gameplay/inventory/inventory.hpp"
#include "raygui.h"

void Inventory::draw() {
    Vector2 boxSize = { INV_WIDTH, INV_HEIGHT };
    Rectangle boxRec{
        static_cast<float>(GetScreenWidth() / 2.0 - boxSize.x / 2.0),
        static_cast<float>(GetScreenHeight() / 2.0 - boxSize.y / 2.0),
        boxSize.x,
        boxSize.y,
    };

    // GuiWindowBox(boxRec, "window box");
    // GuiGroupBox(boxRec, "group box");
    GuiPanel(boxRec, "");
    // GuiLine(boxRec, "line");

    // Draw text
    DrawText("Inventory", boxRec.x + 100, boxRec.y + 2, 20, BLACK);
}
