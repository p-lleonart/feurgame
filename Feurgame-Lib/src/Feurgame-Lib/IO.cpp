#include <Feurgame-Lib/IO.hpp>

#include <Feurgame-Lib/ArmyFactory.hpp>

#include <iostream>

void from_json(const nlohmann::json& j, player_ptr& player) {
    std::string name;
    sf::Color color;
    bool is_bot;
    j.at("name").get_to(name);
    j.at("color").at("red").get_to(color.r);
    j.at("color").at("green").get_to(color.g);
    j.at("color").at("blue").get_to(color.b);
    j.at("color").at("alpha").get_to(color.a);

    try {
        j.at("bot").get_to(is_bot);
    } catch (nlohmann::json::out_of_range& e) {
        if (e.id == 403) {
            is_bot = false;
        } else {
            std::cerr << "Error: can't parsing player" << std::endl;
            exit(1);
        }
    }

    player = std::make_shared<Player>(name, color, is_bot);
}

player_ptr _get_player(const nlohmann::json& j, players_vector& players) {
    std::string player_name;
    j.at("player_name").get_to(player_name);

    int i = 0;
    while (i < players.size() && players[i]->get_name() != player_name) {
        if (players[i]->get_name() != player_name)
            i++;
    }
    if (i == players.size()) {
        std::cerr << "Error: can't parse unit : player '" << player_name << "' doesn't exist." << std::endl;
        exit(1);
    }
    return players[i];  // else the i id the index of the player.
}

region_ptr _get_region(const nlohmann::json& j, regions_vector& regions) {
    unsigned int region_id;
    j.at("region_id").get_to(region_id);

    int i = 0;
    while (i < regions.size() && regions[i]->get_id() != region_id) {
        if (regions[i]->get_id() != region_id)
            i++;
    }
    if (i == regions.size()) {
        std::cerr << "Error: can't parse box : region '" << region_id << "' doesn't exist." << std::endl;
        exit(1);
    }
    return regions[i];
}

void from_json(const nlohmann::json& j, region_ptr& region, players_vector& players) {
    std::string name, city_name;
    j.at("name").get_to(name);
    j.at("city_name").get_to(city_name);

    player_ptr player = _get_player(j, players);
    army_ptr garrison;
    from_json(j.at("garrison"), garrison, players);

    sf::Vector2f city_pos;
    j.at("pos").at("x").get_to(city_pos.x);
    j.at("pos").at("y").get_to(city_pos.y);

    region = std::make_shared<Region>(
        RegionFactory::get_instance()->create(city_pos, garrison, player, name, city_name)
    );
}

void from_json(const nlohmann::json& j, Box& box, regions_vector& regions) {
    std::string terrain_str;
    j.at("terrain").get_to(terrain_str);

    box = Box(_get_region(j, regions), string_to_terrain_type(terrain_str));
}

template<typename T>
std::unique_ptr<T> _instanciate_unit_strategy() {
    return std::make_unique<T>();
}

// TODO: try to improve this
std::unique_ptr<UnitStrategy> _get_unit_strategy(const nlohmann::json& j) {
    std::string strategy_name;
    j.at("type").get_to(strategy_name);

    if (strategy_name == "infantery") {
        return std::move(_instanciate_unit_strategy<InfanteryUnitStrategy>());
    } else if (strategy_name == "cavalery") {
        return std::move(_instanciate_unit_strategy<CavaleryUnitStrategy>());
    } else if (strategy_name == "artillery") {
        return std::move(_instanciate_unit_strategy<ArtilleryUnitStrategy>());
    }
    return nullptr;
}

void from_json(const nlohmann::json& j, unit_ptr& unit, players_vector& players) {
    player_ptr player = _get_player(j, players);
    std::unique_ptr<UnitStrategy> unit_strategy = _get_unit_strategy(j);

    std::string army_name;
    j.at("army").get_to(army_name);

    std::string name;
    bool name_is_type = false;

    // if "name" is undefined, create a name depending on the unit type.
    try {
        j.at("name").get_to(name);
    } catch (nlohmann::json::out_of_range& e) {
        if (e.id == 403) {
            j.at("type").get_to(name);
            name_is_type = true;
        } else {
            std::cerr << "Error: can't parse unit" << std::endl;
            exit(1);
        }
    }

    unit = std::make_shared<Unit>(
        UnitFactory::get_instance()->create(
            std::move(unit_strategy),
            player,
            army_name,
            name,
            name_is_type
        )
    );
}

void from_json(const nlohmann::json& j, army_ptr& army, players_vector& players) {
    player_ptr player = _get_player(j, players);
    std::string name;
    j.at("name").get_to(name);

    sf::Vector2f pos;

    try {
        j.at("pos").at("x").get_to(pos.x);
        j.at("pos").at("y").get_to(pos.y);
    } catch (nlohmann::json::out_of_range& e) {
        if (e.id == 403) {
            pos = {0, 0};
        } else {
            std::cerr << "Error: can't parse army : " << name << std::endl;
            exit(1);
        }
    }
    
    unit_vector units;

    for (auto& el: j.at("units")) {
        unit_ptr unit;
        from_json(el, unit, players);
        units.push_back(unit);
    }

    army = std::make_shared<Army>(ArmyFactory::get_instance()->create(units, player, pos, name));
}
