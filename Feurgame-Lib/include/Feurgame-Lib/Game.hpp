#pragma once

#include "Army.hpp"
#include "IO.hpp"
#include "Map.hpp"
#include "Player.hpp"

class Game {
private:
    Map map_;
    unsigned int current_player_ = 0;
public:
    Game(Map map) : map_(map) {};
    ~Game() = default;

    Map get_map();
};
