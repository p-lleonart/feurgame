#include "Game/Map.hpp"

std::string terrain_type_to_string(TerrainType type) {
    switch (type) {
        case Plains: return "Plains";
        case Mountains: return "Mountains";
        case Forests: return "Forests";
        case Deserts: return "Deserts";
        case River: return "River";
        case City: return "City";
        case Sea: return "Sea";
        default: return "";
    }
}

TerrainType string_to_terrain_type(std::string str) {
    if (str == "Plains") return Plains;
    if (str == "Mountains") return Mountains;
    if (str == "Forests") return Forests;
    if (str == "Deserts") return Deserts;
    if (str == "River") return River;
    if (str == "City") return City;
    if (str == "Sea") return Sea;
    return Unknown;
}

void Box::copy(Box& box) const {
    region_.copy(box.region_);
    box.type_ = type_;
}

Region& Box::getRegion() const {
    return this->region_;
}

TerrainType Box::getTerrainType() const {
    return this->type_;
}

std::string Box::getTerrainTypeName() const {
    return terrain_type_to_string(this->type_);
}
