#include "App/Widgets/Texts.hpp"

void PlayerNameTextWidget::setStyles() const {
    this->text_->setStyle(sf::Text::Bold | sf::Text::Italic);
}
