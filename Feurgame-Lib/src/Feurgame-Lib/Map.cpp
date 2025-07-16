#include <Feurgame-Lib/Map.hpp>

#include <iostream>

void from_json(const nlohmann::json& j, MapMetadata& meta) {
    j.at("title").get_to(meta.title);
    j.at("author").get_to(meta.author);
    j.at("context").get_to(meta.context);
    j.at("version").get_to(meta.version);
}

void from_json(const nlohmann::json& j, MapConfig& map_config) {
    j.at("config").get_to(map_config.config);
    j.at("image").get_to(map_config.img);
}

MapSet::MapSet(std::string path, int number_of_players) : path_(path) {
    std::fstream f(path + "/fg.json");
    nlohmann::json data = nlohmann::json::parse(f);

    from_json(data.at("metadata"), metadata_);

    MapConfig map_config;
    for (auto& i : data.at("maps").items()) {
        if (number_of_players != 0
            && i.key().substr(0, i.key().find("_")) != std::to_string(number_of_players))
            continue;
        
        from_json(i.value(), map_config);
        map_configs_[i.key()] = map_config;
    }
}

std::vector<MapSet> MapSet::fetch_maps_sets(int number_of_players, std::string maps_sets_path) {
    // list of subdirectories of map_sets_path

    // for each of them, create a MapSet
    // rendering will be done in ChooseMapLayout.

    return {};
}

MapMetadata MapSet::get_metadata() const {
    return metadata_;
}

MapConfig MapSet::get_map_config(std::string key) {
    return map_configs_[key];
}

std::map<std::string, MapConfig> MapSet::get_map_configs() const {
    return map_configs_;
}

Map* MapSet::get_map(std::string key) {
    return new Map(path_ + "/" + get_map_config(key).config);
}

Map::Map(std::string path) : config_path_(path) {
    std::fstream f(path);
    nlohmann::json data = nlohmann::json::parse(f);

    std::cout << "begin" << std::endl;

    data.at("map_path").get_to(map_path_);

    // from_json(data.at("metadata"), metadata_);
    
    std::cout << "map parsed" << std::endl;

    for (auto& p : data.at("players")) {
        player_ptr P;
        from_json(p, P);
        players_.push_back(P);
    }
    
    std::cout << "players parsed" << std::endl;

    for (auto& a : data.at("armies")) {
        army_ptr A;
        from_json(a, A, players_);
        armies_.push_back(A);
    }
    std::cout << "armies parsed" << std::endl;

    for (auto& r : data.at("regions")) {
        region_ptr R;
        from_json(r, R, players_);
        regions_.push_back(R);
    }
    
    std::cout << "regions parsed" << std::endl;

    int i = 0;
    for (auto& y : data.at("boxes")) {
        Box B;
        boxes_.push_back(std::vector<Box>());
        int j = 0;
        for (auto& x : y) {
            from_json(x, B, regions_);
            boxes_[i].push_back(B);
            j++;
        }
        i++;
    }
    std::cout << "boxes parsed" << std::endl;

    for (auto i : players_) {
        std::cout << i->get_name() << " " << i->is_bot() << std::endl;
    }
    
    for (auto i : regions_) std::cout << i->get_name() << " " << i->get_owner()->get_name() << std::endl;
    
    
    std::cout<<armies_[0]->get_owner()->get_name() << std::endl;
    for(auto i: armies_) {
        std::cout << i->get_id() << " "<< i->get_name() << " " << i->get_owner()->get_name() << std::endl;
        for (auto j: i->get_units()) {
            std::cout << "      " << j->get_id()<< " " << j->get_name() << " "<<j->get_owner()->get_name() << std::endl;
        }
    }
    for (auto i : regions_) {
        std::cout << i->get_id() << " "<<i->get_name() << " " << i->get_owner()->get_name() << " "<< i->get_garrison()->get_name() << std::endl;
        for (auto j : i->get_garrison()->get_units()) std::cout << "    " <<j->get_id() << " "<< j->get_name()<< " "<<j->get_owner()->get_name() << std::endl;
    }
}

// MapMetadata Map::get_metadata() const {
//     return metadata_;
// }

std::string Map::get_path() const {
    return this->map_path_;
}

box_matrix Map::get_boxes() const {
    return this->boxes_;
}

Box Map::get_box(int x, int y) const {
    return this->boxes_[x][y];
}

regions_vector Map::get_regions() const {
    return this->regions_;
}

void Map::set_player(int i, player_ptr new_val) {
    players_[i] = new_val;
}

players_vector Map::get_players() const {
    return players_;
}
