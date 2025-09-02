#include <Feurgame-Lib/Display.hpp>

#include <cmath>

sf::Vector2f Clickable::get_pos() const {
    return pos_;
}

bool Clickable::is_clicked(const sf::Vector2f& click_pos) const {
    return sqrt(pow(click_pos.x - pos_.x, 2) + pow(click_pos.y - pos_.y, 2)) < CLICKABLE_MARGIN;
}

void Movable::set_pos(const sf::Vector2f& pos) {
    pos_ = pos;
}

void Movable::set_x(float x) {
    pos_.x = x;
}

void Movable::set_y(float y) {
    pos_.y = y;
}

void BaseDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::View current_view = window_->getView();
    window_->setView(window_->getDefaultView());
    for (auto i = widgets_.begin(); i != widgets_.end(); i++)
        if (i->second->canDisplay())
            i->second->draw(target, states);
    window_->setView(current_view);
}
