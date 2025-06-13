#include "Game/Region.hpp"

unsigned int Region::get_id() const {
    return this->id_;
}

army_ptr Region::get_garrison() {
    return this->garrison_;
}

std::string Region::get_name() const {
    return this->name_;
}

std::string Region::get_city_name() const {
    return this->city_name_;
}

player_ptr Region::get_owner() {
    return this->owner_;
}

RegionFactory* RegionFactory::get_instance() {
    if (!RegionFactory::instance_) {
        RegionFactory::instance_ = new RegionFactory();
    }
    return RegionFactory::instance_;
}

Region RegionFactory::create(army_ptr garrison, player_ptr owner, std::string name, std::string city_name) {
    Region region = Region(this->last_id_, garrison, owner, name, city_name);
    this->last_id_++;
    return region;
}

RegionFactory* RegionFactory::instance_ = nullptr;
