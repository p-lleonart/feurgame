#include <Feurgame-Lib/Game.hpp>

#include <iostream>

Game* Game::instance_ = nullptr;

Game* Game::get_instance() {
    if (!instance_) {
        MapMetadata meta{};
        Map map{"assets/default_map.json"};
        instance_ = new Game(meta, &map);
    }
    return instance_;
};

Game* Game::get_instance(const MapMetadata& metadata, Map* map) {
    if (!instance_)
        instance_ = new Game(metadata, map);
    return instance_;
};

Map* Game::get_map() const {
    return this->map_;
}

MapMetadata Game::get_map_meta() const {
    return this->map_meta_;
}
