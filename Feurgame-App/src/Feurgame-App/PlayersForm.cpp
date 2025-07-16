#include <Feurgame-App/PlayersForm.hpp>

#include <Feurgame-App/ChoosePlayer.hpp>

base_event_handler_ptr PlayersFormLayout::getEventHandler() {
    if (!event_handler_)
        event_handler_ = std::make_shared<PlayersFormEventHandler>(std::make_shared<Layout>(*this));
    return event_handler_;
}

void PlayersFormEventHandler::handle(const sf::Event::TextEntered& event) {
    if (this->current_text_widget_ >= this->getWidget<ListWidget>("player_names_inputs")->size()) return;

    if (!std::isprint(event.unicode)) return;

    PlayerNameTextWidget* text_widget = this
        ->getWidget<ListWidget>("player_names_inputs")
        ->getWidget<PlayerNameTextWidget>(this->current_text_widget_);

    std::string text = text_widget->getText();
    text.push_back((char) event.unicode);
    text_widget->setText(text);
}

void PlayersFormEventHandler::handle(const sf::Event::KeyPressed& event) {
    if (this->current_text_widget_ >= this->getWidget<ListWidget>("player_names_inputs")->size()) return;
    
    PlayerNameTextWidget* text_widget = this
        ->getWidget<ListWidget>("player_names_inputs")
        ->getWidget<PlayerNameTextWidget>(this->current_text_widget_);
    
    std::string text = text_widget->getText();

    if (event.code == sf::Keyboard::Key::Enter && !text.empty()) {
        this->current_text_widget_++;
        
        if (this->current_text_widget_ < 4)  // 4 is the max number of players yet
            this->getWidget<ListWidget>("player_names_inputs")->addWidget(
                new PlayerNameTextWidget({0, (float) this->current_text_widget_ * 50})
            );
    }
    else if (event.code == sf::Keyboard::Key::Backspace && !text.empty()) {
        text.pop_back();
        text_widget->setText(text);
    }
}

bool _validate_all_inputs(ListWidget* list) {
    for (int i = 0; i < list->size(); i++) {
        if (list->getWidget<PlayerNameTextWidget>(i)->getText() == "") return false;
    }
    return true;
}

void PlayersFormEventHandler::handle(const sf::Event::MouseButtonPressed& event) {
    PlayerFormSubmitButtonWidget* btn = this->getWidget<PlayerFormSubmitButtonWidget>("submit_btn");

    if (event.button == sf::Mouse::Button::Left
        && btn->button_clicked(event.position)
        && _validate_all_inputs(this->getWidget<ListWidget>("player_names_inputs"))
    ) {
        std::cout << "choose map layout" << std::endl;
        current_layout = "choose_map";
        for (int i = 0; i < current_text_widget_; i++)
            ChoosePlayerLayout::PLAYERS_NAMES.push_back(
                this->getWidget<ListWidget>("player_names_inputs")
                    ->getWidget<TextWidget>(i)
                    ->getText()
            );
    }
}
