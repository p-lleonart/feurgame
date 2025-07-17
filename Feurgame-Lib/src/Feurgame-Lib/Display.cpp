#include <Feurgame-Lib/Display.hpp>

void Movable::set_pos(const sf::Vector2f& pos) {
    pos_ = pos;
}

void Movable::set_x(float x) {
    pos_.x = x;
}

void Movable::set_y(float y) {
    pos_.y = y;
}

sf::Vector2f Movable::get_pos() const {
    return pos_;
}
