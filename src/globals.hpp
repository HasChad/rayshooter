#pragma once

#include <raylib.h>
#include <raymath.h>

enum class GameState { MAINMENU, GAMEPLAY, PAUSE };

class Game {
  public:
    GameState state = GameState::MAINMENU;
    bool run = true;
    float volume = 0.8;
};
inline Game game;
