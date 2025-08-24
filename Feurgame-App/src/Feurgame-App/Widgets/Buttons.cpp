#include <Feurgame-App/Widgets/Buttons.hpp>

bool ButtonWidget::button_clicked(const sf::Event::MouseButtonPressed& event) const {
    if (event.button != mouse_btn_) return false;

    sf::Vector2f btnPos = this->getPosition();
    sf::Vector2f btnSz = this->getSize();

    return btnPos.x <= event.position.x
        && event.position.x <= btnPos.x + btnSz.x
        && btnPos.y <= event.position.y
        && event.position.y <= btnPos.y + btnSz.y;
}

void ButtonWidget::process_callback(const sf::Event::MouseButtonPressed& event) {
    if (!button_clicked(event)) return;

    callback(event);
}

void ButtonWidget::process_callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout) {
    if (!button_clicked(event)) return;

    callback(event, layout);
}

void ButtonWidget::process_callback(const sf::Event::MouseButtonPressed& event, std::string& current_layout) {
    if (!button_clicked(event)) return;

    callback(event, current_layout);
}

void ButtonWidget::process_callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout, std::string& current_layout) {
    if (!button_clicked(event)) return;

    callback(event, layout, current_layout);
}
