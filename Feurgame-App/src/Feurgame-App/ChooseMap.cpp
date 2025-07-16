#include <Feurgame-App/ChooseMap.hpp>

#include <Feurgame-Lib/Game.hpp>

base_event_handler_ptr ChooseMapLayout::getEventHandler() {
    return Layout::baseGetEventHandler<ChooseMapEventHandler>(std::make_shared<Layout>(*this));
}

void ChooseMapEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    ChooseMapButtonWidget* btn = this
        ->layout_->getWidget<ListWidget>("maps")
        ->getWidget<ChooseMapButtonWidget>(0);  // temp
    
    if (event.button == sf::Mouse::Button::Left && btn->button_clicked(event.position)) {
        std::cout << "map chosen. game starting" << std::endl;
        current_layout = "choose_player";

        MapSet map_set("assets/maps/test", 0);
        Map* map = map_set.get_map("3_0");
        
        Game* game = Game::get_instance(map_set.get_metadata(), map);
    }
}
