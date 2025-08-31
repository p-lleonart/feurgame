#include <Feurgame-App/Game.hpp>

base_event_handler_ptr GameLayout::getEventHandler() {
    if (!event_handler_)
        event_handler_ = std::make_shared<GameEventHandler>(std::make_shared<GameLayout>(*this));
    return event_handler_;
}

view_ptr GameLayout::get_map_view() const {
    return map_view_;
}

void GameLayout::update_map_view() const {
    window_->setView(*map_view_);
}

void GameEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    ListWidget* armies = getWidget<ListWidget>("armies");
    ListWidget* cities = getWidget<ListWidget>("cities");

    // needed to convert screen event's position to a position for the view
    sf::Vector2f map_pos = window_->mapPixelToCoords(event.position);
    sf::Event::MouseButtonPressed event_map;
    event_map.button = event.button;
    event_map.position.x = (int) map_pos.x;
    event_map.position.y = (int) map_pos.y;

    for (int i = 0; i < armies->size(); i++)
        armies->getWidget<ArmyPawnWidget>(i)->process_callback(event_map);

    for (int i = 0; i < cities->size(); i++)
        cities->getWidget<CityPawnWidget>(i)->process_callback(event_map);

    if (event.button == sf::Mouse::Button::Left) {
        this->getWidget<ContainerWidget>("bar")->setToDisplay(true);
        this->getWidget<ContainerWidget>("detail")->setToDisplay(true);
    } else {
        this->getWidget<ContainerWidget>("bar")->setToDisplay(false);
        this->getWidget<ContainerWidget>("detail")->setToDisplay(false);
    }
}

void GameEventHandler::handle(const sf::Event::TextEntered& event) {
    std::cout << (char) event.unicode << std::endl;
    float mov = 10;  // value of the movement vector for zqsd movs

    switch((char) event.unicode) {
        case '+':
            std::cout << "zoom in" << std::endl;
            game_layout_->get_map_view()->zoom(0.75f);
            game_layout_->update_map_view();
            break;
        case '-':
            std::cout << "zoom out" << std::endl;
            game_layout_->get_map_view()->zoom(1.25f);
            game_layout_->update_map_view();
            break;
        case 'z':
            game_layout_->get_map_view()->move({ 0, -mov });
            game_layout_->update_map_view();
            break;
        case 'q':
            game_layout_->get_map_view()->move({ -mov, 0 });
            game_layout_->update_map_view();
            break;
        case 's':
            game_layout_->get_map_view()->move({ 0, mov });
            game_layout_->update_map_view();
            break;
        case 'd':
            game_layout_->get_map_view()->move({ mov, 0});
            game_layout_->update_map_view();
            break;
    }
}
