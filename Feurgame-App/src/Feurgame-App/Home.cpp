#include <Feurgame-App/Home.hpp>

base_event_handler_ptr HomeLayout::getEventHandler() {
    return Layout::baseGetEventHandler<HomeEventHandler>(std::make_shared<Layout>(*this));
}

void HomeEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    HomePlayButtonWidget* btn = this->getWidget<HomePlayButtonWidget>("play_btn");

    if (event.button == sf::Mouse::Button::Left && btn->button_clicked(event.position)) {
        std::cout << "btn pressed" << std::endl;
        current_layout = "players_form";
    }

    std::cout << "mouse button (" << (int) event.button << ") pressed : (" << event.position.x << ", " << event.position.y << ")" << std::endl;
}
