#pragma once

#include "Army.hpp"
#include "IO.hpp"
#include "Map.hpp"
#include "Player.hpp"

class Game {
private:
    Game(const MapMetadata& metadata, Map* map) : map_meta_(metadata), map_(map) {};

    static Game* instance_;
    Map* map_;
    const MapMetadata map_meta_;
    unsigned int current_player_ = 0;
public:
    Game(const Game&) = delete;
    void operator=(const Game&) = delete;
    ~Game() = default;

    /** Note: if the Game instance doesn't exists, it will create a new empty Game instance */
    static Game* get_instance();

    /** Note: if the Game instance already exists, it will not be overritten */
    static Game* get_instance(const MapMetadata& metadata, Map* map);

    Map* get_map() const;
    MapMetadata get_map_meta() const;
};
