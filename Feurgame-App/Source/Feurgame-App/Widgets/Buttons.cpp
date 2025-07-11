#include <Feurgame-App/Widgets/Buttons.hpp>

bool ButtonWidget::button_clicked(sf::Vector2i mouse_pos) const {
    sf::Vector2f btnPos = this->getPosition();
    sf::Vector2f btnSz = this->getSize();

    return btnPos.x <= mouse_pos.x
        && mouse_pos.x <= btnPos.x + btnSz.x
        && btnPos.y <= mouse_pos.y
        && mouse_pos.y <= btnPos.y + btnSz.y;
}
