#include "Game/Region.hpp"

void Region::copy(Region& region) const {
    region.id_ = id_;
    garrison_.copy(region.garrison_);
    region.name_ = name_;
    region.city_name_ = city_name_;
    region.owner_ = owner_;
}

unsigned int Region::getId() const {
    return this->id_;
}

Army& Region::getArmy() {
    return this->garrison_;
}

std::string Region::getName() const {
    return this->name_;
}

std::string Region::getCityName() const {
    return this->city_name_;
}

Player& Region::getPlayer() {
    return this->owner_;
}

RegionFactory* RegionFactory::getInstance() {
    if (!RegionFactory::instance_) {
        RegionFactory::instance_ = new RegionFactory();
    }
    return RegionFactory::instance_;
}

Region RegionFactory::create(Army& garrison, Player& owner, std::string name, std::string city_name) {
    Region region = Region(this->last_id_, garrison, owner, name, city_name);
    this->last_id_++;
    return region;
}

RegionFactory* RegionFactory::instance_ = nullptr;
