#include <Feurgame-App/ChooseMap.hpp>

#include <Feurgame-Lib/Game.hpp>

void ChooseMapButtonWidget::callback(const sf::Event::MouseButtonPressed& event, layout_ptr layout, std::string& current_layout) {
    std::cout << "map chosen. game starting" << std::endl;
    current_layout = "choose_player";

    MapSet map_set("assets/maps/test", 0);
    Map* map = map_set.get_map("3_0");
    
    Game* game = Game::get_instance(map_set.get_metadata(), map);

    MapConfig map_config = map_set.get_map_config("3_0");
    map_config.img = "assets/maps/test/" + map_config.img;
    map_config.config = "assets/maps/test/" + map_config.config;

    game->set_map_config(map_config);
}

base_event_handler_ptr ChooseMapLayout::getEventHandler() {
    return Layout::baseGetEventHandler<ChooseMapEventHandler>(std::make_shared<Layout>(*this));
}

void ChooseMapEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    ChooseMapButtonWidget* btn = this
        ->layout_->getWidget<ListWidget>("maps")
        ->getWidget<ChooseMapButtonWidget>(0);  // temp
    
    btn->process_callback(event, layout_, current_layout);
}
