#include <Feurgame-App/Home.hpp>

base_event_handler_ptr HomeLayout::getEventHandler() {
    if (!event_handler_)
        event_handler_ = std::make_shared<HomeEventHandler>(std::shared_ptr<Layout>(this));
    return event_handler_;
}

void HomeEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    auto btn = getWidget<HomePlayButtonWidget>("play_btn");

    btn->process_callback(event, current_layout);

    std::cout << "mouse button (" << (int) event.button << ") pressed : (" << event.position.x << ", " << event.position.y << ")" << std::endl;
}
