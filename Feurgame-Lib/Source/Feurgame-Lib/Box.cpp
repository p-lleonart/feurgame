#include <Feurgame-Lib/Map.hpp>

std::string terrain_type_to_string(TerrainType type) {
    switch (type) {
        case Plains: return "Plains";
        case Mountains: return "Mountains";
        case Forests: return "Forests";
        case Deserts: return "Deserts";
        case River: return "River";
        case City: return "City";
        case Sea: return "Sea";
        default: return "Unknown";
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

region_ptr Box::get_region() {
    return this->region_;
}

TerrainType Box::get_terrain_type() const {
    return this->type_;
}

std::string Box::get_terrain_type_name() const {
    return terrain_type_to_string(this->type_);
}
