#pragma once

#include "nlohmann/json.hpp"

#include "ArmyFactory.hpp"
#include "Box.hpp"
#include "Region.hpp"

using players_vector = std::vector<player_ptr>;
using regions_vector = std::vector<region_ptr>;

void from_json(const nlohmann::json& j, player_ptr& player);

void from_json(const nlohmann::json& j, unit_ptr& unit, players_vector& players);
void from_json(const nlohmann::json& j, army_ptr& army, players_vector& players);

void from_json(const nlohmann::json& j, region_ptr& region, players_vector& players);
void from_json(const nlohmann::json& j, Box& box, regions_vector& regions);
