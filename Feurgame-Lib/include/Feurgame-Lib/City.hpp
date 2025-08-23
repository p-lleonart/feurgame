#pragma once

#include "Army.hpp"
#include "Display.hpp"

static int CITY_CURRENT_ID = 0;

class City : public Entity, public HasOwner, public Clickable {
private:
    army_ptr garrison_;
public:
    City(sf::Vector2f pos, std::string name, army_ptr garrison, player_ptr owner)
        : Entity(name, CITY_CURRENT_ID), HasOwner(owner), Clickable(pos), garrison_(garrison) {
        CITY_CURRENT_ID++;
    }

    army_ptr get_garrison() {
        return garrison_;
    }
};

using city_ptr = std::shared_ptr<City>;
using city_vector = std::vector<city_ptr>;
