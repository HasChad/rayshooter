#pragma once

struct MainMenu {
    bool quit;

    void ui();
};

inline MainMenu mainMenu{ .quit = false };
