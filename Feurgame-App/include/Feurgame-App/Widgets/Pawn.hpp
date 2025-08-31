#pragma once

#include <Feurgame-Lib/Army.hpp>
#include <Feurgame-Lib/City.hpp>
#include "Buttons.hpp"

class PawnWidget : public ButtonWidget {
public:
    PawnWidget(std::string icon_path, sf::Vector2f pos);
    ~PawnWidget() = default;
};

class CityPawnWidget : public PawnWidget {
private:
    city_ptr city_;
public:
    CityPawnWidget(city_ptr city) : PawnWidget("assets/city_icon.png", city->get_pos()), city_(city) {}

    void callback(const sf::Event::MouseButtonPressed& event) override;
};

class ArmyPawnWidget : public PawnWidget {
private:
    army_ptr army_;
public:
    ArmyPawnWidget(army_ptr army) : PawnWidget("assets/army_icon.png", army->get_pos()), army_(army) {}

    void callback(const sf::Event::MouseButtonPressed& event) override;
};
