#include "Game/Map.hpp"

Map::Map(std::string path) : config_path_(path) {
    std::fstream f(path);
    nlohmann::json data = nlohmann::json::parse(f);

    data.at("map_path").get_to(map_path_);

    Player P;
    for (auto& p : data.at("players")) {
        from_json(p, P);
        players_.push_back(P);
    }

    Army A;
    for (auto& a : data.at("armies")) {
        from_json(a, A, players_);
        armies_.push_back(A);
    }

    Region R;
    for (auto& r : data.at("regions")) {
        from_json(r, R, players_);
        regions_.push_back(R);
    }

    Box B;
    for (auto& x : data.at("boxes")) {
        boxes_.push_back(std::vector<Box>());
        for (auto& y : data.at("boxes").at(x)) {
            from_json(y, B, regions_);
            boxes_[x].push_back(B);
        }
    }
}

std::string Map::getPath() const {
    return this->map_path_;
}

box_matrix Map::getBoxes() const {
    return this->boxes_;
}

Box Map::getBox(int x, int y) const {
    return this->boxes_[x][y];
}

regions_vector Map::getRegions() const {
    return this->regions_;
}
