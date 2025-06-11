#include "Game/Player.hpp"

void Player::copy(Player& player) const {
    player.name_ = this->name_;
    player.color_ = this->color_;
    player.is_alive_ = this->is_alive_;
}

std::string Player::getName() const {
    return this->name_;
}

sf::Color Player::getColor() const {
    return this->color_;
}

bool Player::isAlive() const {
    return this->is_alive_;
}

void Player::kill() {
    this->is_alive_ = false;
}
