#include <Feurgame-Lib/Region.hpp>

city_ptr Region::get_city() {
    return city_;
}

RegionFactory* RegionFactory::get_instance() {
    if (!RegionFactory::instance_) {
        RegionFactory::instance_ = new RegionFactory();
    }
    return RegionFactory::instance_;
}

Region RegionFactory::create(sf::Vector2f city_pos, army_ptr garrison, player_ptr owner, std::string name, std::string city_name) {
    Region region = Region(this->last_id_, city_pos, garrison, owner, name, city_name);
    this->last_id_++;
    return region;
}

RegionFactory* RegionFactory::instance_ = nullptr;
