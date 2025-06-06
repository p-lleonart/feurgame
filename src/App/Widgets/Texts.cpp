#include "App/Widgets/Texts.hpp"

PlayerNameTextBackgroundWidget::PlayerNameTextBackgroundWidget(sf::Vector2f pos, sf::Vector2f size) {
    this->pos_ = pos;
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(pos);
    rectangle.setFillColor(sf::Color(255, 0, 0));

    this->shape_ = rectangle;
}

void PlayerNameTextBackgroundWidget::setPosition(sf::Vector2f pos) {
    this->shape_.setPosition(pos);
    this->pos_ = pos;
}

void PlayerNameTextWidget::setStyles() const {
    std::cout << "setting styles" << std::endl;
    this->text_->setStyle(sf::Text::Bold | sf::Text::Italic);
}
