#include "Game/UnitStrategy.hpp"

void UnitStrategy::attack(UnitStrategy& enemy) {
    // another calc must be found (including unit type)
    enemy.setHealthIncr(- this->level_ * (this->morale_ + this->health_) / 10);

    enemy.attack(*this);
}

void UnitStrategy::heal() {
    this->setHealthScalar(1.2);
}

float UnitStrategy::getHealth() const {
    return this->health_;
}

void UnitStrategy::setHealth(float health) {
    this->health_ = health;
    if (this->health_ > 100) this->health_ = 100;
    else if (this->health_ < 0) this->health_ = 0;
}

void UnitStrategy::setHealthIncr(float incr) {
    this->setHealth(this->health_ + incr);
}

void UnitStrategy::setHealthScalar(float scalar) {
    this->setHealth(this->health_ * scalar);
}

unsigned int UnitStrategy::getLevel() const {
    return this->level_;
}

void UnitStrategy::addProgress(float progress) {
    this->progress_ += progress;
    if (this->progress_ >= 100) {
        this->progress_ = 0;
        this->level_++;
    }
}

float UnitStrategy::getMorale() const {
    return this->morale_;
}

void UnitStrategy::setMorale(float morale) {
    this->morale_ = morale;
    if (this->morale_ < 0) this->morale_ = 0;
    else if (this->morale_ > 100) this->morale_ = 100;
}

void UnitStrategy::setMoraleScalar(float scalar) {
    this->setMorale(this->morale_ * scalar);
}
