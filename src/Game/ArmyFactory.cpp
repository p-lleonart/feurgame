#include "Game/ArmyFactory.hpp"

#include <iostream>

UnitFactory* UnitFactory::getInstance() {
    if(!UnitFactory::instance_) {
        UnitFactory::instance_ = new UnitFactory();
    }
    return UnitFactory::instance_;
}

Unit UnitFactory::create(std::unique_ptr<UnitStrategy> strategy, Player& player, std::string army, std::string name, bool name_is_type) {
    if (name_is_type) {
        std::string name = Unit::createUnitName(name, army);
        return this->create(std::move(strategy), player, name, army);
    }

    Unit unit = Unit(
        std::move(strategy),
        this->last_id_,
        name,
        army,
        player
    );
    this->last_id_++;
    return unit;
}

UnitFactory* UnitFactory::instance_ = nullptr;

ArmyFactory* ArmyFactory::getInstance() {
    if(!ArmyFactory::instance_) {
        ArmyFactory::instance_ = new ArmyFactory();
    }
    return ArmyFactory::instance_;
}

Army ArmyFactory::create(unit_vector units, Player& player, std::string name) {
    this->last_id_++;
    if (units.empty())
        return Army(this->last_id_ - 1, name, player);

    return Army(this->last_id_ - 1, units, name, player);
}

ArmyFactory* ArmyFactory::instance_ = nullptr;
