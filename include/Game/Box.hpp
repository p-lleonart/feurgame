#pragma once

#include "Region.hpp"

#include <string>

enum TerrainType {
    Unknown = -1,
    Plains = 0,
    Mountains,
    Forests,
    Deserts,
    River,
    City,
    Sea,
};

std::string terrain_type_to_string(TerrainType type);
TerrainType string_to_terrain_type(std::string str);

class Box {
private:
    region_ptr region_;
    TerrainType type_;
public:
    Box() {}
    Box(region_ptr region, TerrainType type) : region_(region), type_(type) {};

    region_ptr get_region();
    TerrainType get_terrain_type() const;
    std::string get_terrain_type_name() const;
};
