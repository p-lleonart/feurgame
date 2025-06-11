#pragma once

#include "IO.hpp"

#include <fstream>
#include <string>
#include <vector>

using army_vector = std::vector<Army>;
using box_matrix = std::vector<std::vector<Box>>;
using regions_vector = std::vector<Region>;

/**
 * TODO: choose the correct config file for the n players registered.
 * 
 * Each "map" have a strict number of player so you need to have 4 (and maybe more later) of them to
 * be used anytime. (the ``map_path`` field in ``fg.json`` will be a map
 * {nb_of_players => map_config_path})
 */
class Map {
private:
    const std::string config_path_;
    std::string map_path_;
    std::string map_context;
    std::string map_author;
    box_matrix boxes_;
    regions_vector regions_;
    players_vector players_;
    army_vector armies_;
public:
    Map(std::string path);
    ~Map() = default;

    std::string getPath() const;
    box_matrix getBoxes() const;
    Box getBox(int x, int y) const;
    regions_vector getRegions() const;
};
