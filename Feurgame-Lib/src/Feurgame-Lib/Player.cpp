#include <Feurgame-Lib/Player.hpp>

std::string Player::get_name() const {
    return this->name_;
}

sf::Color Player::get_color() const {
    return this->color_;
}

bool Player::is_alive() const {
    return this->is_alive_;
}

void Player::kill() {
    this->is_alive_ = false;
}
