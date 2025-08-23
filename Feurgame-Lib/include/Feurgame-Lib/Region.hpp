#pragma once

#include "Army.hpp"
#include "City.hpp"

class Region : public Entity, public HasOwner {
private:
    city_ptr city_;
public:
    Region() {}
    Region(
        unsigned int region_id,
        sf::Vector2f city_pos,
        army_ptr garrison,
        player_ptr owner,
        std::string name,
        std::string city_name
    ) : Entity(name, region_id), HasOwner(owner) {
        city_ = std::make_shared<City>(city_pos, city_name, garrison, owner);
    }
    ~Region() = default;

    city_ptr get_city();
};

using region_ptr = std::shared_ptr<Region>;

class RegionFactory {
private:
    static RegionFactory* instance_;
    unsigned int last_id_ = 1;

    RegionFactory() {};
public:
    RegionFactory(const RegionFactory &factory) = delete;
    void operator=(const RegionFactory&) = delete;
    ~RegionFactory() = default;

    static RegionFactory* get_instance();

    Region create(sf::Vector2f city_pos, army_ptr garrison, player_ptr owner, std::string name, std::string city_name);
};
