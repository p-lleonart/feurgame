#include <Feurgame-Lib/UnitStrategy.hpp>

void UnitStrategy::attack(UnitStrategy& enemy) {
    // another calc must be found (including unit type)
    enemy.set_health_incr(- this->level_ * (this->morale_ + this->health_) / 10);

    enemy.attack(*this);
}

void UnitStrategy::heal() {
    this->set_health_scalar(1.2);
}

float UnitStrategy::get_health() const {
    return this->health_;
}

void UnitStrategy::set_health(float health) {
    this->health_ = health;
    if (this->health_ > 100) this->health_ = 100;
    else if (this->health_ < 0) this->health_ = 0;
}

void UnitStrategy::set_health_incr(float incr) {
    this->set_health(this->health_ + incr);
}

void UnitStrategy::set_health_scalar(float scalar) {
    this->set_health(this->health_ * scalar);
}

unsigned int UnitStrategy::get_level() const {
    return this->level_;
}

void UnitStrategy::add_progress(float progress) {
    this->progress_ += progress;
    if (this->progress_ >= 100) {
        this->progress_ = 0;
        this->level_++;
    }
}

float UnitStrategy::get_morale() const {
    return this->morale_;
}

void UnitStrategy::set_morale(float morale) {
    this->morale_ = morale;
    if (this->morale_ < 0) this->morale_ = 0;
    else if (this->morale_ > 100) this->morale_ = 100;
}

void UnitStrategy::set_morale_scalar(float scalar) {
    this->set_morale(this->morale_ * scalar);
}
