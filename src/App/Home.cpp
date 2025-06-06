#include "App/Home.hpp"

#include "App/Widgets/Logo.hpp"
#include "App/Widgets/Buttons.hpp"

HomeLayout::HomeLayout(sf::RenderWindow* window) {
    this->widgets_["logo"] = new LogoWidget();
    this->widgets_["play_btn"] = new HomePlayButtonWidget();
    this->window_ = window;
}

BaseEventHandler* HomeLayout::getEventHandler() {
    if (!this->event_handler_)
        this->event_handler_ = new HomeEventHandler(*this);

    return this->event_handler_;
}

void HomeEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    HomePlayButtonWidget* btn = this->layout_.getWidget<HomePlayButtonWidget>("play_btn");

    if (event.button == sf::Mouse::Button::Left && btn->button_clicked(event.position)) {
        std::cout << "btn pressed" << std::endl;
        current_layout = "players_form";
    }

    std::cout << "mouse button (" << (int) event.button << ") pressed : (" << event.position.x << ", " << event.position.y << ")" << std::endl;
}
