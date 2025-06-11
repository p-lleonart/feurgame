#include "Game/Army.hpp"

std::string Unit::createUnitName(std::string type, std::string army) {
    return army + " battalion of " + type;
    // maybe add random name generator to generate smth like "3rd Infantery battalion of <insert city name>"
}

void Unit::copy(Unit& unit) const {
    unit.id_ = this->id_;
    unit.strategy_ = std::make_unique<UnitStrategy>(*this->strategy_);
    unit.owner_ = this->owner_;
    unit.army_ = this->army_;
    unit.name_ = this->name_;
}

unsigned int Unit::getId() const {
    return this->id_;
}

std::string Unit::getName() const {
    return this->name_;
}

void Unit::setName(std::string name) {
    this->name_ = name;
}
    
std::string Unit::getArmy() const {
    return this->army_;
}

void Unit::setArmy(std::string army) {
    this->army_ = army;
}

float Unit::getHealth() const {
    return this->strategy_->getHealth();
}

void Unit::setHealth(float health) {
    this->strategy_->setHealth(health);
}

void Unit::setHealthIncr(float incr) {
    this->strategy_->setHealthIncr(incr);
}

void Unit::setHealthScalar(float scalar) {
    this->strategy_->setHealthScalar(scalar);
}

unsigned int Unit::getLevel() const {
    return this->strategy_->getLevel();
}

void Unit::addProgress(float progress) {
    this->strategy_->addProgress(progress);
}

float Unit::getMorale() const {
    return this->strategy_->getMorale();
}

void Unit::setMorale(float morale) {
    this->strategy_->setMorale(morale);
}

void Unit::setMoraleScalar(float scalar) {
    this->strategy_->setMoraleScalar(scalar);
}

UnitStrategy& Unit::getStrategy() {
    return *this->strategy_;
}

void Unit::attack(Unit& enemy) {
    this->strategy_->attack(enemy.getStrategy());
}

void Unit::get_possible_targets() const {
    this->strategy_->get_possible_targets();
}

void Unit::move() {
    this->strategy_->move();
}

void Unit::heal() {
    this->strategy_->heal();
}

Player& Unit::getOwner() const {
    return this->owner_;
}

void Army::copy(Army& army) const {
    army.id_ = this->id_;
    // army.units_ = this->units_;
    Unit U;
    for (Unit u : this->units_) {
        u.copy(U);
        army.units_.push_back(U);
    }
    army.name_ = this->name_;
    army.owner_ = this->owner_;
}

unsigned int Army::getId() const {
    return this->id_;
}

unit_vector Army::getUnits() const {
    return this->units_;
}

Unit& Army::getUnit(int i) {
    return this->units_[i];
}

std::string Army::getName() const {
    return this->name_;
}

void Army::setName(std::string name) {
    this->name_ = name;
}

Player& Army::getOwner() const {
    return this->owner_;
}
