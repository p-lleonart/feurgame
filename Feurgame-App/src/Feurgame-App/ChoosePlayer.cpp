#include <Feurgame-App/ChoosePlayer.hpp>

#include <Feurgame-Lib/Game.hpp>

std::vector<std::string> ChoosePlayerLayout::PLAYERS_NAMES = {};

base_event_handler_ptr ChoosePlayerLayout::getEventHandler() {
    if (!event_handler_)
        event_handler_ = std::make_shared<ChoosePlayerEventHandler>(std::shared_ptr<Layout>(this));
    return event_handler_;
}

void ChoosePlayerEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    Game* game = Game::get_instance();
    auto right_list = getWidget<ListWidget>("right");

    int index = (event.position.y - 60) / 50;

    if (WINDOW_X / 2 <= event.position.x
        && event.position.x <= WINDOW_X / 2 + 300
        && 0 <= index
        && index < game->get_map()->get_players().size()
        && !game->get_map()->get_players()[index]->is_bot()) {
    
            if (focused_index_ == -1)  // if there's no focused card yet, focus one
                focused_index_ = index;
            else {                     // otherwise, switch the focused one with the current one

                // switch in the gui
                auto second_focused = right_list->getWidget<PlayerNameTextWidget>(index);
                auto tmp = right_list->getWidget<PlayerNameTextWidget>(focused_index_);
                float tmp_pos_y = tmp->getPosition().y;

                tmp->setPosition({tmp->getPosition().x, second_focused->getPosition().y});
                second_focused->setPosition({second_focused->getPosition().x, tmp_pos_y});

                right_list->setWidget<PlayerNameTextWidget>(focused_index_, second_focused);
                right_list->setWidget<PlayerNameTextWidget>(index, tmp);

                // switch in the game instance
                player_ptr second_plyr = game->get_map()->get_players()[index];
                player_ptr tmp_plyr = game->get_map()->get_players()[focused_index_];
                game->get_map()->set_player(focused_index_, second_plyr);
                game->get_map()->set_player(index, tmp_plyr);
                
                focused_index_ = -1;
            }
    } else {
        focused_index_ = -1;
    }

    if (getWidget<ChoosePlayerSubmitButtonWidget>("save")->button_clicked(event)) {
        for (int i = 0; i < game->get_map()->get_players().size(); i++)
            game->get_map()->get_players()[i]->set_name(
                game->get_map()->get_players()[i]->get_name()
                    + "("
                    + ChoosePlayerLayout::PLAYERS_NAMES[i]
                    + ")"
            );
        
        std::cout << "game starting" << std::endl;
        current_layout = "game";  // game start
    }
}
