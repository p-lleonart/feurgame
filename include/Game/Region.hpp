#pragma once

#include "Army.hpp"

class Region {
private:
    unsigned int id_;
    Army& garrison_;
    std::string name_;
    std::string city_name_;
    Player& owner_;
public:
    Region(Army& army = DEFAULT_ARMY, Player& player = DEFAULT_PLAYER) : garrison_(army), owner_(player) {}
    Region(
        unsigned int region_id,
        Army& garrison,
        Player& player,
        std::string name,
        std::string city_name
    ) :
        id_(region_id),
        garrison_(garrison),
        owner_(player),
        name_(name),
        city_name_(city_name) {}
    ~Region() = default;

    void copy(Region& region) const;

    unsigned int getId() const;
    Army& getArmy();
    std::string getName() const;
    std::string getCityName() const;
    Player& getPlayer();
};

static Region DEFAULT_REGION = Region();

class RegionFactory {
private:
    static RegionFactory* instance_;
    unsigned int last_id_ = 0;

    RegionFactory() {};
public:
    RegionFactory(const RegionFactory &factory) = delete;
    void operator=(const RegionFactory&) = delete;
    ~RegionFactory() = default;

    static RegionFactory* getInstance();

    Region create(Army& garrison, Player& owner, std::string name, std::string city_name);
};
