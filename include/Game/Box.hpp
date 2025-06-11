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
    Region& region_;
    TerrainType type_;
public:
    Box(Region region = DEFAULT_REGION) : region_(region) {}
    Box(Region& region, TerrainType type) : region_(region), type_(type) {};

    void copy(Box& box) const;

    Region& getRegion() const;
    TerrainType getTerrainType() const;
    std::string getTerrainTypeName() const;
};
