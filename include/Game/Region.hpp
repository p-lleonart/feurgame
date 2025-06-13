#pragma once

#include "Army.hpp"

class Region {
private:
    unsigned int id_;
    army_ptr garrison_;
    std::string name_;
    std::string city_name_;
    player_ptr owner_;
public:
    Region() {}
    Region(
        unsigned int region_id,
        army_ptr garrison,
        player_ptr owner,
        std::string name,
        std::string city_name
    ) :
        id_(region_id),
        garrison_(garrison),
        owner_(owner),
        name_(name),
        city_name_(city_name) {}
    ~Region() = default;

    unsigned int get_id() const;
    army_ptr get_garrison();
    std::string get_name() const;
    std::string get_city_name() const;
    player_ptr get_owner();
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

    Region create(army_ptr garrison, player_ptr owner, std::string name, std::string city_name);
};
