#include "App/ChooseMap.hpp"

BaseEventHandler* ChooseMapLayout::getEventHandler() {
    if (!this->event_handler_)
        this->event_handler_ = new ChooseMapEventHandler(*this);

    return this->event_handler_;
}

void ChooseMapEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    ChooseMapButtonWidget* btn = this
        ->layout_.getWidget<ListWidget>("maps")
        ->getWidget<ChooseMapButtonWidget>(0);  // temp
    
    if (event.button == sf::Mouse::Button::Left && btn->button_clicked(event.position)) {
        std::cout << "map chosen. game starting" << std::endl;
        // change layout to game
    }
}
