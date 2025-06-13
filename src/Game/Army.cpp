#include "Game/Army.hpp"

std::string Unit::create_unit_name(std::string unit_type, std::string army) {
    return army + std::string(" battalion of ") + unit_type;
    // maybe add random name generator to generate smth like "3rd Infantery battalion of <insert city name>"
}

unsigned int Unit::get_id() const {
    return this->id_;
}

std::string Unit::get_name() const {
    return this->name_;
}

void Unit::set_name(std::string name) {
    this->name_ = name;
}
    
std::string Unit::get_army() const {
    return this->army_;
}

void Unit::set_army(std::string army) {
    this->army_ = army;
}

float Unit::get_health() const {
    return this->strategy_->get_health();
}

void Unit::set_health(float health) {
    this->strategy_->set_health(health);
}

void Unit::set_health_incr(float incr) {
    this->strategy_->set_health_incr(incr);
}

void Unit::set_health_scalar(float scalar) {
    this->strategy_->set_health_scalar(scalar);
}

unsigned int Unit::get_level() const {
    return this->strategy_->get_level();
}

void Unit::add_progress(float progress) {
    this->strategy_->add_progress(progress);
}

float Unit::get_morale() const {
    return this->strategy_->get_morale();
}

void Unit::set_morale(float morale) {
    this->strategy_->set_morale(morale);
}

void Unit::set_morale_scalar(float scalar) {
    this->strategy_->set_morale_scalar(scalar);
}

UnitStrategy& Unit::get_strategy() {
    return *this->strategy_;
}

void Unit::attack(Unit& enemy) {
    this->strategy_->attack(enemy.get_strategy());
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

player_ptr Unit::get_owner() {
    return this->owner_;
}

unsigned int Army::get_id() const {
    return this->id_;
}

unit_vector Army::get_units() const {
    return this->units_;
}

unit_ptr Army::get_unit(int i) {
    return this->units_[i];
}

std::string Army::get_name() const {
    return this->name_;
}

void Army::set_name(std::string name) {
    this->name_ = name;
}

player_ptr Army::get_owner() {
    return this->owner_;
}
