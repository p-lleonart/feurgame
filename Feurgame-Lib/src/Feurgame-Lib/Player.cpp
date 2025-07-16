#include <Feurgame-Lib/Player.hpp>

void Player::set_name(const std::string& new_val) {
    name_ = new_val;
}

std::string Player::get_name() const {
    return this->name_;
}

sf::Color Player::get_color() const {
    return this->color_;
}

bool Player::is_alive() const {
    return this->is_alive_;
}

bool Player::is_bot() const {
    return this->is_bot_;
}

void Player::kill() {
    this->is_alive_ = false;
}
