#pragma once

#include "IO.hpp"

#include <fstream>
#include <map>
#include <string>
#include <vector>

using army_vector = std::vector<army_ptr>;
using box_matrix = std::vector<std::vector<Box>>;
using regions_vector = std::vector<region_ptr>;

struct MapMetadata {
    std::string title, author, context, version;
};

void from_json(const nlohmann::json& j, MapMetadata& meta);

struct MapConfig {
    std::string config, img;
};

void from_json(const nlohmann::json& j, MapConfig& map_config);

class Map {
private:
    const std::string config_path_;
    std::string map_path_;
    box_matrix boxes_;
    regions_vector regions_;
    players_vector players_;
    army_vector armies_;
public:
    Map(std::string path);
    ~Map() = default;

    std::string get_path() const;
    box_matrix get_boxes() const;
    Box get_box(int x, int y) const;
    regions_vector get_regions() const;
    void set_player(int i, player_ptr new_val);
    players_vector get_players() const;
};

class MapSet {
private:
    const std::string path_;
    MapMetadata metadata_;
    std::map<std::string, MapConfig> map_configs_;
public:
    /**
     * @param number_of_players if set to 0, we don't care about the number of players
     */
    MapSet(std::string path, int number_of_players = 0);
    ~MapSet() = default;

    static std::vector<MapSet> fetch_maps_sets(int number_of_players, std::string maps_sets_path = "assets/maps");

    MapMetadata get_metadata() const;
    MapConfig get_map_config(std::string key);
    std::map<std::string, MapConfig> get_map_configs() const;

    Map* get_map(std::string key);
};
