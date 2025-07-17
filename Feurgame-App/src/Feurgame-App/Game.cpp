#include <Feurgame-App/Game.hpp>

base_event_handler_ptr GameLayout::getEventHandler() {
    if (!event_handler_)
        event_handler_ = std::make_shared<GameEventHandler>(std::make_shared<GameLayout>(*this));
    return event_handler_;
}

map_view_ptr GameLayout::get_map_view() const {
    return map_view_;
}

void GameLayout::update_map_view() const {
    window_->setView(*map_view_);
}

void GameEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    if (event.button == sf::Mouse::Button::Left)
        this->getWidget<ContainerWidget>("bar")->setToDisplay(true);
    else
        this->getWidget<ContainerWidget>("detail")->setToDisplay(true);
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
