#pragma once

#include "nlohmann/json.hpp"

#include "ArmyFactory.hpp"
#include "Box.hpp"
#include "Region.hpp"

using players_vector = std::vector<Player>;
using regions_vector = std::vector<Region>;

void from_json(const nlohmann::json& j, Player& player);

void from_json(const nlohmann::json& j, Unit& unit, players_vector players);
void from_json(const nlohmann::json& j, Army& army, players_vector players);

void from_json(const nlohmann::json& j, Region& region, players_vector players);
void from_json(const nlohmann::json& j, Box& box, regions_vector regions);
