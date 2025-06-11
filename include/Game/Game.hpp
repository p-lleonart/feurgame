#pragma once

#include "Army.hpp"
#include "IO.hpp"
#include "Map.hpp"
#include "Player.hpp"

// using players_vector = std::vector<Player>;

class Game {
private:
    Map map_;
    // army_vector armies_;
    // players_vector players_;
    unsigned int current_player_ = 0;
public:
    Game(std::string map_path) : map_(Map(map_path)) {};
    ~Game() = default;

    Map getMap();
    // army_vector getArmies();
    // players_vector getPlayers();
};
