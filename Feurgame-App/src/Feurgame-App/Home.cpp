#include <Feurgame-App/Home.hpp>

base_event_handler_ptr HomeLayout::getEventHandler() {
    return Layout::baseGetEventHandler<HomeEventHandler>(std::make_shared<Layout>(*this));
}

void HomeEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    HomePlayButtonWidget* btn = this->getWidget<HomePlayButtonWidget>("play_btn");

    btn->process_callback(event, current_layout);

    std::cout << "mouse button (" << (int) event.button << ") pressed : (" << event.position.x << ", " << event.position.y << ")" << std::endl;
}
